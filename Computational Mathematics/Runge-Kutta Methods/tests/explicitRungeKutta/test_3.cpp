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
    double endTime = 2.1;
    auto solution = integrate<RK4Table, CubicTime>(initialState, endTime, step, cubicTimeRHS);
    
    ASSERT_EQ(solution.size(), 3);
    ASSERT_EQ(cubicTimeRHS.dim, 1);

    ASSERT_EQ(solution[0].state, typename CubicTime::State {1});
    ASSERT_EQ(solution[0].arg, typename CubicTime::Argument {0});
    
    ASSERT_NEAR(solution[1].state[0], 1.25, 1e-12);
    ASSERT_EQ(solution[1].arg, typename CubicTime::Argument {1});

    ASSERT_NEAR(solution[2].state[0], 5, 1e-12);
    ASSERT_EQ(solution[2].arg, typename CubicTime::Argument {2});
}