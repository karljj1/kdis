// Inspired by
// https://github.com/pocoproject/poco/blob/devel/Net/include/Poco/Net/NetworkInterface.h

#ifndef KDIS_NETWORK_NETINTERFACE_HPP_
#define KDIS_NETWORK_NETINTERFACE_HPP_

#include <map>
#include <string>
#include <vector>

#include "KDIS/KDefines.hpp"
#include "KDIS/Network/IPAddress.hpp"

namespace KDIS {
namespace NETWORK {

class KDIS_EXPORT NetInterface {
 public:
  NetInterface() = delete;

  std::size_t index() const;

  const std::string& name() const;

  const std::vector<IPAddress>& addresses() const;

  const IPAddress& firstAddress(
      const AddressFamily family = AddressFamily::UNKNOWN) const;

  const IPAddress& address(const std::size_t index = 0) const;

  bool supportsIPv4() const;

  bool supportsIPv6() const;

  bool supportsMulticast() const;

  bool isUp() const;

  bool isRunning() const;

  bool isLoopback() const;

  static NetInterface forName(
      const std::string& name,
      const AddressFamily family = AddressFamily::UNKNOWN);

  static NetInterface forAddress(const IPAddress& address);

  static NetInterface forIndex(const std::size_t index);

  static std::vector<NetInterface> list(const bool upOnly = true);

  static std::map<std::size_t, NetInterface> map(const bool upOnly = true);

  bool operator==(const NetInterface& netInterface) const;

  bool operator!=(const NetInterface& netInterface) const;

 private:
  std::size_t _index;

  std::string _name;

  std::vector<IPAddress> _addresses;

  bool up;

  bool running;

  bool multicast;

  bool loopback;

  NetInterface(const std::size_t index, const std::string name,
               const std::vector<IPAddress>& addresses, const bool up,
               const bool running, const bool multicast, const bool loopback);
};

}  // namespace NETWORK
}  // namespace KDIS

#endif  // KDIS_NETWORK_NETINTERFACE_HPP_
