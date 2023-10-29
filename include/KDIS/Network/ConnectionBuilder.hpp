#ifndef KDIS_NETWORK_CONNECTIONBUILDER_HPP_
#define KDIS_NETWORK_CONNECTIONBUILDER_HPP_

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  #include <winsock2.h>

  #pragma comment(lib, "Ws2_32.lib")
#else
  #include <netinet/in.h>
  #include <sys/socket.h>
#endif

#include "KDIS/KConfig.hpp"

namespace KDIS {
namespace NETWORK {

class ConnectionBuilder {
 public:
  ConnectionBuilder();

  /**
   * @brief Set receive.
   *
   * @param address Address.
   * @param port Port.
   * @return Builder.
   */
  ConnectionBuilder &setRecv(
      const char *address,
      const in_port_t port = KDIS_CONNECTION_DEFAULT_RECV_PORT);

  /**
   * @brief Set receive interface.
   *
   * @param iface Name or address.
   * @return Builder.
   */
  ConnectionBuilder &setRecvInterface(const char *iface);

  /**
   * @brief Set send.
   *
   * @param address Address.
   * @param port Port.
   * @return Builder.
   */
  ConnectionBuilder &setSend(
      const char *address,
      const in_port_t port = KDIS_CONNECTION_DEFAULT_SEND_PORT);

  /**
   * @brief Set send interface.
   *
   * @param iface Name or address.
   * @return Builder.
   */
  ConnectionBuilder &setSendInterface(const char *iface);

 private:
  /**
   * @brief Receive.
   */
  sockaddr_storage recv;

  /**
   * @brief Send.
   */
  sockaddr_storage send;

  /**
   * @brief Returns the address family of the address.
   *
   * @param address Address.
   * @return Address family.
   */
  static sa_family_t address_family(const char *address);

  /**
   * @brief Set ss to the appropriate address family's address and port.
   *
   * @param ss Socket address storage.
   * @param address Address.
   * @param port Port.
   *
   * @throws KException if address is invalid.
   */
  static void set_sockaddr_storage(sockaddr_storage &ss, const char *address,
                                   const in_port_t port);
};

}  // namespace NETWORK
}  // namespace KDIS

#endif  // KDIS_NETWORK_CONNECTIONBUILDER_HPP_
