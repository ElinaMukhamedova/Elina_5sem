#include "cubic_spline.hpp"
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::vector<int> N_choice = {5, 10, 20, 40, 80, 160};
    std::vector<std::vector<double>> nodes_choice(N_choice.size());
    std::vector<std::vector<double>> values_choice(N_choice.size());
    double a = 0;
    double b = 10;
    for (int i = 0; i < N_choice.size(); ++i) {
        int N = N_choice[i];
        std::vector<double> nodes(N);
        std::vector<double> values(N);
        double step = (b - a) / (N - 1);
        for (int j = 0; j < N; ++j){
            nodes[j] = a + j * step;
            values[j] = std::exp(nodes[j]);
        }
        nodes_choice[i] = nodes;
        values_choice[i] = values;
    }

    double step = (b - a) / 999;
    std::vector<double> errors;
    for (int i = 0; i < N_choice.size(); ++i) {
        double max_delta = -1;
        CubicSpline<double, double> spline = CubicSpline<double, double>(nodes_choice[i], values_choice[i]);
        for (int j = 0; j < 1000; ++j) {
            double delta = std::abs(spline.interpolate(a + step * j) - std::exp(a + step * j));
            if (delta > max_delta)
                max_delta = delta;    
        }
        errors.push_back(max_delta);
    }

    for (double elt : errors)
        std::cout << elt << ", ";

    std::cout << std::endl;
    
    CubicSpline<double, double> spline0 = CubicSpline<double, double>(nodes_choice[0], values_choice[0]);
    for (int j = 0; j < 1000; ++j) {
        std::cout << spline0.interpolate(a + step * j) << ", ";   
    }

    std::cout << std::endl;

    CubicSpline<double, double> spline5 = CubicSpline<double, double>(nodes_choice[5], values_choice[5]);
    for (int j = 0; j < 1000; ++j) {
        std::cout << spline5.interpolate(a + step * j) << ", ";   
    }

    return 0;
}