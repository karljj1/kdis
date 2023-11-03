#ifndef KDIS_UTIL_ERROR_HPP_
#define KDIS_UTIL_ERROR_HPP_

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  #include "windef.h"
#endif

#include "KDIS/KDefines.hpp"

namespace KDIS {
namespace UTIL {

class KDIS_EXPORT Error {
 public:
#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  static DWORD last();

  static std::string toString(const DWORD error = Error::last());
#else
  static int last();

  static std::string toString(const int error = Error::last());
#endif
};

}  // namespace UTIL
}  // namespace KDIS

#endif  // KDIS_UTIL_ERROR_HPP_
