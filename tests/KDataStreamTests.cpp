#include <gtest/gtest.h>

#include <KDIS/KDataStream.hpp>
#include <KDIS/KDefines.hpp>

TEST(KDataStream, KConversions) {
  KDIS::KDataStream stream;
  EXPECT_NO_THROW(stream.GetBufferSize());
  EXPECT_THROW(stream.CopyIntoBuffer(nullptr, 0, 5), KDIS::KException);
  EXPECT_NO_THROW(stream.GetBufferPtr());
}