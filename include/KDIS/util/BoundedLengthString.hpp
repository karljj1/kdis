#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>

namespace KDIS {
namespace UTIL {

// For the purposes of this class, N includes the number of readable characters
//    AND the null terminator. So the maximum readable # of characters that can
//    be stored by this class is N - 1.
template <std::size_t N>
class BoundedLengthString {
 private:
  std::array<char, N> data{};  // pre-filled with \0s

  static_assert(N > 0, "Size must be at least 1 to hold a null terminator");

 public:
  BoundedLengthString() = default;

  void assign(const std::string& s) {
    data.fill('\0');  // ensure null termination
    // Adjust copy count to fit within source size and array capacity
    std::size_t safe_count = std::min(s.size(), N - 1);  // disallow overflow
    std::copy_n(s.begin(), safe_count, data.begin());
  }

  std::string str() const noexcept { return data.data(); }

  std::size_t max_size() const noexcept { return N; }

  // non-const for write access
  char& operator[](std::size_t index) {
    return data[index];  // no bounds checking, like std::array
  }

  // const for read-only access
  const char& operator[](std::size_t index) const {
    return data[index];  // no bounds checking, like std::array
  }

  bool operator==(const BoundedLengthString<N>& rhs) const {
    return (this->data == rhs.data);
  }

  bool operator!=(const BoundedLengthString<N>& rhs) const {
    return !(*this == rhs);
  }
};

}  // namespace UTIL
}  // namespace KDIS