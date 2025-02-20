#pragma once

#include "KDIS/Network/ISocket.hpp"

namespace KDIS {
namespace NETWORK {

class Socket : public ISocket {
 public:
  int socket(int domain, int type, int protocol) const override;

  int setsockopt(int sockfd, int level, int optname, const void* optval,
                 socklen_t optlen) const override;

#if defined(WIN32) | defined(_WIN32) | defined(WIN64) | defined(_WIN64)
  int ioctlsocket(SOCKET s, long cmd, u_long* argp) const override;
#else
  int fcntl_setfl(int fd, int flags) const override;
#endif

  int getsockname(int sockfd, struct sockaddr* addr,
                  socklen_t* addrlen) const override;

  int bind(int sockfd, const struct sockaddr* addr,
           socklen_t addrlen) const override;

  int connect(int sockfd, const struct sockaddr* addr,
              socklen_t addrlen) const override;

  int select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds,
             struct timeval* timeout) const override;

  ssize_t recvfrom(int sockfd, void* buf, size_t len, int flags,
                   struct sockaddr* src_addr,
                   socklen_t* addrlen) const override;

  ssize_t sendto(int sockfd, const void* buf, size_t len, int flags,
                 const struct sockaddr* dest_addr,
                 socklen_t addrlen) const override;

  std::string inetToString(const struct in_addr& addr) const override;

  const char* inet_ntop(int af, const void* src, char* dst,
                        socklen_t size) const override;

  in_addr_t inet_addr(const char* cp) const override;
};

}  // END namespace NETWORK
}  // END namespace KDIS
