#include "DoubleSin.hpp"
#include "calculator/Calculator.hpp"

namespace DoubleSin {
    double calcDoubleSin(double x) {
        return 2 * Calculator::calcSin(x) * Calculator::calcCos(x);
    }
}