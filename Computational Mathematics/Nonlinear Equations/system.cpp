#include "SystemIteration.hpp"
#include <iostream>
#include <cmath>
#include <array>
#include <vector>

std::array<double, 2> func_1(std::array<double, 2> v) {
    double x = v[0];
    double y = v[1];
    return std::array<double, 2> {std::atan(y), std::sqrt(1-x*x)};
}

std::array<double, 2> func_2(std::array<double, 2> v) {
    double x = v[0];
    double y = v[1];
    return std::array<double, 2> {std::atan(y), -std::sqrt(1-x*x)};
}

int main() {
    std::vector<std::array<double, 2>> v_1 = solve<double, 2>(func_1, {0.6, 0.8}, 1e-6, 50);
    unsigned int n1 = v_1.size();
    double x1_star = v_1[n1 - 1][0], y1_star = v_1[n1 - 1][1];
    std::vector<double> log10_errors_1;
    for (int i = 0; i < n1; ++i) {
        log10_errors_1.push_back(std::log10(std::sqrt((x1_star - v_1[i][0])*(x1_star - v_1[i][0]) + (y1_star - v_1[i][1])*(y1_star - v_1[i][1]))));
    }

    for (double err : log10_errors_1)
        std::cout << err << ", ";
    std::cout << std::endl;

    std::vector<std::array<double, 2>> v_2 = solve<double, 2>(func_2, {-0.6, -0.8}, 1e-6, 50);
    unsigned int n2 = v_2.size();
    double x2_star = v_2[n2 - 1][0], y2_star = v_2[n2 - 1][1];
    std::vector<double> log10_errors_2;
    for (int i = 0; i < n2; ++i) {
        log10_errors_2.push_back(std::log10(std::sqrt((x2_star - v_2[i][0])*(x2_star - v_2[i][0]) + (y2_star - v_2[i][1])*(y2_star - v_2[i][1]))));
    }

    for (double err : log10_errors_2)
        std::cout << err << ", ";
    std::cout << std::endl;

    std::cout << "x_positive = " << x1_star << "   " << "y_positive = "  << y1_star << std::endl;  
    std::cout << "x_negative = " << v_2[n2 - 1][0] << "   " << "y_negative = " << v_2[n2 - 1][1] << std::endl;

    return 0;

}