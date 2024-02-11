#include "KDIS/Network/ConnectionOptions.hpp"

#include "KDIS/KConfig.hpp"

namespace KDIS {
namespace NETWORK {

ConnectionOptions::SharedOptions::SharedOptions(
    bool enabled, const KDIS::UTIL::optional<NetInterface>& netInterface,
    const IPAddress& address, const std::uint16_t port)
    : _enabled(enabled),
      _netInterface(netInterface),
      _address(address),
      _port(port) {}

bool ConnectionOptions::SharedOptions::enabled() const { return _enabled; }

const KDIS::UTIL::optional<NetInterface>&
ConnectionOptions::SharedOptions::netInterface() const {
  return _netInterface;
}

const IPAddress& ConnectionOptions::SharedOptions::address() const {
  return _address;
}

std::uint16_t ConnectionOptions::SharedOptions::port() const { return _port; }

ConnectionOptions::SharedOptions& ConnectionOptions::SharedOptions::setEnabled(
    const bool enabled) {
  _enabled = enabled;
  return *this;
}

ConnectionOptions::SharedOptions&
ConnectionOptions::SharedOptions::setNetInterface(
    const NetInterface& netInterface) {
  _netInterface = netInterface;
  return *this;
}

ConnectionOptions::SharedOptions& ConnectionOptions::SharedOptions::setAddress(
    const IPAddress& address) {
  _address = address;
  return *this;
}

ConnectionOptions::SharedOptions& ConnectionOptions::SharedOptions::setPort(
    const std::uint16_t port) {
  _port = port;
  return *this;
}

ConnectionOptions::RecvOptions::RecvOptions()
    : ConnectionOptions::SharedOptions(
          true, KDIS::UTIL::nullopt,
          IPAddress(KDIS_CONNECTION_DEFAULT_RECV_ADDRESS),
          KDIS_CONNECTION_DEFAULT_RECV_PORT),
      _timeout(KDIS::UTIL::nullopt),
      _factory() {}

const KDIS::UTIL::optional<struct timeval>&
ConnectionOptions::RecvOptions::timeout() const {
  return _timeout;
}

const KDIS::UTILS::PDU_Factory& ConnectionOptions::RecvOptions::factory()
    const {
  return _factory;
}

ConnectionOptions::RecvOptions& ConnectionOptions::RecvOptions::setEnabled(
    bool enabled) {
  ConnectionOptions::SharedOptions::setEnabled(enabled);
  return *this;
}

ConnectionOptions::RecvOptions& ConnectionOptions::RecvOptions::setNetInterface(
    const NetInterface& netInterface) {
  ConnectionOptions::SharedOptions::setNetInterface(netInterface);
  return *this;
}

ConnectionOptions::RecvOptions& ConnectionOptions::RecvOptions::setAddress(
    const IPAddress& address) {
  ConnectionOptions::SharedOptions::setAddress(address);
  return *this;
}

ConnectionOptions::RecvOptions& ConnectionOptions::RecvOptions::setPort(
    std::uint16_t port) {
  ConnectionOptions::SharedOptions::setPort(port);
  return *this;
}

ConnectionOptions::RecvOptions& ConnectionOptions::RecvOptions::setTimeout(
    const KDIS::UTIL::optional<struct timeval>& timeout) {
  _timeout = timeout;
  return *this;
}

ConnectionOptions::RecvOptions& ConnectionOptions::RecvOptions::setFactory(
    const KDIS::UTILS::PDU_Factory& factory) {
  _factory = factory;
  return *this;
}

ConnectionOptions::SendOptions::SendOptions()
    : ConnectionOptions::SharedOptions(
          true, KDIS::UTIL::nullopt,
          IPAddress(KDIS_CONNECTION_DEFAULT_SEND_ADDRESS),
          KDIS_CONNECTION_DEFAULT_SEND_PORT) {}

ConnectionOptions::SendOptions& ConnectionOptions::SendOptions::setEnabled(
    bool enabled) {
  ConnectionOptions::SharedOptions::setEnabled(enabled);
  return *this;
}

ConnectionOptions::SendOptions& ConnectionOptions::SendOptions::setNetInterface(
    const NetInterface& netInterface) {
  ConnectionOptions::SharedOptions::setNetInterface(netInterface);
  return *this;
}

ConnectionOptions::SendOptions& ConnectionOptions::SendOptions::setAddress(
    const IPAddress& address) {
  ConnectionOptions::SharedOptions::setAddress(address);
  return *this;
}

ConnectionOptions::SendOptions& ConnectionOptions::SendOptions::setPort(
    std::uint16_t port) {
  ConnectionOptions::SharedOptions::setPort(port);
  return *this;
}

ConnectionOptions::RecvOptions& ConnectionOptions::recv() { return _recv; }

const ConnectionOptions::RecvOptions& ConnectionOptions::recv() const {
  return _recv;
}

ConnectionOptions::SendOptions& ConnectionOptions::send() { return _send; }

const ConnectionOptions::SendOptions& ConnectionOptions::send() const {
  return _send;
}

}  // namespace NETWORK
}  // namespace KDIS
