#include "IterationMethod.hpp"
#include <iostream>
#include <cmath>

double func(const double x) {return x*x + std::tan(x)*std::tan(x) - 1;}

int main() {
    decltype(auto) x_negative = solve<double>(func, -0.2, -0.8, 3);
    decltype(auto) x_positive = solve<double>(func, 0.2, 0.8, 3);
    std::cout << "x_positive = " << x_positive << "   x_negative = " << x_negative << std::endl;
    std::cout << "func(x_positive) = " << func(x_positive) << "   func(x_negative) = " << func(x_negative) << std::endl;

    return 0;

}