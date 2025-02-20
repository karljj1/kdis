#pragma once

#include <sys/select.h>
#include <sys/socket.h>

#if defined(WIN32) | defined(_WIN32) | defined(WIN64) | defined(_WIN64)
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <fcntl.h>
#endif

#include <string>

namespace KDIS {
namespace NETWORK {

// Interface class designed to allow dependency injection of socket features.
class ISocket {
 public:
  virtual ~ISocket() = default;

  virtual int socket(int domain, int type, int protocol) const = 0;

  virtual int setsockopt(int sockfd, int level, int optname, const void* optval,
                         socklen_t optlen) const = 0;

#if defined(WIN32) | defined(_WIN32) | defined(WIN64) | defined(_WIN64)
  virtual int ioctlsocket(SOCKET s, long cmd, u_long* argp) const = 0;
#else
  virtual int fcntl_setfl(int fd, int flags) const = 0;
#endif

  virtual int getsockname(int sockfd, struct sockaddr* addr,
                          socklen_t* addrlen) const = 0;

  virtual int bind(int sockfd, const struct sockaddr* addr,
                   socklen_t addrlen) const = 0;

  virtual int connect(int sockfd, const struct sockaddr* addr,
                      socklen_t addrlen) const = 0;

  virtual int select(int nfds, fd_set* readfds, fd_set* writefds,
                     fd_set* exceptfds, struct timeval* timeout) const = 0;

  virtual ssize_t recvfrom(int sockfd, void* buf, size_t len, int flags,
                           struct sockaddr* src_addr,
                           socklen_t* addrlen) const = 0;

  virtual ssize_t sendto(int sockfd, const void* buf, size_t len, int flags,
                         const struct sockaddr* dest_addr,
                         socklen_t addrlen) const = 0;

  virtual std::string inetToString(const struct in_addr& addr) const = 0;

  virtual const char* inet_ntop(int af, const void* src, char* dst,
                                socklen_t size) const = 0;

  virtual in_addr_t inet_addr(const char* cp) const = 0;
};

}  // END namespace NETWORK
}  // END namespace KDIS
