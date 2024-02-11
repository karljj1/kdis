// Inspired by
// https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf

#ifndef KDIS_UTIL_FORMAT_HPP_
#define KDIS_UTIL_FORMAT_HPP_

#include <memory>
#include <stdexcept>
#include <string>

namespace KDIS {
namespace UTIL {

/**
 * @brief Format args according to the format string fmt, and return the result
 * as a string.
 * Mimics
 *
 * [`std::format`](https://en.cppreference.com/w/cpp/utility/format/format) from
 * C++20.
 *
 * @tparam Args Types of `args`.
 * @param fmt Format string.
 * @param args Arguments to be formatted.
 * @return A string holding the formatted result.
 */
template <typename... Args>
std::string format(const std::string& fmt, Args... args) {
  const auto string_size =
      std::snprintf(nullptr, 0, fmt.c_str(), args...) + 1;  // Include '\0'
  if (string_size <= 0) {
    throw std::runtime_error("Formatting error");
  }
  const auto size = static_cast<std::size_t>(string_size);
  std::unique_ptr<char[]> buf(new char[size]);
  std::snprintf(buf.get(), size, fmt.c_str(), args...);
  return std::string(buf.get(), buf.get() + size - 1);  // Exclude '\0'
}

}  // namespace UTIL
}  // namespace KDIS

#endif  // KDIS_UTIL_FORMAT_HPP_
