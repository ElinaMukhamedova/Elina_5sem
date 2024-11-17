#include <gtest/gtest.h>
#include <RungeKuttaMethods/classicRungeKutta.hpp>
#include <Core>
#include <cmath>

TEST(CubicTimeTest, rhsWorks){
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