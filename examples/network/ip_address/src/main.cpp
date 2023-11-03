#include <KDIS/Network/IPAddress.hpp>
#include <iostream>

static void print(const KDIS::NETWORK::IPAddress &address);

int main() {
  print(KDIS::NETWORK::IPAddress("127.0.0.1"));
  print(KDIS::NETWORK::IPAddress("::1"));
  print(KDIS::NETWORK::IPAddress("224.0.0.1"));
  print(KDIS::NETWORK::IPAddress("ff02::1"));
  print(KDIS::NETWORK::IPAddress("127.0.0.1",
                                 KDIS::NETWORK::AddressFamily::IPv4));
  print(
      KDIS::NETWORK::IPAddress("::1", KDIS::NETWORK::AddressFamily::IPv6, 255));

  return EXIT_SUCCESS;
}

static void print(const KDIS::NETWORK::IPAddress &address) {
  std::cout << address << std::endl;
  std::cout << "\tFAMILY: ";
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
  std::cout << std::boolalpha << "\tIPv4: " << address.isIPv4() << std::endl;
  std::cout << std::boolalpha << "\tIPv6: " << address.isIPv6() << std::endl;
  std::cout << std::boolalpha << "\tMULTICAST: " << address.isMulticast()
            << std::endl;
}
