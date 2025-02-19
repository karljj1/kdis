#include <sstream>
#include <stdexcept>

#include "KDIS/Network/Socket.hpp"

using namespace KDIS;
using namespace NETWORK;

int Socket::Select(int nfds, fd_set* readfds, fd_set* writefds,
                   fd_set* exceptfds, struct timeval* timeout) const {
  return ::select(nfds, readfds, writefds, exceptfds, timeout);
}

ssize_t Socket::RecvFrom(int sockfd, void* buf, size_t len, int flags,
                         struct sockaddr* src_addr, socklen_t* addrlen) const {
  return ::recvfrom(sockfd, buf, len, flags, src_addr, addrlen);
}

std::string Socket::inetToString(const struct in_addr& addr) const {
  auto bytes = reinterpret_cast<const unsigned char*>(&addr.s_addr);

  std::stringstream ss;
  ss << static_cast<unsigned int>(bytes[0]) << "."
     << static_cast<unsigned int>(bytes[1]) << "."
     << static_cast<unsigned int>(bytes[2]) << "."
     << static_cast<unsigned int>(bytes[3]);

  if (ss.fail()) {
    throw std::runtime_error("Failed to format IP address in stringstream");
  }

  return ss.str();
}

ssize_t Socket::SendTo(int sockfd, void* buf, size_t len, int flags,
                       const struct sockaddr* dest_addr,
                       socklen_t addrlen) const {
  return ::sendto(sockfd, buf, len, flags, dest_addr, addrlen);
}