#include <gtest/gtest.h>
#include <BDF/BDF4.hpp>
#include <iostream>

TEST(BDF4test, CoefficientFillingWorks) {
    auto coefs = BDF4::alpha;
    std::cout << coefs[0] << std::endl;
    ASSERT_EQ(coefs[0], (double)11/6);
}