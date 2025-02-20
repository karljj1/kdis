#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "KDIS/KDefines.hpp"
#include "KDIS/Network/Connection.hpp"
#include "KDIS/Network/ISocket.hpp"

class MockSocket : public KDIS::NETWORK::ISocket {
 public:
  int socket(int domain, int type, int protocol) const override { return 0; }

  int setsockopt(int sockfd, int level, int optname, const void* optval,
                 socklen_t optlen) const override {
    return 0;
  }

#if defined(WIN32) | defined(_WIN32) | defined(WIN64) | defined(_WIN64)
  int ioctlsocket(SOCKET s, long cmd, u_long* argp) const override { return 0; }
#else
  int fcntl_setfl(int fd, int flags) const override { return 0; }
#endif

  int getsockname(int sockfd, struct sockaddr* addr,
                  socklen_t* addrlen) const override {
    return 0;
  }

  int bind(int sockfd, const struct sockaddr* addr,
           socklen_t addrlen) const override {
    return 0;
  }

  int select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds,
             struct timeval* timeout) const override {
    return 0;
  }

  int connect(int sockfd, const struct sockaddr* addr,
              socklen_t addrlen) const override {
    return 0;
  }

  ssize_t recvfrom(int sockfd, void* buf, size_t len, int flags,
                   struct sockaddr* src_addr,
                   socklen_t* addrlen) const override {
    return 0;
  }

  ssize_t sendto(int sockfd, const void* buf, size_t len, int flags,
                 const struct sockaddr* dest_addr,
                 socklen_t addrlen) const override {
    return 0;
  }

  std::string inetToString(const struct in_addr& addr) const override {
    return "";
  }

  const char* inet_ntop(int af, const void* src, char* dst,
                        socklen_t size) const override {
    return "";
  }

  in_addr_t inet_addr(const char* cp) const override { return 0; }
};

TEST(Network, Connection) {
  KDIS::NETWORK::Connection conn{
      "badAddress",
      9999,
      true,
      false,
      nullptr,
      true,
      true,
      "iface addy",
      std::unique_ptr<KDIS::NETWORK::ISocket>(new MockSocket())};
  EXPECT_NO_THROW(conn.AddMulticastAddress("notAMulticastAddress"));
  EXPECT_NO_THROW(conn.RemoveMulticastAddress("notOneEither"));
  const std::string someData{"justAString"};
  EXPECT_NO_THROW(conn.Send(someData.c_str(), someData.size()));
  EXPECT_NO_THROW(conn.Receive(nullptr, 0));
}
