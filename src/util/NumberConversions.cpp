#include <cmath>
#include <limits>

#include "KDIS/util/NumberConversions.hpp"

namespace KDIS {
namespace UTIL {

std::int32_t double_to_int32(double value) {
  if (std::isnan(value) || std::isinf(value)) {
    throw std::invalid_argument("Cannot convert NaN or infinity to int32_t");
  }
  if (value > static_cast<double>(std::numeric_limits<std::int32_t>::max())) {
    throw std::overflow_error("value exceeds int32_t maximum");
  }
  if (value < static_cast<double>(std::numeric_limits<std::int32_t>::min())) {
    throw std::underflow_error("value exceeds int32_t minimum");
  }
  return static_cast<std::int32_t>(value);
}

}  // namespace UTIL
}  // namespace KDIS
