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

class MatrixTest : public ::testing::Test {};

TEST_F(MatrixTest, inPlaceTranspose) {
  KDIS::UTILS::Matrix<double, 3, 3> m1;

  m1.Data[0][0] = 3;
  m1.Data[0][1] = 3;
  m1.Data[0][2] = 3;

  EXPECT_NO_THROW(m1.inPlaceTranspose());
  ASSERT_EQ(m1.Data[0][0], 3);
  ASSERT_EQ(m1.Data[0][1], 0);
  ASSERT_EQ(m1.Data[0][2], 0);
  ASSERT_EQ(m1.Data[1][0], 3);
  ASSERT_EQ(m1.Data[1][1], 1);
  ASSERT_EQ(m1.Data[1][2], 0);
  ASSERT_EQ(m1.Data[2][0], 3);
  ASSERT_EQ(m1.Data[2][1], 0);
  ASSERT_EQ(m1.Data[2][2], 1);

  KDIS::UTILS::Matrix<double, 2, 3> m2;
  ASSERT_EQ(m2.Data[0][0], 1);
  ASSERT_EQ(m2.Data[0][1], 0);
  ASSERT_EQ(m2.Data[0][2], 0);
  ASSERT_EQ(m2.Data[1][0], 0);
  ASSERT_EQ(m2.Data[1][1], 1);
  ASSERT_EQ(m2.Data[1][2], 0);

  // no change should occur.
  // the matrix isn't square
  EXPECT_NO_THROW(m2.inPlaceTranspose());
  ASSERT_EQ(m2.Data[0][0], 1);
  ASSERT_EQ(m2.Data[0][1], 0);
  ASSERT_EQ(m2.Data[0][2], 0);
  ASSERT_EQ(m2.Data[1][0], 0);
  ASSERT_EQ(m2.Data[1][1], 1);
  ASSERT_EQ(m2.Data[1][2], 0);
}

TEST_F(MatrixTest, constructor) {
  KDIS::UTILS::Matrix<double, 3, 3> matrix;
  ASSERT_EQ(matrix.Data[0][0], 1);
  ASSERT_EQ(matrix.Data[0][1], 0);
  ASSERT_EQ(matrix.Data[0][2], 0);
  ASSERT_EQ(matrix.Data[1][0], 0);
  ASSERT_EQ(matrix.Data[1][1], 1);
  ASSERT_EQ(matrix.Data[1][2], 0);
  ASSERT_EQ(matrix.Data[2][0], 0);
  ASSERT_EQ(matrix.Data[2][1], 0);
  ASSERT_EQ(matrix.Data[2][2], 1);
}

TEST_F(MatrixTest, additional_operator) {
  KDIS::UTILS::Matrix<double, 3, 3> m1;
  KDIS::UTILS::Matrix<double, 3, 3> m2;

  m1 = m1 + m2;
  ASSERT_EQ(m1.Data[0][0], 2);
  ASSERT_EQ(m1.Data[0][1], 0);
  ASSERT_EQ(m1.Data[0][2], 0);
  ASSERT_EQ(m1.Data[1][0], 0);
  ASSERT_EQ(m1.Data[1][1], 2);
  ASSERT_EQ(m1.Data[1][2], 0);
  ASSERT_EQ(m1.Data[2][0], 0);
  ASSERT_EQ(m1.Data[2][1], 0);
  ASSERT_EQ(m1.Data[2][2], 2);

  m1 += m2;
  ASSERT_EQ(m1.Data[0][0], 3);
  ASSERT_EQ(m1.Data[0][1], 0);
  ASSERT_EQ(m1.Data[0][2], 0);
  ASSERT_EQ(m1.Data[1][0], 0);
  ASSERT_EQ(m1.Data[1][1], 3);
  ASSERT_EQ(m1.Data[1][2], 0);
  ASSERT_EQ(m1.Data[2][0], 0);
  ASSERT_EQ(m1.Data[2][1], 0);
  ASSERT_EQ(m1.Data[2][2], 3);
}

