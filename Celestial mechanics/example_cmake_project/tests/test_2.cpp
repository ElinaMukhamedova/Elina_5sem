#include <double_sin/DoubleSin.hpp>
#include <complex>
#include <iostream>

const double deg = M_PI / 180;

int main() {


    const double doub = DoubleSin::calcDoubleSin(10 * deg);
    const double ref = std::sin(20 * deg);

    if (std::abs(doub - ref) > 1e-14 ) {
        std::cerr << "Тест 2 не пройден" << std::endl;
    }

}
