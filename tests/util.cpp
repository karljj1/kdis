#include <gtest/gtest.h>

#include <cmath>
#include <limits>
#include <string>

#include "KDIS/util/BoundedLengthString.hpp"
#include "KDIS/util/NumberConversions.hpp"

TEST(util, BoundedLengthString) {
  KDIS::UTIL::BoundedLengthString<7> bls;
  const std::string seven{"seven"};
  const std::string eleven{"eleven"};
  const std::string fourteen{"fourteen"};
  EXPECT_NO_THROW(bls.assign(seven));
  EXPECT_EQ(seven, bls.str());
  EXPECT_NO_THROW(bls.assign(eleven));
  EXPECT_EQ(eleven, bls.str());
  EXPECT_NO_THROW(bls.assign(fourteen));
  EXPECT_EQ("fourte", bls.str());
  EXPECT_EQ(7, bls.max_size());
  EXPECT_EQ('u', bls[2]);
  EXPECT_EQ('e', bls[5]);
  EXPECT_EQ('\0', bls[6]);
  EXPECT_NO_THROW(bls[5] = 'h');
  KDIS::UTIL::BoundedLengthString<7> bls2;
  EXPECT_NO_THROW(bls2.assign("filthy"));
  EXPECT_TRUE(bls == bls);
  EXPECT_TRUE(bls != bls2);
}

class NumberConversionsTest : public ::testing::Test {
 protected:
  static constexpr double infinity{std::numeric_limits<double>::infinity()};
  static const double nan;  // not constexpr, initialized below
  static constexpr double int_max_as_double{
      static_cast<double>(std::numeric_limits<std::int32_t>::max())};
  static constexpr double int_min_as_double{
      static_cast<double>(std::numeric_limits<std::int32_t>::min())};
};

const double NumberConversionsTest::nan = std::nan("1");

TEST_F(NumberConversionsTest, HandlesNaN) {
  EXPECT_THROW(KDIS::UTIL::double_to_int32(nan), std::invalid_argument);
}

TEST_F(NumberConversionsTest, HandlesPositiveInfinity) {
  EXPECT_THROW(KDIS::UTIL::double_to_int32(infinity), std::invalid_argument);
}

TEST_F(NumberConversionsTest, HandlesNegativeInfinity) {
  EXPECT_THROW(KDIS::UTIL::double_to_int32(-infinity), std::invalid_argument);
}

TEST_F(NumberConversionsTest, ThrowsOnOverflow) {
  constexpr double too_big{int_max_as_double + 1.0};
  EXPECT_THROW(KDIS::UTIL::double_to_int32(too_big), std::overflow_error);
  EXPECT_THROW(KDIS::UTIL::double_to_int32(1e10), std::overflow_error);
}

TEST_F(NumberConversionsTest, ThrowsOnUnderflow) {
  constexpr double too_small{int_min_as_double - 1.0};
  EXPECT_THROW(KDIS::UTIL::double_to_int32(too_small), std::underflow_error);
  EXPECT_THROW(KDIS::UTIL::double_to_int32(-1e10), std::underflow_error);
}

TEST_F(NumberConversionsTest, TruncatesPositiveValues) {
  EXPECT_EQ(3, KDIS::UTIL::double_to_int32(3.7));
  EXPECT_EQ(3, KDIS::UTIL::double_to_int32(3.2));
  EXPECT_EQ(std::numeric_limits<std::int32_t>::max(),
            KDIS::UTIL::double_to_int32(int_max_as_double));
  EXPECT_EQ(1, KDIS::UTIL::double_to_int32(1.5001));
}

TEST_F(NumberConversionsTest, TruncatesNegativeValues) {
  EXPECT_EQ(-3, KDIS::UTIL::double_to_int32(-3.7));
  EXPECT_EQ(-3, KDIS::UTIL::double_to_int32(-3.2));
  EXPECT_EQ(std::numeric_limits<std::int32_t>::min(),
            KDIS::UTIL::double_to_int32(int_min_as_double));
  EXPECT_EQ(-1, KDIS::UTIL::double_to_int32(-1.5001));
}

TEST_F(NumberConversionsTest, HandlesZero) {
  EXPECT_EQ(0, KDIS::UTIL::double_to_int32(0.0));
  EXPECT_EQ(0, KDIS::UTIL::double_to_int32(-0.0));
}
