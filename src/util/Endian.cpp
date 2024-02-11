#include "KDIS/util/Endian.hpp"

namespace KDIS {
namespace UTIL {

Endian::Endianness Endian::endian() {
  const short int num = 0x1;
  const auto *numPtr = reinterpret_cast<const char *>(&num);
  return (numPtr[0] == 1) ? Endianness::LITTLE : Endianness::BIG;
}

bool Endian::isLittleEndian() { return Endian::endian() == Endianness::LITTLE; }

bool Endian::isBigEndian() { return Endian::endian() == Endianness::BIG; }

}  // namespace UTIL
}  // namespace KDIS
