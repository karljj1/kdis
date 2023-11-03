#ifndef KDIS_NETWORK_ADDRESSFAMILY_HPP_
#define KDIS_NETWORK_ADDRESSFAMILY_HPP_

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  #include <ws2tcpip.h>
#else
  #include <sys/socket.h>
#endif

#include <cstdint>

namespace KDIS {
namespace NETWORK {

/**
 * @brief Address family.
 */
enum class AddressFamily : std::uint8_t {
  /**
   * @brief Unknown.
   */
  UNKNOWN = AF_UNSPEC,
  /**
   * @brief IPv4.
   */
  IPv4 = AF_INET,
  /**
   * @brief IPv6.
   */
  IPv6 = AF_INET6
};

}  // namespace NETWORK
}  // namespace KDIS

#endif  // KDIS_NETWORK_ADDRESSFAMILY_HPP_
