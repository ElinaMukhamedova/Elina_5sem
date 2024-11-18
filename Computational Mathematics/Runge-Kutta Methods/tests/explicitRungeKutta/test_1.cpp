#include <gtest/gtest.h>
#include <RungeKuttaMethods/explicitRungeKutta.hpp>

class RK4TableTest : public testing::Test {
    protected:
        RK4Table table;
};

TEST_F(RK4TableTest, aTableFillingWorks) {
    auto aTable_ = table.aTable;
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

TEST_F(RK4TableTest, cColumnFillingWorks) {
    auto cColumn_ = table.cColumn;
    ASSERT_TRUE(cColumn_[0] == 0);
    ASSERT_TRUE(cColumn_[1] == 0.5);
    ASSERT_TRUE(cColumn_[2] == 0.5);
    ASSERT_TRUE(cColumn_[3] == 1);
}

TEST_F(RK4TableTest, bStringFillingWorks) {
    auto bString_ = table.bString;
    ASSERT_NEAR(bString_[0], (double)1/6, 1e-12);
    ASSERT_NEAR(bString_[1], (double)1/3, 1e-12);
    ASSERT_NEAR(bString_[2], (double)1/3, 1e-12);
    ASSERT_NEAR(bString_[3], (double)1/6, 1e-12);
}