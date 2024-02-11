#ifndef KDIS_NETWORK_CONNECTIONOPTIONS_HPP_
#define KDIS_NETWORK_CONNECTIONOPTIONS_HPP_

#include "KDIS/Extras/PDU_Factory.hpp"
#include "KDIS/KDefines.hpp"
#include "KDIS/Network/IPAddress.hpp"
#include "KDIS/Network/NetInterface.hpp"
#include "KDIS/util/optional.hpp"

namespace KDIS {
namespace NETWORK {

class KDIS_EXPORT ConnectionOptions {
 public:
  class KDIS_EXPORT SharedOptions {
   public:
    virtual ~SharedOptions() = default;

    bool enabled() const;

    const KDIS::UTIL::optional<NetInterface>& netInterface() const;

    const IPAddress& address() const;

    std::uint16_t port() const;

   protected:
    SharedOptions(bool enabled,
                  const KDIS::UTIL::optional<NetInterface>& netInterface,
                  const IPAddress& address, std::uint16_t port);

    virtual SharedOptions& setEnabled(bool enabled);

    virtual SharedOptions& setNetInterface(const NetInterface& netInterface);

    virtual SharedOptions& setAddress(const IPAddress& address);

    virtual SharedOptions& setPort(std::uint16_t port);

   private:
    bool _enabled;
    KDIS::UTIL::optional<NetInterface> _netInterface;
    IPAddress _address;
    std::uint16_t _port;
  };

  class KDIS_EXPORT RecvOptions : public ConnectionOptions::SharedOptions {
   public:
    RecvOptions();

    const KDIS::UTIL::optional<struct timeval>& timeout() const;

    const KDIS::UTILS::PDU_Factory& factory() const;

    RecvOptions& setEnabled(bool enabled) override;

    RecvOptions& setNetInterface(const NetInterface& netInterface) override;

    RecvOptions& setAddress(const IPAddress& address) override;

    RecvOptions& setPort(std::uint16_t port) override;

    RecvOptions& setTimeout(
        const KDIS::UTIL::optional<struct timeval>& timeout);

    RecvOptions& setFactory(const KDIS::UTILS::PDU_Factory& factory);

   private:
    KDIS::UTIL::optional<struct timeval> _timeout;
    KDIS::UTILS::PDU_Factory _factory;
  };

  class KDIS_EXPORT SendOptions : public ConnectionOptions::SharedOptions {
   public:
    SendOptions();

    SendOptions& setEnabled(bool enabled) override;

    SendOptions& setNetInterface(const NetInterface& netInterface) override;

    SendOptions& setAddress(const IPAddress& address) override;

    SendOptions& setPort(std::uint16_t port) override;
  };

  ConnectionOptions() = default;

  ConnectionOptions::RecvOptions& recv();

  const ConnectionOptions::RecvOptions& recv() const;

  ConnectionOptions::SendOptions& send();

  const ConnectionOptions::SendOptions& send() const;

 private:
  ConnectionOptions::RecvOptions _recv;
  ConnectionOptions::SendOptions _send;
};

}  // namespace NETWORK
}  // namespace KDIS

#endif  // KDIS_NETWORK_CONNECTIONOPTIONS_HPP_
