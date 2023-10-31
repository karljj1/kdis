#include "KDIS/Network/ConnectionBuilder.hpp"

#include <cstring>

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  #include <ws2tcpip.h>
#else
  #include <arpa/inet.h>
#endif

#include "KDIS/KDefines.hpp"
#include "KDIS/util/format.hpp"

namespace KDIS {
namespace NETWORK {

ConnectionBuilder::ConnectionBuilder() {
  // Receive
  recv.ss_family = AF_UNSPEC;
  ConnectionBuilder::set_sockaddr_storage(recv,
                                          KDIS_CONNECTION_DEFAULT_RECV_ADDRESS,
                                          KDIS_CONNECTION_DEFAULT_RECV_PORT);

  // Send
  send.ss_family = AF_UNSPEC;
  ConnectionBuilder::set_sockaddr_storage(send,
                                          KDIS_CONNECTION_DEFAULT_SEND_ADDRESS,
                                          KDIS_CONNECTION_DEFAULT_SEND_PORT);
}

ConnectionBuilder &ConnectionBuilder::setRecv(const char *address,
                                              const in_port_t port) {
  ConnectionBuilder::set_sockaddr_storage(recv, address, port);
  return *this;
}

ConnectionBuilder &ConnectionBuilder::setRecvInterface(const char *iface) {
  // TODO(carlocorradini)
  return *this;
}

ConnectionBuilder &ConnectionBuilder::setSend(const char *address,
                                              const in_port_t port) {
  ConnectionBuilder::set_sockaddr_storage(send, address, port);
  return *this;
}

ConnectionBuilder &ConnectionBuilder::setSendInterface(const char *iface) {
  // TODO(carlocorradini)
  return *this;
}

sa_family_t ConnectionBuilder::address_family(const char *address) {
  std::uint8_t buffer[16];
  if (inet_pton(AF_INET, address, buffer)) {
    return AF_INET;
  } else if (inet_pton(AF_INET6, address, buffer)) {
    return AF_INET;
  }
  return AF_UNSPEC;
}

void ConnectionBuilder::set_sockaddr_storage(sockaddr_storage &ss,
                                             const char *address,
                                             const in_port_t port) {
  std::memset(&ss, 0, sizeof(sockaddr_storage));

  switch (ConnectionBuilder::address_family(address)) {
    case AF_INET: {
      auto &sin = reinterpret_cast<sockaddr_in &>(ss);
      sin.sin_family = AF_INET;
      inet_pton(AF_INET, address, &sin.sin_addr);
      sin.sin_port = htons(port);
      break;
    }
    case AF_INET6: {
      auto &sin6 = reinterpret_cast<sockaddr_in6 &>(ss);
      sin6.sin6_family = AF_INET6;
      inet_pton(AF_INET6, address, &sin6.sin6_addr);
      sin6.sin6_port = htons(port);
      break;
    }
    default:
      throw KException(ErrorCode::CONNECTION_SOCKET_ERROR,
                       KDIS::UTIL::format("Invalid address %s", address));
  }
}

}  // namespace NETWORK
}  // namespace KDIS
