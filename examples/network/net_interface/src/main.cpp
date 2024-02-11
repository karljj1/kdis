#include <KDIS/Network/NetInterface.hpp>
#include <iostream>

static void print(const KDIS::NETWORK::NetInterface &netInterface);

int main() {
  std::cout << "-------------------- ALL --------------------" << std::endl;
  for (const auto &netInterface : KDIS::NETWORK::NetInterface::list(false)) {
    print(netInterface);
  }

  std::cout << "-------------------- NAME --------------------" << std::endl;
#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  print(KDIS::NETWORK::NetInterface::forName("Ethernet"));
#else
  print(KDIS::NETWORK::NetInterface::forName("eth0"));
#endif

  std::cout << "-------------------- ADDRESS --------------------" << std::endl;
  print(KDIS::NETWORK::NetInterface::forAddress(
      KDIS::NETWORK::IPAddress("127.0.0.1")));

  std::cout << "-------------------- INDEX --------------------" << std::endl;
  print(KDIS::NETWORK::NetInterface::forIndex(1));

  return EXIT_SUCCESS;
}

static void print(const KDIS::NETWORK::NetInterface &netInterface) {
  std::cout << netInterface.name() << ":" << std::endl;
  std::cout << "\tINDEX: " << netInterface.index() << std::endl;
  std::cout << std::boolalpha << "\tUP: " << netInterface.isUp() << std::endl;
  std::cout << std::boolalpha << "\tRUNNING: " << netInterface.isRunning()
            << std::endl;
  std::cout << std::boolalpha << "\tLOOPBACK: " << netInterface.isLoopback()
            << std::endl;
  std::cout << std::boolalpha
            << "\tMULTICAST: " << netInterface.supportsMulticast() << std::endl;
  std::cout << std::boolalpha << "\tIPv4: " << netInterface.supportsIPv4()
            << std::endl;
  std::cout << std::boolalpha << "\tIPv6: " << netInterface.supportsIPv6()
            << std::endl;
  std::cout << "\tADDRESSES:" << std::endl;
  for (const auto &address : netInterface.addresses()) {
    std::cout << "\t\t" << address << std::endl;
  }
}
