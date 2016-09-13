#include "gtest/gtest.h"

#include "money/money.h"

TEST(DevideTest, Test1) {
    auto denoms = money::getDenominators(10);
    EXPECT_TRUE(money::isDivisible(10, 2, denoms));
}

