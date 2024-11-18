#include <gtest/gtest.h>
#include <RungeKuttaMethods/explicitRungeKutta.hpp>
#include <Core>
#include <cmath>
#include <iostream>

class IntegrationTest : public testing::Test {
    protected:
        CubicTime cubicTimeRHS;
        Harmonic harmonicRHS;
        double step;
        void SetUp() {
            step = 1;
        }
};

TEST_F(IntegrationTest, CubicTimeWorks) {
    auto initialState = Eigen::Vector<double, 1> {1};
    double endTime = 2;
    auto solution = integrate<RK4Table, CubicTime>(initialState, endTime, step, cubicTimeRHS);
    std::cout << solution.size() << std::endl;
    ASSERT_EQ(solution.size(), 2);
}