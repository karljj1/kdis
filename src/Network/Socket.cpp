#include <sstream>
#include <stdexcept>

#include "KDIS/Network/Socket.hpp"

using namespace KDIS;
using namespace NETWORK;

int Socket::socket(int domain, int type, int protocol) const {
  return ::socket(domain, type, protocol);
}

int Socket::setsockopt(int sockfd, int level, int optname, const void* optval,
                       socklen_t optlen) const {
  return ::setsockopt(sockfd, level, optname, optval, optlen);
}

#if defined(WIN32) | defined(_WIN32) | defined(WIN64) | defined(_WIN64)
int Socket::ioctlsocket(SOCKET s, long cmd, u_long* argp) const {
  return ::ioctlsocket(s, cmd, argp);
}
#else
int Socket::fcntl_setfl(int fd, int flags) const {
  return ::fcntl(fd, F_SETFL, flags);
}
#endif

int Socket::getsockname(int sockfd, struct sockaddr* addr,
                        socklen_t* addrlen) const {
  return ::getsockname(sockfd, addr, addrlen);
}

int Socket::bind(int sockfd, const struct sockaddr* addr,
                 socklen_t addrlen) const {
  return ::bind(sockfd, addr, addrlen);
}

int Socket::connect(int sockfd, const struct sockaddr* addr,
                    socklen_t addrlen) const {
  return ::connect(sockfd, addr, addrlen);
}

int Socket::select(int nfds, fd_set* readfds, fd_set* writefds,
                   fd_set* exceptfds, struct timeval* timeout) const {
  return ::select(nfds, readfds, writefds, exceptfds, timeout);
}

ssize_t Socket::recvfrom(int sockfd, void* buf, size_t len, int flags,
                         struct sockaddr* src_addr, socklen_t* addrlen) const {
  return ::recvfrom(sockfd, buf, len, flags, src_addr, addrlen);
}

ssize_t Socket::sendto(int sockfd, const void* buf, size_t len, int flags,
                       const struct sockaddr* dest_addr,
                       socklen_t addrlen) const {
  return ::sendto(sockfd, buf, len, flags, dest_addr, addrlen);
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

const char* Socket::inet_ntop(int af, const void* src, char* dst,
                              socklen_t size) const {
  return ::inet_ntop(af, src, dst, size);
}

in_addr_t Socket::inet_addr(const char* cp) const { return ::inet_addr(cp); }