#include <KDIS/Network/ConnectionOptions.hpp>
#include <iostream>

static void print(const KDIS::NETWORK::ConnectionOptions &options);

int main() {
  std::cout << "-------------------- DEFAULT --------------------" << std::endl;
  print(KDIS::NETWORK::ConnectionOptions());

  std::cout << "-------------------- CUSTOM --------------------" << std::endl;
  KDIS::NETWORK::ConnectionOptions options;
  options.recv()
      .setEnabled(true)
      .setNetInterface(KDIS::NETWORK::NetInterface::forAddress(
          KDIS::NETWORK::IPAddress("127.0.0.1")))
      .setAddress(KDIS::NETWORK::IPAddress("0.0.0.0"))
      .setPort(6000)
      .setTimeout(timeval{10, 500000});
  options.send()
      .setEnabled(true)
      .setNetInterface(KDIS::NETWORK::NetInterface::forAddress(
          KDIS::NETWORK::IPAddress("127.0.0.1")))
      .setAddress(KDIS::NETWORK::IPAddress("127.0.0.1"))
      .setPort(9000);
  print(options);

  return EXIT_SUCCESS;
}

static void print(const KDIS::NETWORK::ConnectionOptions &options) {
  const auto &printEnabled = [](const bool enabled) {
    std::cout << std::boolalpha << "\tENABLED: " << enabled << std::endl;
  };
  const auto &printNetInterface =
      [](const KDIS::UTIL::optional<KDIS::NETWORK::NetInterface>
             &netInterface) {
        if (!netInterface.has_value()) return;
        std::cout << "\tINTERFACE:" << std::endl;
        std::cout << "\t\tNAME: " << netInterface->name() << std::endl;
        std::cout << "\t\tINDEX: " << netInterface->index() << std::endl;
        std::cout << std::boolalpha << "\t\tUP: " << netInterface->isUp()
                  << std::endl;
        std::cout << std::boolalpha
                  << "\t\tRUNNING: " << netInterface->isRunning() << std::endl;
        std::cout << std::boolalpha
                  << "\t\tLOOPBACK: " << netInterface->isLoopback()
                  << std::endl;
        std::cout << std::boolalpha
                  << "\t\tMULTICAST: " << netInterface->supportsMulticast()
                  << std::endl;
        std::cout << std::boolalpha
                  << "\t\tIPv4: " << netInterface->supportsIPv4() << std::endl;
        std::cout << std::boolalpha
                  << "\t\tIPv6: " << netInterface->supportsIPv6() << std::endl;
        std::cout << "\t\tADDRESSES:" << std::endl;
        for (const auto &address : netInterface->addresses()) {
          std::cout << "\t\t\t" << address << std::endl;
        }
      };
  const auto &printAddress = [](const KDIS::NETWORK::IPAddress &address) {
    std::cout << "\tADDRESS:" << std::endl;
    std::cout << "\t\t" << address << std::endl;
    std::cout << "\t\tFAMILY: ";
    switch (address.family()) {
      case KDIS::NETWORK::AddressFamily::IPv4:
        std::cout << "IPv4" << std::endl;
        break;
      case KDIS::NETWORK::AddressFamily::IPv6:
        std::cout << "IPv6" << std::endl;
        break;
      default:
        std::cout << "UNKNOWN" << std::endl;
        break;
    }
    std::cout << std::boolalpha << "\t\tIPv4: " << address.isIPv4()
              << std::endl;
    std::cout << std::boolalpha << "\t\tIPv6: " << address.isIPv6()
              << std::endl;
    std::cout << std::boolalpha << "\t\tMULTICAST: " << address.isMulticast()
              << std::endl;
  };
  const auto &printPort = [](const std::uint16_t port) {
    std::cout << "\tPORT:" << std::endl;
    std::cout << "\t\t" << port << std::endl;
  };
  const auto &printTimeout =
      [](const KDIS::UTIL::optional<struct timeval> &timeout) {
        if (!timeout.has_value()) return;
        std::cout << "\tTIMEOUT:" << std::endl;
        std::cout << "\t\tSECONDS: " << timeout->tv_sec << std::endl;
        std::cout << "\t\tMICROSECONDS: " << timeout->tv_usec << std::endl;
      };
  const auto &printFactory = [](const KDIS::UTILS::PDU_Factory &factory) {
    std::cout << "\tFACTORY:" << std::endl;
    std::cout << "\t\t" << &factory << std::endl;
  };

  std::cout << "RECV:" << std::endl;
  printEnabled(options.recv().enabled());
  printNetInterface(options.recv().netInterface());
  printAddress(options.recv().address());
  printPort(options.recv().port());
  printTimeout(options.recv().timeout());
  printFactory(options.recv().factory());
  std::cout << "SEND:" << std::endl;
  printEnabled(options.send().enabled());
  printNetInterface(options.send().netInterface());
  printAddress(options.send().address());
  printPort(options.send().port());
}
