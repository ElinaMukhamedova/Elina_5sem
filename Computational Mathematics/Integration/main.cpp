#include "gaussLegendre.hpp"
#include <cmath>
#include <iostream>
#include <math.h>

double s(const double x) {return std::sin(x);}

int main() {
    const auto sin =[](const double x) {return std::sin(x);};
    //std::cout << f_sin(M_PI / 2) << std::endl;
    decltype(auto) integral = integrate<13>(s, 0.0, 10.0);
    std::cout << integral << std::endl;

    return 0;
}