#pragma once

#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/socket.h>

#include <string>

namespace KDIS {
namespace NETWORK {

// Interface class designed to allow dependency injection of socket features.
class ISocket {
 public:
  virtual ~ISocket() = default;

  virtual int Select(int nfds, fd_set* readfds, fd_set* writefds,
                     fd_set* exceptfds, struct timeval* timeout) const = 0;

  virtual ssize_t RecvFrom(int sockfd, void* buf, size_t len, int flags,
                           struct sockaddr* src_addr,
                           socklen_t* addrlen) const = 0;

  virtual std::string inetToString(const struct in_addr& addr) const = 0;

  virtual ssize_t SendTo(int sockfd, void* buf, size_t len, int flags,
                         const struct sockaddr* dest_addr,
                         socklen_t addrlen) const = 0;
};

}  // END namespace NETWORK
}  // END namespace KDIS
