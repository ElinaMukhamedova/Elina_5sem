#include <gtest/gtest.h>
#include <RungeKuttaMethods/explicitRungeKutta.hpp>

TEST(RK4TableTest, aTableFillingWorks) {
    auto aTable_ = RK4Table::aTable;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (j >= i || j <= i-2)
                ASSERT_TRUE(aTable_[i][j] == 0);
            else
                if (i == 3)
                    ASSERT_TRUE(aTable_[i][j] == 1);
                else
                    ASSERT_TRUE(aTable_[i][j] == 0.5);
}

TEST(RK4TableTest, cColumnFillingWorks) {
    auto cColumn_ = RK4Table::cColumn;
    ASSERT_TRUE(cColumn_[0] == 0);
    ASSERT_TRUE(cColumn_[1] == 0.5);
    ASSERT_TRUE(cColumn_[2] == 0.5);
    ASSERT_TRUE(cColumn_[3] == 1);
}

TEST(RK4TableTest, bStringFillingWorks) {
    auto bString_ = RK4Table::bString;
    ASSERT_NEAR(bString_[0], (double)1/6, 1e-12);
    ASSERT_NEAR(bString_[1], (double)1/3, 1e-12);
    ASSERT_NEAR(bString_[2], (double)1/3, 1e-12);
    ASSERT_NEAR(bString_[3], (double)1/6, 1e-12);
}