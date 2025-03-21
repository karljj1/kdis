#ifndef KDIS_UTIL_ENDIAN_HPP_
#define KDIS_UTIL_ENDIAN_HPP_

#include "KDIS/KDefines.hpp"

namespace KDIS {
namespace UTIL {

/**
 * @brief This class supports querying machine endianness. It does not provide
 *        byte swap features. For byte swap support, see KEncodersDecoders.hpp.
 */
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

  /**
   * @brief Returns the endianness.
   *
   * @return Endianness.
   */
  static Endianness endian();

  /**
   * @brief Check if Little Endian (LE).
   *
   * @return True if Little Endian (LE), false otherwise.
   */
  static bool isLittleEndian();

  /**
   * @brief Check if Big Endian (BE).
   *
   * @return True if Big Endian (BE), false otherwise.
   */
  static bool isBigEndian();
};

}  // namespace UTIL
}  // namespace KDIS

#endif  // KDIS_UTIL_ENDIAN_HPP_
