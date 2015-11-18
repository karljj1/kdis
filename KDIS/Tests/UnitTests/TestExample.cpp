#include <iostream>
#include "gtest/gtest.h"

//#include "project1.h"

// IndependentMethod is a test case - here, we have 2 tests for this 1 test case
TEST(IndependentMethod, ResetsToZero)
 {
	int i = 12;
	EXPECT_EQ(0,i);
}

// }  // namespace - could surround Project1Test in a namespace