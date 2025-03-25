#include <gtest/gtest.h>

#include <KDIS/DataTypes/Enums/EnumDescriptor.hpp>

class EnumDescriptorTest : public ::testing::Test {
 protected:
  enum class ThreeStooges { Larry = 7, Curly = 8, Moe = 11 };
  static const KDIS::DATA_TYPE::ENUMS::EnumDescriptor ThreeStoogesDescriptor[];
  static const std::vector<KDIS::DATA_TYPE::ENUMS::EnumDescriptor>
      ThreeStoogesDescVec;
};

const KDIS::DATA_TYPE::ENUMS::EnumDescriptor
    EnumDescriptorTest::ThreeStoogesDescriptor[] = {
        {static_cast<int>(ThreeStooges::Larry), "Larry"},
        {static_cast<int>(ThreeStooges::Curly), "Curly"},
        {static_cast<int>(ThreeStooges::Moe), "Moe"}};
const std::vector<KDIS::DATA_TYPE::ENUMS::EnumDescriptor>
    EnumDescriptorTest::ThreeStoogesDescVec = {
        {static_cast<int>(ThreeStooges::Larry), "Larry"},
        {static_cast<int>(ThreeStooges::Curly), "Curly"},
        {static_cast<int>(ThreeStooges::Moe), "Moe"}};

TEST_F(EnumDescriptorTest, GetEnumAsStringCArr) {
  EXPECT_EQ("Larry", KDIS::DATA_TYPE::ENUMS::GetEnumAsString(
                         ThreeStoogesDescriptor, 3,
                         static_cast<int>(ThreeStooges::Larry)));
  EXPECT_NE("Victor", KDIS::DATA_TYPE::ENUMS::GetEnumAsString(
                          ThreeStoogesDescriptor, 3, -12));
}

TEST_F(EnumDescriptorTest, GetEnumAsStringVector) {
  EXPECT_EQ("Moe",
            KDIS::DATA_TYPE::ENUMS::GetEnumAsString(
                ThreeStoogesDescVec, static_cast<int>(ThreeStooges::Moe)));
  EXPECT_NE("Karen",
            KDIS::DATA_TYPE::ENUMS::GetEnumAsString(ThreeStoogesDescVec, 47));
}

TEST_F(EnumDescriptorTest, GetEnumFromStringCArr) {
  KDIS::KINT32 out{0};
  EXPECT_TRUE(KDIS::DATA_TYPE::ENUMS::GetEnumFromString(ThreeStoogesDescriptor,
                                                        3, "Curly", out));
  EXPECT_EQ(static_cast<int>(ThreeStooges::Curly), out);
  EXPECT_FALSE(KDIS::DATA_TYPE::ENUMS::GetEnumFromString(ThreeStoogesDescriptor,
                                                         3, "Arnold", out));
}

TEST_F(EnumDescriptorTest, GetEnumFromStringVector) {
  KDIS::KINT32 out{0};
  EXPECT_TRUE(KDIS::DATA_TYPE::ENUMS::GetEnumFromString(ThreeStoogesDescVec,
                                                        "Moe", out));
  EXPECT_EQ(static_cast<int>(ThreeStooges::Moe), out);
  EXPECT_FALSE(KDIS::DATA_TYPE::ENUMS::GetEnumFromString(ThreeStoogesDescVec,
                                                         "Vinny", out));
}