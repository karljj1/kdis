#include <gtest/gtest.h>

#include <KDIS/Extras/DeadReckoningCalculator.hpp>
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

class MatrixTest : public ::testing::Test {
 protected:
  KDIS::UTILS::Matrix<int, 3, 2> mtx;
};

TEST_F(MatrixTest, inPlaceTranspose) {
  EXPECT_NO_THROW(mtx.inPlaceTranspose());
}

class DeadReckoningCalculatorTest : public ::testing::Test {
 protected:
  KDIS::UTILS::DeadReckoningCalculator drc;
};

TEST_F(DeadReckoningCalculatorTest, Reset) {
  const KDIS::DATA_TYPE::Vector vec;
  const KDIS::DATA_TYPE::WorldCoordinates wc;
  const KDIS::DATA_TYPE::EulerAngles ea;
  EXPECT_NO_THROW(
      drc.Reset(vec, vec, vec, wc, ea, vec, KDIS::DATA_TYPE::ENUMS::Static));
}