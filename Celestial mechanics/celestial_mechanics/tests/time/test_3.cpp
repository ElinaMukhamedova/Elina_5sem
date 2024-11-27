#include <gtest/gtest.h>
#include "celestial_mechanics/Interpolation.hpp"
#include "celestial_mechanics/time/DutContainer.hpp"
#include "tests/Paths.hpp"
#include <vector>

class InterpolationTest : public testing::Test {
    protected:
    std::vector<double> nodes;
    std::vector<double> values;
    std::size_t N;
    Interpolant<double, double> interpolant;
    std::vector<double> midpoints;
    std::vector<double> values_midpoints;
    void SetUp() {
        nodes = {1, 3, 5, 7, 9, 11, 13};
        values = {3, 7, 11, 15, 19, 23, 27};
        N = nodes.size();
        interpolant = Interpolant(nodes, values);
        midpoints = {2, 4, 6, 8, 10, 12};
        values_midpoints = {5, 9, 13, 17, 21, 25};
    }
};

TEST_F(InterpolationTest, InterpolationAtNodesWorks) {
    for (std::size_t i = 0; i < N; ++i)
        EXPECT_NEAR(interpolant.evaluate(nodes[i]), values[i], 1e-12);
}

TEST_F(InterpolationTest, InterpolationAtMidpointsWorks) {
    for (std::size_t i = 0; i < N - 1; ++i)
        EXPECT_NEAR(interpolant.evaluate(midpoints[i]), values_midpoints[i], 1e-12);
}