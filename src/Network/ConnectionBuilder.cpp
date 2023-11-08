#include "KDIS/Network/ConnectionBuilder.hpp"

#include "KDIS/KConfig.hpp"

namespace KDIS {
namespace NETWORK {

ConnectionBuilder::ConnectionBuilder()
    : recvInterface(KDIS::UTIL::nullopt),
      recvAddress(IPAddress(KDIS_CONNECTION_DEFAULT_RECV_ADDRESS)),
      recvPort(KDIS_CONNECTION_DEFAULT_RECV_PORT),
      sendInterface(KDIS::UTIL::nullopt),
      sendAddress(IPAddress(KDIS_CONNECTION_DEFAULT_SEND_ADDRESS)),
      sendPort(KDIS_CONNECTION_DEFAULT_SEND_PORT) {}

const KDIS::UTIL::optional<NetInterface>& ConnectionBuilder::getRecvInterface()
    const {
  return recvInterface;
}

ConnectionBuilder& ConnectionBuilder::setRecvInterface(
    const NetInterface& netInterface) {
  this->recvInterface = netInterface;
  return *this;
}

const IPAddress& ConnectionBuilder::getRecvAddress() const {
  return recvAddress;
}

ConnectionBuilder& ConnectionBuilder::setRecvAddress(const IPAddress& address) {
  this->recvAddress = address;
  return *this;
}

std::uint16_t ConnectionBuilder::getRecvPort() const { return recvPort; }

ConnectionBuilder& ConnectionBuilder::setRecvPort(const std::uint16_t port) {
  this->recvPort = port;
  return *this;
}

const KDIS::UTIL::optional<NetInterface>& ConnectionBuilder::getSendInterface()
    const {
  return sendInterface;
}

ConnectionBuilder& ConnectionBuilder::setSendInterface(
    const NetInterface& netInterface) {
  this->sendInterface = netInterface;
  return *this;
}

const IPAddress& ConnectionBuilder::getSendAddress() const {
  return sendAddress;
}

ConnectionBuilder& ConnectionBuilder::setSendAddress(const IPAddress& address) {
  this->sendAddress = address;
  return *this;
}

std::uint16_t ConnectionBuilder::getSendPort() const { return sendPort; }

ConnectionBuilder& ConnectionBuilder::setSendPort(const std::uint16_t port) {
  this->sendPort = port;
  return *this;
}

}  // namespace NETWORK
}  // namespace KDIS
