#ifndef KDIS_UTIL_ERROR_HPP_
#define KDIS_UTIL_ERROR_HPP_

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  #include "windef.h"
#endif

#include "KDIS/KDefines.hpp"

namespace KDIS {
namespace UTIL {

/**
 * @brief Error.
 */
class KDIS_EXPORT Error {
 public:
#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  /**
   * @brief Returns the last error code for the calling thread.
   *
   * @return Last error.
   */
  static DWORD last();

  /**
   * @brief Returns the string describing the error.
   *
   * @param error Error code. By default, the last error code.
   * @return String describing the error.
   */
  static std::string toString(const DWORD error = Error::last());
#else
  /**
   * @brief Returns the last error code for the calling thread.
   *
   * @return Last error.
   */
  static int last();

  /**
   * @brief Returns the string describing the error.
   *
   * @param error Error code. By default, the last error code.
   * @return String describing the error.
   */
  static std::string toString(const int error = Error::last());
#endif
};

}  // namespace UTIL
}  // namespace KDIS

#endif  // KDIS_UTIL_ERROR_HPP_
