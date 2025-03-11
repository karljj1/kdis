#include <gtest/gtest.h>

#include <KDIS/KDataStream.hpp>
#include <KDIS/KDefines.hpp>
#include <string>
#include <vector>

TEST(KDataStream, Buffer) {
  KDIS::KDataStream stream;
  EXPECT_NO_THROW(stream.GetBufferSize());
  // method rejects nullptr Buffer
  EXPECT_THROW(stream.CopyIntoBuffer(nullptr, 0, 5), KDIS::KException);
  std::vector<KDIS::KOCTET> buf(5);
  // method rejects WritePos bigger than BufferSize
  EXPECT_THROW(stream.CopyIntoBuffer(buf.data(), buf.size(), 7),
               KDIS::KException);
  for (int ii = 0; ii < 17; ++ii) {
    stream.Write(0);
  }
  // internal buffer is too big to be copied into the 2 available buffer slots
  EXPECT_THROW(stream.CopyIntoBuffer(buf.data(), buf.size(), 3),
               KDIS::KException);
  EXPECT_NO_THROW(stream.GetBufferPtr());
}

TEST(KDataStream, ReadFromString) {
  KDIS::KDataStream stream;
  std::string str{""};
  EXPECT_NO_THROW(stream.ReadFromString(str));
  str = "3g9reay9reag@#$$%^#$@${}";
  EXPECT_NO_THROW(stream.ReadFromString(str));
}