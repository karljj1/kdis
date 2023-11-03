// Inspired by
// https://github.com/pocoproject/poco/blob/devel/Net/include/Poco/Net/IPAddress.h

#ifndef KDIS_NETWORK_IPADDRESS_HPP_
#define KDIS_NETWORK_IPADDRESS_HPP_

#include <ostream>
#include <string>

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
#else
  #include <netinet/in.h>
#endif

#include "KDIS/KDefines.hpp"
#include "KDIS/Network/AddressFamily.hpp"

namespace KDIS {
namespace NETWORK {

class KDIS_EXPORT IPAddress {
 public:
  IPAddress() = delete;

  IPAddress(const std::string &address, const std::uint32_t scope = 0);

  explicit IPAddress(const sockaddr &address);

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  explicit IPAddress(const SOCKET_ADDRESS &address);
#endif

  IPAddress(const std::string &address, const AddressFamily family,
            const std::uint32_t scope = 0);

  IPAddress(const IPAddress &address);

  AddressFamily family() const;

  std::uint32_t scope() const;

  bool isIPv4() const;

  bool isIPv6() const;

  bool isMulticast() const;

  std::string toString() const;

  bool operator==(const IPAddress &address) const;

  bool operator!=(const IPAddress &address) const;

  friend std::ostream &operator<<(std::ostream &os, const IPAddress &address);

 private:
  struct sockaddr_storage address;

  void initIPv4(const std::string &address);

  void initIPv4(const in_addr &address);

  void initIPv6(const std::string &address, const std::uint32_t scope = 0);

  void initIPv6(const in6_addr &address, const std::uint32_t scope = 0);
};

}  // namespace NETWORK
}  // namespace KDIS

#endif  // KDIS_NETWORK_IPADDRESS_HPP_
