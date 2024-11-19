#include <gtest/gtest.h>
#include <RungeKuttaMethods/explicitRungeKutta.hpp>
#include <Core>
#include <cmath>

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
    auto initialState =typename CubicTime::State {1};
    auto endTime = typename CubicTime::Argument {2.1};
    auto solution = integrate<RK4Table, CubicTime>(initialState, endTime, step, cubicTimeRHS);
    
    ASSERT_EQ(solution.size(), 3);

    ASSERT_EQ(solution[0].state, initialState);
    ASSERT_EQ(solution[0].arg, typename CubicTime::Argument {0});
    
    ASSERT_EQ(solution[1].state.size(), 1);
    ASSERT_NEAR(solution[1].state[0], 1.25, 1e-12);
    ASSERT_EQ(solution[1].arg, typename CubicTime::Argument {1});

    ASSERT_EQ(solution[2].state.size(), 1);
    ASSERT_NEAR(solution[2].state[0], 5, 1e-12);
    ASSERT_EQ(solution[2].arg, typename CubicTime::Argument {2});
}

TEST_F(IntegrationTest, HarmonicWorks) {
    auto initialState = typename Harmonic::State {13, 17};
    auto endTime = typename Harmonic::Argument {3.7};
    auto solution = integrate<RK4Table, Harmonic>(initialState, endTime, step, harmonicRHS);

    ASSERT_EQ(solution.size(), 4);

    ASSERT_EQ(solution[0].state, initialState);
    ASSERT_EQ(solution[0].arg, typename Harmonic::Argument {0});

    ASSERT_EQ(solution[1].state.size(), 2);
    ASSERT_NEAR(solution[1].state[0], 15.625 + (double) 16.75 / 3, 1e-12);
    ASSERT_NEAR(solution[1].state[1], -1.625, 1e-12);
    ASSERT_EQ(solution[1].arg, typename Harmonic::Argument {1});
}