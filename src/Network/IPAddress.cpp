#include "KDIS/Network/IPAddress.hpp"

#include <cstring>

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  #include <winsock2.h>
  #include <ws2tcpip.h>

  #pragma comment(lib, "Ws2_32.lib")
#else
  #include <arpa/inet.h>
#endif

#include "KDIS/util/Endian.hpp"
#include "KDIS/util/unreachable.hpp"

namespace KDIS {
namespace NETWORK {

IPAddress::IPAddress(const std::string& address, const std::uint32_t scope) {
  try {
    initIPv4(address);
  } catch (...) {
    try {
      initIPv6(address, scope);
    } catch (...) {
      throw KException(
          ErrorCode::INVALID_DATA,
          KDIS::UTIL::format("Invalid IP address %s", address.c_str()));
    }
  }
}

IPAddress::IPAddress(const sockaddr& address) {
  const auto family = address.sa_family;
  switch (family) {
    case AF_INET: {
      const auto& sin = reinterpret_cast<const sockaddr_in&>(address);
      initIPv4(sin.sin_addr);
      break;
    }
    case AF_INET6: {
      const auto& sin6 = reinterpret_cast<const sockaddr_in6&>(address);
      initIPv6(sin6.sin6_addr, sin6.sin6_scope_id);
      break;
    }
    default:
      throw KException(
          ErrorCode::INVALID_OPERATION,
          KDIS::UTIL::format("Invalid or unsupported address family %hu",
                             family));
  }
}

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
IPAddress::IPAddress(const SOCKET_ADDRESS& address) {
  const auto family = address.lpSockaddr->sa_family;
  switch (family) {
    case AF_INET: {
      const auto& sin =
          reinterpret_cast<const sockaddr_in&>(*address.lpSockaddr);
      initIPv4(sin.sin_addr);
      break;
    }
    case AF_INET6: {
      const auto& sin6 =
          reinterpret_cast<const sockaddr_in6&>(*address.lpSockaddr);
      initIPv6(sin6.sin6_addr, sin6.sin6_scope_id);
      break;
    }
    default:
      throw KException(
          ErrorCode::INVALID_OPERATION,
          KDIS::UTIL::format("Invalid or unsupported address family %hu",
                             family));
  }
}
#endif

IPAddress::IPAddress(const std::string& address, const AddressFamily family,
                     const std::uint32_t scope) {
  switch (family) {
    case AddressFamily::IPv4: {
      initIPv4(address);
      break;
    }
    case AddressFamily::IPv6: {
      initIPv6(address, scope);
      break;
    }
    default:
      throw KException(
          ErrorCode::INVALID_OPERATION,
          KDIS::UTIL::format(
              "Invalid or unsupported address family %d",
              static_cast<std::underlying_type<AddressFamily>::type>(family)));
  }
}

IPAddress::IPAddress(const IPAddress& address) {
  std::memcpy(&this->address, &address.address, sizeof(this->address));
}

AddressFamily IPAddress::family() const {
  switch (address.ss_family) {
    case AF_INET:
      return AddressFamily::IPv4;
    case AF_INET6:
      return AddressFamily::IPv6;
    default:
      KDIS::UTIL::unreachable();
  }
}

std::uint32_t IPAddress::scope() const {
  switch (family()) {
    case AddressFamily::IPv4: {
      return 0;
    }
    case AddressFamily::IPv6: {
      const auto& sin6 = reinterpret_cast<const sockaddr_in6&>(this->address);
      return sin6.sin6_scope_id;
    }
    default:
      KDIS::UTIL::unreachable();
  }
}

bool IPAddress::isIPv4() const { return family() == AddressFamily::IPv4; }

bool IPAddress::isIPv6() const { return family() == AddressFamily::IPv6; }

bool IPAddress::isMulticast() const {
  switch (family()) {
    case AddressFamily::IPv4: {
      const auto& sin = reinterpret_cast<const sockaddr_in&>(this->address);
      return (ntohl(sin.sin_addr.s_addr) & 0xF0000000) == 0xE0000000;
    }
    case AddressFamily::IPv6: {
      const auto& sin6 = reinterpret_cast<const sockaddr_in6&>(this->address);
      auto word = reinterpret_cast<const std::uint16_t*>(&sin6.sin6_addr)[0];
      if (KDIS::UTIL::Endian::isLittleEndian()) {
        // Flip word
        word = ((word >> 8) & 0x00FF) | ((word << 8) & 0xFF00);
      }
      return (word & 0xFFE0) == 0xFF00;
    }
    default:
      KDIS::UTIL::unreachable();
  }
}

std::string IPAddress::toString() const {
  switch (family()) {
    case AddressFamily::IPv4: {
      const auto& sin = reinterpret_cast<const sockaddr_in&>(address);
      char buffer[INET_ADDRSTRLEN];
      inet_ntop(AF_INET, &sin.sin_addr, buffer, INET_ADDRSTRLEN);
      const auto addressString = std::string(buffer);
      return addressString;
    }
    case AddressFamily::IPv6: {
      const auto& sin6 = reinterpret_cast<const sockaddr_in6&>(address);
      char buffer[INET6_ADDRSTRLEN];
      inet_ntop(AF_INET6, &sin6.sin6_addr, buffer, INET6_ADDRSTRLEN);
      auto addressString = std::string(buffer);
      if (scope() > 0) {
        addressString.append("%").append(std::to_string(scope()));
      }
      return addressString;
    }
    default:
      KDIS::UTIL::unreachable();
  }
}

bool IPAddress::operator==(const IPAddress& address) const {
  const auto f = family();
  if (f != address.family()) {
    return false;
  }

  return scope() == address.scope() &&
         std::memcmp(&this->address, &address.address, sizeof(this->address)) ==
             0;
}

bool IPAddress::operator!=(const IPAddress& address) const {
  return !(*this == address);
}

std::ostream& operator<<(std::ostream& os, const IPAddress& address) {
  os << address.toString();
  return os;
}

void IPAddress::initIPv4(const std::string& address) {
  std::memset(&this->address, 0, sizeof(this->address));
  auto& sin = reinterpret_cast<sockaddr_in&>(this->address);
  sin.sin_family = AF_INET;
  if (!inet_pton(AF_INET, address.c_str(), &sin.sin_addr)) {
    throw KException(
        ErrorCode::INVALID_DATA,
        KDIS::UTIL::format("Invalid IPv4 address %s", address.c_str()));
  }
}

void IPAddress::initIPv4(const in_addr& address) {
  std::memset(&this->address, 0, sizeof(this->address));
  auto& sin = reinterpret_cast<sockaddr_in&>(this->address);
  sin.sin_family = AF_INET;
  std::memcpy(&sin.sin_addr, &address, sizeof(sin.sin_addr));
}

void IPAddress::initIPv6(const std::string& address,
                         const std::uint32_t scope) {
  std::memset(&this->address, 0, sizeof(this->address));
  auto& sin6 = reinterpret_cast<sockaddr_in6&>(this->address);
  sin6.sin6_family = AF_INET6;
  sin6.sin6_scope_id = scope;
  if (!inet_pton(AF_INET6, address.c_str(), &sin6.sin6_addr)) {
    throw KException(
        ErrorCode::INVALID_DATA,
        KDIS::UTIL::format("Invalid IPv6 address %s", address.c_str()));
  }
}

void IPAddress::initIPv6(const in6_addr& address, const std::uint32_t scope) {
  std::memset(&this->address, 0, sizeof(this->address));
  auto& sin6 = reinterpret_cast<sockaddr_in6&>(this->address);
  sin6.sin6_family = AF_INET6;
  sin6.sin6_scope_id = scope;
  std::memcpy(&sin6.sin6_addr, &address, sizeof(sin6.sin6_addr));
}

}  // namespace NETWORK
}  // namespace KDIS
