#include <gtest/gtest.h>

#include <KDIS/Extras/KConversions.hpp>
#include <KDIS/KDefines.hpp>

TEST(Extras, KConversions) {
  constexpr double decimal{39.4221};
  double degrees{0};
  double minutes{0};
  double seconds{0};
  EXPECT_NO_THROW(
      KDIS::UTILS::DecimalToDMS(decimal, degrees, minutes, seconds));
}