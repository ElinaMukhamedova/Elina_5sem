#include "gaussLegendre.hpp"
#include <cmath>
#include <iostream>
#include <math.h>

double s(const double x) {return std::sin(x);}

int main() {
    const auto sin =[](const double x) {return std::sin(x);};
    decltype(auto) integral_30 = integrate<30>(s, 0.0, 10.0);
    std::cout << integral_30 << std::endl;

    decltype(auto) integral_1 = integrate<1>(s, 0.0, 10.0);
    std::cout << std::abs(integral_30 - integral_1) << std::endl;

    decltype(auto) integral_2 = integrate<2>(s, 0.0, 10.0);
    std::cout << std::abs(integral_30 - integral_2) << std::endl;

    decltype(auto) integral_3 = integrate<3>(s, 0.0, 10.0);
    std::cout << std::abs(integral_30 - integral_3) << std::endl;

    decltype(auto) integral_4 = integrate<4>(s, 0.0, 10.0);
    std::cout << std::abs(integral_30 - integral_4) << std::endl;

    decltype(auto) integral_5 = integrate<5>(s, 0.0, 10.0);
    std::cout << std::abs(integral_30 - integral_5) << std::endl;

    decltype(auto) integral_6 = integrate<6>(s, 0.0, 10.0);
    std::cout << std::abs(integral_30 - integral_6) << std::endl;

    decltype(auto) integral_7 = integrate<7>(s, 0.0, 10.0);
    std::cout << std::abs(integral_30 - integral_7) << std::endl;

    decltype(auto) integral_8 = integrate<8>(s, 0.0, 10.0);
    std::cout << std::abs(integral_30 - integral_8) << std::endl;

    decltype(auto) integral_9 = integrate<9>(s, 0.0, 10.0);
    std::cout << std::abs(integral_30 - integral_9) << std::endl;

    decltype(auto) integral = integrate<4>(s, 0.0, 10.0, 10.0);
    std::cout << integral << std::endl;

    for (int i = 1; i <= 10; ++i){
        decltype(auto) integral = integrate<4>(s, 0.0, 10.0, (double)(10.0 / i));
        std::cout << std::abs(integral_30 - integral) << std::endl;
        //std::cout << (double)(10.0 / i) << std::endl;
    }
    for (int i = 1; i <= 10; ++i){
        decltype(auto) integral = integrate<3>(s, 0.0, 10.0, (double)(10.0 / i));
        std::cout << std::abs(integral_30 - integral) << std::endl;
        //std::cout << (double)(10.0 / i) << std::endl;
    }

    return 0;
}