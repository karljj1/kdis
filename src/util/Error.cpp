#include "KDIS/util/Error.hpp"

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)
  #include "errhandlingapi.h"
#else
  #include <cerrno>
#endif

namespace KDIS {
namespace UTIL {

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__WIN64__) || defined(__NT__)

DWORD Error::last() { return GetLastError(); }

std::string Error::toString(const DWORD error) {
  LPSTR buffer = nullptr;
  std::size_t size = FormatMessageA(
      FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
          FORMAT_MESSAGE_IGNORE_INSERTS,
      nullptr, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&buffer,
      0, nullptr);
  std::string message(buffer, size);
  LocalFree(buffer);
  return message;
}

#else

int Error::last() { return errno; }

std::string Error::toString(const int error) {
  #if (_XOPEN_SOURCE >= 600) || _GNU_SOURCE || __APPLE__
  char buffer[256] = {'\0'};
  strerror_r(error, buffer, sizeof(buffer));
  return std::string(buffer);
  #else
  return std::string(strerror(err));
  #endif
}

#endif

}  // namespace UTIL
}  // namespace KDIS
