#include <gtest/gtest.h>

#include <KDIS/KDataStream.hpp>
#include <KDIS/KDefines.hpp>
#include <string>
#include <vector>

class KDataStreamTest : public ::testing::Test {
 protected:
  KDIS::KDataStream stream;
  // The following syntax can be simplified to use `auto` in C++17
  std::vector<KDIS::KOCTET> buf = std::vector<KDIS::KOCTET>(5);
};

TEST_F(KDataStreamTest, AlternateConstructors) {
  EXPECT_THROW(KDIS::KDataStream(nullptr, 0), std::invalid_argument);
  EXPECT_NO_THROW(KDIS::KDataStream(buf.data(), buf.size()));
}

TEST_F(KDataStreamTest, GetMachineEndian) {
  auto machEnd = stream.GetMachineEndian();
  EXPECT_TRUE(KDIS::UTILS::Endian::Endianness::BIG == machEnd ||
              KDIS::UTILS::Endian::Endianness::LITTLE == machEnd);
}

TEST_F(KDataStreamTest, GetNetWorkEndian) {
  EXPECT_EQ(KDIS::UTILS::Endian::Endianness::BIG, stream.GetNetWorkEndian());
}

TEST_F(KDataStreamTest, GetBufferSize) {
  EXPECT_NO_THROW(stream.GetBufferSize());
}

TEST_F(KDataStreamTest, CopyIntoBufferRejectNullptr) {
  EXPECT_THROW(stream.CopyIntoBuffer(nullptr, 0, 5), KDIS::KException);
}

TEST_F(KDataStreamTest, CopyIntoBufferRejectWritePosTooBig) {
  EXPECT_THROW(stream.CopyIntoBuffer(buf.data(), buf.size(), 7),
               KDIS::KException);
}

TEST_F(KDataStreamTest, CopyIntoBufferRejectSpaceInBufferTooSmall) {
  for (int ii = 0; ii < 17; ++ii) {
    stream.Write(0);
  }
  // internal buffer is too big to be copied into the 2 available buffer slots
  EXPECT_THROW(stream.CopyIntoBuffer(buf.data(), buf.size(), 3),
               KDIS::KException);
}

TEST_F(KDataStreamTest, GetBufferPtr) {
  EXPECT_NO_THROW(stream.GetBufferPtr());
}

TEST_F(KDataStreamTest, ReadFromString) {
  std::string str{""};
  EXPECT_NO_THROW(stream.ReadFromString(str));
  str = "3g9reay9reag@#$$%^#$@${}";
  EXPECT_NO_THROW(stream.ReadFromString(str));
}