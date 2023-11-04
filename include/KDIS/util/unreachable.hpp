#ifndef KDIS_UTIL_UNREACHABLE_HPP_
#define KDIS_UTIL_UNREACHABLE_HPP_

namespace KDIS {
namespace UTIL {

/**
 * @brief Invokes undefined behavior.
 * An implementation may use this to optimize impossible code branches away
 * (typically, in optimized builds) or to trap them to prevent further execution
 * (typically, in debug builds).
 *
 * Mimics
 * [`std::unreachable`](https://en.cppreference.com/w/cpp/utility/unreachable)
 * from C++23.
 */
[[noreturn]] inline void unreachable() {
#ifdef __GNUC__
  __builtin_unreachable();
#elif defined(_MSC_VER)
  __assume(false);
#endif
}

}  // namespace UTIL
}  // namespace KDIS

#endif  // KDIS_UTIL_UNREACHABLE_HPP_
