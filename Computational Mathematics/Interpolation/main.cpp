#include "newton_polynomial.hpp"
#include <iostream>
#include <cmath>

int main() {
    std::array<std::array<double, 2>, 6> endpoints_choice = {{ {0, 2}, {0, 1}, {0, 0.5}, {0, 0.25}, {0, 0.125}, {0, 0.0625} }};

    std::array<double, 3> even_points;
    int N = even_points.size();
    std::array<double, 3> values;
    for (std::array<double, 2> endpoints : endpoints_choice) {
        double delta = (endpoints[1] - endpoints[0]) / (N - 1);
        for (int i = 0; i < N; ++i) {
            double node = i * delta;
            even_points[i] = node;
            values[i] = std::exp(node);
        }
        NewtonInterpolant<double, double, 3> D = NewtonInterpolant<double, double, 3>{even_points, values};
        std::array<double, 100> x_plot;
        std::array<double, 100> y_plot;
        delta = (endpoints[1] - endpoints[0]) / 99;
        for (int i = 0; i < 100; ++i) {
            double node = i * delta;
            x_plot[i] = node;
            y_plot[i] = D.predict(node);
        }
        std::cout << "Input data" << std::endl;
        for (int i = 0; i < N; ++i) {
            std::cout << "  x" + std::to_string(i) + " = " << even_points[i]
            << "    f(x" + std::to_string(i) + ") = " << values[i] << std::endl;
        }
        std::cout << "Interpolated data" << std::endl;
        for (int i = 0; i < 100; ++i) {
            std::cout << "  x" + std::to_string(i) + " = " << x_plot[i]
            << "    y(x" + std::to_string(i) + ") = " << y_plot[i] << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}