TEST_F(MatrixTest, subtraction_operator) {
  KDIS::UTILS::Matrix<double, 3, 3> m1;
  KDIS::UTILS::Matrix<double, 3, 3> m2;

  m1 = m1 - m2;
  ASSERT_EQ(m1.Data[0][0], 0);
  ASSERT_EQ(m1.Data[0][1], 0);
  ASSERT_EQ(m1.Data[0][2], 0);
  ASSERT_EQ(m1.Data[1][0], 0);
  ASSERT_EQ(m1.Data[1][1], 0);
  ASSERT_EQ(m1.Data[1][2], 0);
  ASSERT_EQ(m1.Data[2][0], 0);
  ASSERT_EQ(m1.Data[2][1], 0);
  ASSERT_EQ(m1.Data[2][2], 0);

  m1 -= m2;
  ASSERT_EQ(m1.Data[0][0], -1);
  ASSERT_EQ(m1.Data[0][1], 0);
  ASSERT_EQ(m1.Data[0][2], 0);
  ASSERT_EQ(m1.Data[1][0], 0);
  ASSERT_EQ(m1.Data[1][1], -1);
  ASSERT_EQ(m1.Data[1][2], 0);
  ASSERT_EQ(m1.Data[2][0], 0);
  ASSERT_EQ(m1.Data[2][1], 0);
  ASSERT_EQ(m1.Data[2][2], -1);
}

TEST_F(MatrixTest, multiplication_operator) {
  KDIS::UTILS::Matrix<double, 3, 3> m1;
  KDIS::UTILS::Matrix<double, 3, 3> m2;
  for (uint16_t i = 0; i < 3; ++i) {
    for (uint16_t j = 0; j < 3; ++j) {
      m1.Data[i][j] = 2;
      m2.Data[i][j] = 2;
    }
  }

  m1 = m1 * m2;

  ASSERT_EQ(m1.Data[0][0], 12);
  ASSERT_EQ(m1.Data[0][1], 12);
  ASSERT_EQ(m1.Data[0][2], 12);
  ASSERT_EQ(m1.Data[1][0], 12);
  ASSERT_EQ(m1.Data[1][1], 12);
  ASSERT_EQ(m1.Data[1][2], 12);
  ASSERT_EQ(m1.Data[2][0], 12);
  ASSERT_EQ(m1.Data[2][1], 12);
  ASSERT_EQ(m1.Data[2][2], 12);

  m1 = m1 * m2;

  ASSERT_EQ(m1.Data[0][0], 72);
  ASSERT_EQ(m1.Data[0][1], 72);
  ASSERT_EQ(m1.Data[0][2], 72);
  ASSERT_EQ(m1.Data[1][0], 72);
  ASSERT_EQ(m1.Data[1][1], 72);
  ASSERT_EQ(m1.Data[1][2], 72);
  ASSERT_EQ(m1.Data[2][0], 72);
  ASSERT_EQ(m1.Data[2][1], 72);
  ASSERT_EQ(m1.Data[2][2], 72);
}

TEST_F(MatrixTest, scalar_multuplication) {
  KDIS::UTILS::Matrix<double, 3, 3> m1;
  for (uint16_t i = 0; i < 3; ++i) {
    for (uint16_t j = 0; j < 3; ++j) {
      m1.Data[i][j] = 2;
    }
  }

  m1 *= 2;
  ASSERT_EQ(m1.Data[0][0], 4);
  ASSERT_EQ(m1.Data[0][1], 4);
  ASSERT_EQ(m1.Data[0][2], 4);
  ASSERT_EQ(m1.Data[1][0], 4);
  ASSERT_EQ(m1.Data[1][1], 4);
  ASSERT_EQ(m1.Data[1][2], 4);
  ASSERT_EQ(m1.Data[2][0], 4);
  ASSERT_EQ(m1.Data[2][1], 4);
  ASSERT_EQ(m1.Data[2][2], 4);

  m1 *= 2;
  ASSERT_EQ(m1.Data[0][0], 8);
  ASSERT_EQ(m1.Data[0][1], 8);
  ASSERT_EQ(m1.Data[0][2], 8);
  ASSERT_EQ(m1.Data[1][0], 8);
  ASSERT_EQ(m1.Data[1][1], 8);
  ASSERT_EQ(m1.Data[1][2], 8);
  ASSERT_EQ(m1.Data[2][0], 8);
  ASSERT_EQ(m1.Data[2][1], 8);
  ASSERT_EQ(m1.Data[2][2], 8);
}
