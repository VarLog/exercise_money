#include "gtest/gtest.h"

#include "money/money.h"

TEST(SumTest, Test1) {
    auto denoms = money::getDenominators(10);
    EXPECT_EQ(20, money::calculateSum(10, denoms));
}

