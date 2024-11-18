#include <gtest/gtest.h>
#include <RungeKuttaMethods/classicRungeKutta.hpp>
#include <Core>
#include <cmath>

TEST(rhsTest, CubicTimeWorks){
    CubicTime cubicTimeRHS;
    CubicTime::StateAndArg stateAndArg_13{Eigen::Vector<double, 1>{13}, 0.7};
    CubicTime::StateAndArg stateAndArg_17{Eigen::Vector<double, 1>{17}, 0.3};
    auto rhs_13 = cubicTimeRHS.calc(stateAndArg_13);
    auto rhs_17 = cubicTimeRHS.calc(stateAndArg_17);
    ASSERT_NEAR(rhs_13[0], std::pow(0.7, 3), 1e-12);
    ASSERT_NEAR(rhs_17[0], std::pow(0.3, 3), 1e-12);
    ASSERT_TRUE(rhs_13.size() == 1);
    ASSERT_TRUE(rhs_17.size() == 1);
}

TEST(rhsTest, HarmonicWorks) {
    Harmonic harmonicRHS;
    Harmonic::StateAndArg stateAndArg_1{Eigen::Vector<double, 2>{13, 17}, 0.7};
    Harmonic::StateAndArg stateAndArg_2{Eigen::Vector<double, 2>{21, 13}, 0.3};
    auto rhs_1 = harmonicRHS.calc(stateAndArg_1);
    auto rhs_2 = harmonicRHS.calc(stateAndArg_2);
    ASSERT_TRUE(rhs_1.size() == 2);
    ASSERT_TRUE(rhs_2.size() == 2);
    ASSERT_EQ(rhs_1[0], 17);
    ASSERT_EQ(rhs_1[1], -13);
    ASSERT_EQ(rhs_2[0], 13);
    ASSERT_EQ(rhs_2[1], -21);
}