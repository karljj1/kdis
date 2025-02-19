#pragma once

#include "KDIS/Network/ISocket.hpp"

namespace KDIS {
namespace NETWORK {

class Socket : public ISocket {
 public:
  int Select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds,
             struct timeval* timeout) const override;

  ssize_t RecvFrom(int sockfd, void* buf, size_t len, int flags,
                   struct sockaddr* src_addr,
                   socklen_t* addrlen) const override;

  std::string inetToString(const struct in_addr& addr) const override;

  ssize_t SendTo(int sockfd, void* buf, size_t len, int flags,
                 const struct sockaddr* dest_addr,
                 socklen_t addrlen) const override;
};

}  // END namespace NETWORK
}  // END namespace KDIS
