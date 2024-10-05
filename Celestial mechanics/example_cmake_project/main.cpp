#include <iostream>
#include <cmath>

#include <double_sin/DoubleSin.hpp>
#include <calculator/Calculator.hpp>

const double deg = M_PI / 180;

int main() {

    std::cout << DoubleSin::calcDoubleSin(30 * deg) << std::endl;
    std::cout << Calculator::calcSin(60 * deg) << std::endl;

    return 0;
}