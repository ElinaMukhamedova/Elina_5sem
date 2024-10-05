#include <double_sin/DoubleSin.hpp>
#include <cmath>

#include <gtest/gtest.h>


class SUITE_NAME : public ::testing::Test {
protected:

    double deg;

    void SetUp() override {

        deg = M_PI / 180;

    }

};

void foo(){
    throw std::runtime_error("fsdfsdf");
}

TEST_F(SUITE_NAME, COMP_60) {

    const double doub = DoubleSin::calcDoubleSin(30 * deg);
    const double ref = std::sin(60 * deg);
    ASSERT_NEAR(doub, ref, 1e-14);
    ASSERT_ANY_THROW(foo());
    ASSERT_THROW(foo(), std::runtime_error);

    ASSERT_NO_THROW(foo());
}


TEST_F(SUITE_NAME, COMP_30) {

    const double doub = DoubleSin::calcDoubleSin(15 * deg);
    const double ref = std::sin(30 * deg);
    ASSERT_NEAR(doub, ref, 1e-14);
}
