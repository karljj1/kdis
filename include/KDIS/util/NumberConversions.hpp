#pragma once

#include <cstdint>
#include <stdexcept>

namespace KDIS {
namespace UTIL {

// This function throws on NaN, infinity, overflow, and underflow. It truncates
// toward zero on a successful return.
std::int32_t double_to_int32(double value);

}  // namespace UTIL
}  // namespace KDIS