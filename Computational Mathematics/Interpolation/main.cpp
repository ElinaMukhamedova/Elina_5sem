#include "newton_polynomial.hpp"
#include <iostream>
#include <cmath>

int main() {
    std::array<std::array<double, 2>, 6> endpoints_choice = {{ {0, 2}, {0, 1}, {0, 0.5}, {0, 0.25}, {0, 0.125}, {0, 0.0625} }};

    std::array<double, 3> even_points;
    int N = 3;
    std::array<double, 3> values;
    std::array<double, 6> errors_for_3_nodes; 
    for (int range_i = 0; range_i < 6; ++range_i) {
        std::array<double, 2> endpoints = endpoints_choice[range_i];
        double delta = (endpoints[1] - endpoints[0]) / (N - 1);
        for (int i = 0; i < N; ++i) {
            double node = i * delta;
            even_points[i] = node;
            values[i] = std::exp(node);
        }
        NewtonInterpolant<double, double, 3> D = NewtonInterpolant<double, double, 3>{even_points, values};
        std::array<double, 1000> x_plot;
        std::array<double, 1000> y_plot;
        double max_error = 0;
        delta = (endpoints[1] - endpoints[0]) / 999;
        for (int i = 0; i < 1000; ++i) {
            double node = i * delta;
            x_plot[i] = node;
            double y_predict = D.predict(node);
            y_plot[i] = y_predict;
            double error = std::abs(y_predict - std::exp(node));
            if (error > max_error)
                max_error = error;
        }
        errors_for_3_nodes[range_i] = max_error;
        //std::cout << "Input data" << std::endl;
        //for (int i = 0; i < N; ++i) {
        //    std::cout << "  x" + std::to_string(i) + " = " << even_points[i]
        //    << "    f(x" + std::to_string(i) + ") = " << values[i] << std::endl;
        //}
        //std::cout << "Interpolated data" << std::endl;
        //for (int i = 0; i < 1000; ++i) {
        //    std::cout << "  x" + std::to_string(i) + " = " << x_plot[i]
        //    << "    y(x" + std::to_string(i) + ") = " << y_plot[i] << std::endl;
        //}
        //std::cout << std::endl;
        //for (int i = 0; i < 1000; ++i)
        //    std::cout << x_plot[i] << ", ";
        //std::cout << std::endl;
        //for (int i = 0; i < 1000; ++i)
        //    std::cout << y_plot[i] << ", ";
        //std::cout << std::endl;
    }
    for (int range_i = 0; range_i < 6; ++range_i)
        std::cout << errors_for_3_nodes[range_i] << ", ";
    std::cout << std::endl;

    std::array<double, 4> even_points_4;
    N = 4;
    std::array<double, 4> values_4;
    std::array<double, 6> errors_for_4_nodes; 
    for (int range_i = 0; range_i < 6; ++range_i) {
        std::array<double, 2> endpoints = endpoints_choice[range_i];
        double delta = (endpoints[1] - endpoints[0]) / (N - 1);
        for (int i = 0; i < N; ++i) {
            double node = i * delta;
            even_points_4[i] = node;
            values_4[i] = std::exp(node);
        }
        NewtonInterpolant<double, double, 4> D_4 = NewtonInterpolant<double, double, 4>{even_points_4, values_4};
        std::array<double, 1000> x_plot;
        std::array<double, 1000> y_plot;
        double max_error = 0;
        delta = (endpoints[1] - endpoints[0]) / 999;
        for (int i = 0; i < 1000; ++i) {
            double node = i * delta;
            x_plot[i] = node;
            double y_predict = D_4.predict(node);
            y_plot[i] = y_predict;
            double error = std::abs(y_predict - std::exp(node));
            if (error > max_error)
                max_error = error;
        }
        errors_for_4_nodes[range_i] = max_error;
    }
    for (int range_i = 0; range_i < 6; ++range_i)
        std::cout << errors_for_4_nodes[range_i] << ", ";
    std::cout << std::endl;

    std::array<double, 5> even_points_5;
    N = 5;
    std::array<double, 5> values_5;
    std::array<double, 6> errors_for_5_nodes; 
    for (int range_i = 0; range_i < 6; ++range_i) {
        std::array<double, 2> endpoints = endpoints_choice[range_i];
        double delta = (endpoints[1] - endpoints[0]) / (N - 1);
        for (int i = 0; i < N; ++i) {
            double node = i * delta;
            even_points_5[i] = node;
            values_5[i] = std::exp(node);
        }
        NewtonInterpolant<double, double, 5> D_5 = NewtonInterpolant<double, double, 5>{even_points_5, values_5};
        std::array<double, 1000> x_plot;
        std::array<double, 1000> y_plot;
        double max_error = 0;
        delta = (endpoints[1] - endpoints[0]) / 999;
        for (int i = 0; i < 1000; ++i) {
            double node = i * delta;
            x_plot[i] = node;
            double y_predict = D_5.predict(node);
            y_plot[i] = y_predict;
            double error = std::abs(y_predict - std::exp(node));
            if (error > max_error)
                max_error = error;
        }
        errors_for_5_nodes[range_i] = max_error;
    }
    for (int range_i = 0; range_i < 6; ++range_i)
        std::cout << errors_for_5_nodes[range_i] << ", ";
    std::cout << std::endl;

    ////////////////////////////////
    N = 3;
    std::array<double, 3> chebyshev_points_3;
    std::array<double, 3> chebyshev_values_3;
    std::array<double, 6> errors_for_3_chebyshev_nodes; 
    for (int range_i = 0; range_i < 6; ++range_i) {
        std::array<double, 2> endpoints = endpoints_choice[range_i];
        chebyshev_points_3 = chebyshev_nodes<double, 2>(endpoints[0], endpoints[1]);
        for (int i = 0; i < N; ++i) {
            chebyshev_values_3[i] = std::exp(chebyshev_points_3[i]);
        }
        NewtonInterpolant<double, double, 3> C_3 = NewtonInterpolant<double, double, 3>{chebyshev_points_3, chebyshev_values_3};
        std::array<double, 1000> x_plot;
        std::array<double, 1000> y_plot;
        double max_error = 0;
        double delta = (endpoints[1] - endpoints[0]) / 999;
        for (int i = 0; i < 1000; ++i) {
            double point = i * delta;
            x_plot[i] = point;
            double y_predict = C_3.predict(point);
            y_plot[i] = y_predict;
            double error = std::abs(y_predict - std::exp(point));
            if (error > max_error)
                max_error = error;
        }
        errors_for_3_chebyshev_nodes[range_i] = max_error;
    }
    for (int range_i = 0; range_i < 6; ++range_i)
        std::cout << errors_for_3_chebyshev_nodes[range_i] << ", ";
    std::cout << std::endl;

    N = 4;
    std::array<double, 4> chebyshev_points_4;
    std::array<double, 4> chebyshev_values_4;
    std::array<double, 6> errors_for_4_chebyshev_nodes; 
    for (int range_i = 0; range_i < 6; ++range_i) {
        std::array<double, 2> endpoints = endpoints_choice[range_i];
        chebyshev_points_4 = chebyshev_nodes<double, 3>(endpoints[0], endpoints[1]);
        for (int i = 0; i < N; ++i) {
            chebyshev_values_4[i] = std::exp(chebyshev_points_4[i]);
        }
        NewtonInterpolant<double, double, 4> C_4 = NewtonInterpolant<double, double, 4>{chebyshev_points_4, chebyshev_values_4};
        std::array<double, 1000> x_plot;
        std::array<double, 1000> y_plot;
        double max_error = 0;
        double delta = (endpoints[1] - endpoints[0]) / 999;
        for (int i = 0; i < 1000; ++i) {
            double point = i * delta;
            x_plot[i] = point;
            double y_predict = C_4.predict(point);
            y_plot[i] = y_predict;
            double error = std::abs(y_predict - std::exp(point));
            if (error > max_error)
                max_error = error;
        }
        errors_for_4_chebyshev_nodes[range_i] = max_error;
    }
    for (int range_i = 0; range_i < 6; ++range_i)
        std::cout << errors_for_4_chebyshev_nodes[range_i] << ", ";
    std::cout << std::endl;

    N = 5;
    std::array<double, 5> chebyshev_points_5;
    std::array<double, 5> chebyshev_values_5;
    std::array<double, 6> errors_for_5_chebyshev_nodes; 
    for (int range_i = 0; range_i < 6; ++range_i) {
        std::array<double, 2> endpoints = endpoints_choice[range_i];
        chebyshev_points_5 = chebyshev_nodes<double, 4>(endpoints[0], endpoints[1]);
        for (int i = 0; i < N; ++i) {
            chebyshev_values_5[i] = std::exp(chebyshev_points_5[i]);
        }
        NewtonInterpolant<double, double, 5> C_5 = NewtonInterpolant<double, double, 5>{chebyshev_points_5, chebyshev_values_5};
        std::array<double, 1000> x_plot;
        std::array<double, 1000> y_plot;
        double max_error = 0;
        double delta = (endpoints[1] - endpoints[0]) / 999;
        for (int i = 0; i < 1000; ++i) {
            double point = i * delta;
            x_plot[i] = point;
            double y_predict = C_5.predict(point);
            y_plot[i] = y_predict;
            double error = std::abs(y_predict - std::exp(point));
            if (error > max_error)
                max_error = error;
        }
        errors_for_5_chebyshev_nodes[range_i] = max_error;
    }
    for (int range_i = 0; range_i < 6; ++range_i)
        std::cout << errors_for_5_chebyshev_nodes[range_i] << ", ";
    std::cout << std::endl;

    return 0;
}