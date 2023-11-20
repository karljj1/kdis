#ifndef KDIS_NETWORK_CONNECTIONBUILDER_HPP_
#define KDIS_NETWORK_CONNECTIONBUILDER_HPP_

#include <memory>

#include "KDIS/Extras/PDU_Factory.hpp"
#include "KDIS/KDefines.hpp"
#include "KDIS/Network/Connection.hpp"
#include "KDIS/Network/IPAddress.hpp"
#include "KDIS/Network/NetInterface.hpp"
#include "KDIS/util/optional.hpp"

namespace KDIS {
namespace NETWORK {

class KDIS_EXPORT ConnectionBuilder {
 public:
  ConnectionBuilder();

  bool getRecv() const;

  ConnectionBuilder& setRecv(const bool recv);

  const KDIS::UTIL::optional<NetInterface>& getRecvInterface() const;

  ConnectionBuilder& setRecvInterface(const NetInterface& netInterface);

  const IPAddress& getRecvAddress() const;

  ConnectionBuilder& setRecvAddress(const IPAddress& address);

  std::uint16_t getRecvPort() const;

  ConnectionBuilder& setRecvPort(const std::uint16_t port);

  const KDIS::UTIL::optional<struct timeval>& getRecvTimeout() const;

  ConnectionBuilder& setRecvTimeout(const struct timeval& timeout);

  const KDIS::UTILS::PDU_Factory& getRecvFactory() const;

  ConnectionBuilder& setRecvFactory(const KDIS::UTILS::PDU_Factory& factory);

  bool getSend() const;

  ConnectionBuilder& setSend(const bool send);

  const KDIS::UTIL::optional<NetInterface>& getSendInterface() const;

  ConnectionBuilder& setSendInterface(const NetInterface& netInterface);

  const IPAddress& getSendAddress() const;

  ConnectionBuilder& setSendAddress(const IPAddress& address);

  std::uint16_t getSendPort() const;

  ConnectionBuilder& setSendPort(const std::uint16_t port);

  std::unique_ptr<Connection> build();

 private:
  bool recv;
  KDIS::UTIL::optional<NetInterface> recvInterface;
  IPAddress recvAddress;
  std::uint16_t recvPort;
  KDIS::UTIL::optional<struct timeval> recvTimeout;
  KDIS::UTILS::PDU_Factory recvFactory;

  bool send;
  KDIS::UTIL::optional<NetInterface> sendInterface;
  IPAddress sendAddress;
  std::uint16_t sendPort;
};

}  // namespace NETWORK
}  // namespace KDIS

#endif  // KDIS_NETWORK_CONNECTIONBUILDER_HPP_
