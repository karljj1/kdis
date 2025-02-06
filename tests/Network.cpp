#include <gtest/gtest.h>

#include <KDIS/KDefines.hpp>
#include <KDIS/Network/Connection.hpp>
#include <iostream>
#include <string>

TEST(Network, Connection) {
  KDIS::NETWORK::Connection conn{"badAddress"};
  EXPECT_NO_THROW(conn.SetSendAddress("nonsense"));
  EXPECT_THROW(conn.AddMulticastAddress("notAMulticastAddress"),
               KDIS::KException);
  EXPECT_THROW(conn.RemoveMulticastAddress("notOneEither"), KDIS::KException);
  // Probably need a mocking framework to properly unit test here. This code
  //    throws on macos, but not in Windows WSL Ubuntu.
  //  const std::string someData{"justAString"};
  //  EXPECT_NO_THROW(conn.Send(someData.c_str(), someData.size()));
  //  EXPECT_NO_THROW(conn.Receive(nullptr, 0));
}