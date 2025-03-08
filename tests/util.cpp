#include <gtest/gtest.h>

#include <KDIS/util/BoundedLengthString.hpp>
#include <string>

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