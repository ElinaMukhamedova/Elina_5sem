#include "gaussLegendre.hpp"
#include <cmath>
#include <iostream>
#include <math.h>

int main() {
    const std::function<double(double)>& f_sin = (double(*)(double)) std::sin;
    //std::cout << f_sin(M_PI / 2) << std::endl;
    decltype(auto) integral = integrate<std::function<double(double)>, 13>(f_sin, 0.0, 10.0);
    std::cout << integral << std::endl;

    return 0;
}