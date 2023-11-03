#include "KDIS/Network/NetInterface.hpp"

#include <algorithm>

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  #include <iphlpapi.h>

  #pragma comment(lib, "IPHLPAPI.lib")
#else
  #include <ifaddrs.h>
  #include <net/if.h>
#endif

#include "KDIS/util/Error.hpp"
#include "KDIS/util/unreachable.hpp"

namespace KDIS {
namespace NETWORK {

NetInterface::NetInterface(const std::size_t index, const std::string name,
                           const std::vector<IPAddress> &addresses,
                           const bool up, const bool running,
                           const bool multicast, const bool loopback)
    : _index(index),
      _name(name),
      _addresses(addresses),
      up(up),
      running(running),
      multicast(multicast),
      loopback(loopback) {}

std::size_t NetInterface::index() const { return _index; }

const std::string &NetInterface::name() const { return _name; }

const std::vector<IPAddress> &NetInterface::addresses() const {
  return _addresses;
}

const IPAddress &NetInterface::firstAddress(const AddressFamily family) const {
  for (const auto &address : _addresses) {
    if (family == AddressFamily::UNKNOWN || address.family() == family) {
      return address;
    }
  }

  throw KException(
      ErrorCode::NOT_FOUND,
      KDIS::UTIL::format(
          "Address family %d not found",
          static_cast<std::underlying_type<AddressFamily>::type>(family)));
}

const IPAddress &NetInterface::address(const std::size_t index) const {
  if (index < _addresses.size()) return _addresses.at(index);
  throw KException(ErrorCode::NOT_FOUND,
                   KDIS::UTIL::format("Address index %zu not found", index));
}

bool NetInterface::supportsIPv4() const {
  for (const auto &address : _addresses) {
    if (address.isIPv4()) {
      return true;
    }
  }
  return false;
}

bool NetInterface::supportsIPv6() const {
  for (const auto &address : _addresses) {
    if (address.isIPv6()) {
      return true;
    }
  }
  return false;
}

bool NetInterface::supportsMulticast() const { return multicast; }

bool NetInterface::isUp() const { return up; }

bool NetInterface::isRunning() const { return running; }

bool NetInterface::isLoopback() const { return loopback; }

NetInterface NetInterface::forName(const std::string &name,
                                   const AddressFamily family) {
  for (const auto &it : NetInterface::map(false)) {
    if (name != it.second.name()) {
      continue;
    }

    switch (family) {
      case AddressFamily::UNKNOWN: {
        if (it.second.supportsIPv4() && it.second.supportsIPv6()) {
          return it.second;
        }
        break;
      }
      case AddressFamily::IPv4: {
        if (it.second.supportsIPv4()) {
          return it.second;
        }
        break;
      }
      case AddressFamily::IPv6: {
        if (it.second.supportsIPv6()) {
          return it.second;
        }
        break;
      }
      default:
        KDIS::UTIL::unreachable();
    }
  }

  throw KException(
      ErrorCode::NOT_FOUND,
      KDIS::UTIL::format("Interface name %s not found", name.c_str()));
}

NetInterface NetInterface::forAddress(const IPAddress &address) {
  for (const auto &it : NetInterface::map(false)) {
    if (std::find(it.second.addresses().begin(), it.second.addresses().end(),
                  address) != it.second.addresses().end()) {
      return it.second;
    }
  }

  throw KException(ErrorCode::NOT_FOUND,
                   KDIS::UTIL::format("Interface address %s not found",
                                      address.toString().c_str()));
}

NetInterface NetInterface::forIndex(const std::size_t index) {
  const auto map = NetInterface::map(false);
  const auto it = map.find(index);
  if (it != map.end()) {
    return it->second;
  }

  throw KException(ErrorCode::NOT_FOUND,
                   KDIS::UTIL::format("Interface index %zu not found", index));
}

std::vector<NetInterface> NetInterface::list(const bool upOnly) {
  std::vector<NetInterface> list;
  const auto map = NetInterface::map(upOnly);
  std::transform(
      map.begin(), map.end(), std::back_inserter(list),
      [](std::pair<const std::size_t, const NetInterface> const &it) {
        return it.second;
      });

  return list;
}

bool NetInterface::operator==(const NetInterface &netInterface) const {
  return this->index() == netInterface.index();
}

bool NetInterface::operator!=(const NetInterface &netInterface) const {
  return !(*this == netInterface);
}

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)

std::map<std::size_t, NetInterface> NetInterface::map(const bool upOnly) {
  OSVERSIONINFO osvi;
  ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
  osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
  GetVersionEx(&osvi);

  std::map<std::size_t, NetInterface> map;
  DWORD status = 0;
  ULONG iterations = 0;
  ULONG bufferLength = 16384;
  PIP_ADAPTER_ADDRESSES netInterfaces = nullptr;

  // Read interfaces
  do {
    netInterfaces = static_cast<PIP_ADAPTER_ADDRESSES>(
        HeapAlloc(GetProcessHeap(), 0, bufferLength));
    if (netInterfaces == nullptr) {
      throw KException(
          ErrorCode::SYSTEM,
          KDIS::UTIL::format("Error reading network interfaces: %s",
                             KDIS::UTIL::Error::toString().c_str()));
    }

    status = GetAdaptersAddresses(
        AF_UNSPEC,
        GAA_FLAG_SKIP_ANYCAST | GAA_FLAG_SKIP_MULTICAST |
            GAA_FLAG_SKIP_DNS_SERVER | GAA_FLAG_INCLUDE_PREFIX |
            GAA_FLAG_INCLUDE_ALL_INTERFACES,
        0, netInterfaces, &bufferLength);

    // Check
    switch (status) {
      case ERROR_BUFFER_OVERFLOW: {
        // Retry
        HeapFree(GetProcessHeap(), 0, netInterfaces);
        netInterfaces = nullptr;
        break;
      }
      case ERROR_NO_DATA: {
        // Not found
        HeapFree(GetProcessHeap(), 0, netInterfaces);
        return map;
      }
      case NO_ERROR: {
        // Found
        break;
      }
      default: {
        HeapFree(GetProcessHeap(), 0, netInterfaces);
        throw KException(
            ErrorCode::SYSTEM,
            KDIS::UTIL::format("Error reading network interfaces: %s",
                               KDIS::UTIL::Error::toString().c_str()));
      }
    }
  } while ((status == ERROR_BUFFER_OVERFLOW) && (++iterations <= 2));

  // Iterate
  for (PIP_ADAPTER_ADDRESSES netInterface = netInterfaces;
       netInterface != nullptr; netInterface = netInterface->Next) {
    std::size_t index = 0;

  #if defined(_WIN32_WCE)
    index = netInterface->Ipv6IfIndex;
  #elif (_WIN32_WINNT >= 0x0501) && (NTDDI_VERSION >= 0x05010100)  // Win XP SP1
    #if defined(IP_ADAPTER_IPV6_ENABLED)                           // Vista
    if (osvi.dwMajorVersion >= 6) {
      // Vista
      if ((netInterface->Flags & IP_ADAPTER_IPV6_ENABLED) &&
          (osvi.dwMajorVersion >= 5) && (osvi.dwMinorVersion >= 1) &&
          (osvi.dwBuildNumber >= 1)) {
        index = netInterface->Ipv6IfIndex;
      }
    } else {
      if ((osvi.dwMajorVersion >= 5) && (osvi.dwMinorVersion >= 1) &&
          (osvi.dwBuildNumber >= 1)) {
        index = netInterface->Ipv6IfIndex;
      }
    }
    #else
    if ((osvi.dwMajorVersion >= 5) && (osvi.dwMinorVersion >= 1) &&
        (osvi.dwBuildNumber >= 1)) {
      index = netInterface->Ipv6IfIndex;
    }
    #endif
  #endif

  #if defined(IP_ADAPTER_IPV4_ENABLED)
    if (osvi.dwMajorVersion >= 6) {
      // Vista
      if (netInterface->Flags & IP_ADAPTER_IPV4_ENABLED) {
        index = netInterface->IfIndex;
      }
    } else {
      index = netInterface->IfIndex;
    }
  #else
    index = netInterface->IfIndex;
  #endif

    if (index == 0) {
      continue;
    }

    const bool ip = (netInterface->FirstUnicastAddress != 0);
    const bool up = (netInterface->OperStatus == IfOperStatusUp);

    if (!ip || (upOnly && !up)) {
      continue;
    }

    std::wstring nameWs(netInterface->FriendlyName);
    const std::string name(nameWs.begin(), nameWs.end());

    bool running = false;
  #if (_WIN32_WINNT >= 0x0600)  // Vista and newer
    if ((osvi.dwMajorVersion >= 6) && (osvi.dwMinorVersion >= 0) &&
        (osvi.dwBuildNumber >= 0)) {
      running = netInterface->ReceiveLinkSpeed > 0 ||
                netInterface->TransmitLinkSpeed > 0;
    }
  #endif

    bool multicast = false;
    bool loopback = false;
    switch (netInterface->Flags) {
      case IF_TYPE_ETHERNET_CSMACD:
      case IF_TYPE_ISO88025_TOKENRING:
      case IF_TYPE_IEEE80211: {
        multicast = true;
        break;
      }
      case IF_TYPE_SOFTWARE_LOOPBACK: {
        loopback = true;
        break;
      }
    }
    if (!(netInterface->Flags & IP_ADAPTER_NO_MULTICAST)) {
      multicast = true;
    }

    std::vector<IPAddress> addresses;
    for (PIP_ADAPTER_UNICAST_ADDRESS pAddress =
             netInterface->FirstUnicastAddress;
         pAddress != nullptr; pAddress = pAddress->Next) {
      switch (pAddress->Address.lpSockaddr->sa_family) {
        case AF_INET:
        case AF_INET6: {
          addresses.emplace_back(pAddress->Address);
          break;
        }
        default: {
          // Ignore
          break;
        }
      }
    }

    // Add
    map.emplace(
        index, NetInterface(index, name,
                            const_cast<const std::vector<IPAddress>>(addresses),
                            up, running, multicast, loopback));
  }

  if (netInterfaces != nullptr) {
    HeapFree(GetProcessHeap(), 0, netInterfaces);
  }

  return map;
}

#else

std::map<std::size_t, NetInterface> NetInterface::map(const bool upOnly) {
  std::map<std::size_t, NetInterface> map;
  ifaddrs *netInterfaces = nullptr;

  // Read interfaces
  if (getifaddrs(&netInterfaces) < 0) {
    throw KException(ErrorCode::SYSTEM,
                     KDIS::UTIL::format("Error reading network interfaces: %s",
                                        KDIS::UTIL::Error::toString().c_str()));
  }

  // Iterate
  for (ifaddrs *netInterface = netInterfaces; netInterface != nullptr;
       netInterface = netInterface->ifa_next) {
    if (netInterface->ifa_addr == nullptr) continue;

    switch (netInterface->ifa_addr->sa_family) {
      case AF_INET:
      case AF_INET6: {
        const std::size_t index = if_nametoindex(netInterface->ifa_name);
        const std::string name(netInterface->ifa_name);
        const IPAddress address(*(netInterface->ifa_addr));
        const bool up = (netInterface->ifa_flags & IFF_UP) != 0;
        const bool running = (netInterface->ifa_flags & IFF_RUNNING) != 0;
        const bool multicast = (netInterface->ifa_flags & IFF_MULTICAST) != 0;
        const bool loopback = (netInterface->ifa_flags & IFF_LOOPBACK) != 0;

        if (upOnly && !up) {
          continue;
        }

        std::vector<IPAddress> addresses = {address};

        const auto it = map.find(index);
        if (it == map.end()) {
          // First insertion
          map.emplace(index, NetInterface(index, name, addresses, up, running,
                                          multicast, loopback));
        } else {
          // Non first insertion, maintain order
          addresses.insert(addresses.end(), it->second.addresses().rbegin(),
                           it->second.addresses().rend());
          std::reverse(addresses.begin(), addresses.end());
          it->second = NetInterface(index, name, addresses, up, running,
                                    multicast, loopback);
        }

        break;
      }
      default:
        // Ignore
        break;
    }
  }

  if (netInterfaces != nullptr) {
    freeifaddrs(netInterfaces);
  }

  return map;
}

#endif

}  // namespace NETWORK
}  // namespace KDIS
