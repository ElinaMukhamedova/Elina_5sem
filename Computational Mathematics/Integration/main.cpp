#include "gaussLegendre.hpp"
#include <cmath>
#include <iostream>

int main() {
    std::function<double(double)> f_sin = (double(*)(double))& std::sin;
    decltype(auto) integral = integrate<std::function<double(double)>, 13>(f_sin, 0.0, 10.0);
    std::cout << integral << std::endl;

    return 0;
}