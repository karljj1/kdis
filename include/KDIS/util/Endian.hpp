#ifndef KDIS_UTIL_ENDIAN_HPP_
#define KDIS_UTIL_ENDIAN_HPP_

#include "KDIS/KDefines.hpp"

namespace KDIS {
namespace UTIL {

class KDIS_EXPORT Endian {
 public:
  /**
   * @brief Endianness.
   */
  enum class Endianness : std::uint8_t {
    /**
     * @brief Little Endian (LE).
     * Least significant byte at the smallest address.
     * Most significant byte at the largest address.
     */
    LITTLE,
    /**
     * @brief Big Endian (BE).
     * Least significant byte at the largest address.
     * Most significant byte at the smallest address.
     */
    BIG
  };

  static Endianness endian();

  static bool isBigEndian();

  static bool isLittleEndian();
};

}  // namespace UTIL
}  // namespace KDIS

#endif  // KDIS_UTIL_ENDIAN_HPP_
