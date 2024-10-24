#include "cubic_spline.hpp"
#include <iostream>

int main() {
    std::vector<double> h = {0.5, 0.5, 1, 1.5, 2};
    CubicSplineMatrix<double> matrix = CubicSplineMatrix<double> (h);
    std::vector<double> diagonal = matrix.getDiagonal_();
    std::vector<double> edge = matrix.getEdge_();
    for (auto&& elt : diagonal)
        std::cout << elt << ", ";
    std::cout << std::endl;
    for (auto&& elt : edge)
        std::cout << elt << ", ";
    std::cout << std::endl;

    std::vector<double> column = {7, 13, 17, 21};
    std::vector<double> z = inner_second_derivatives(matrix, column);
    for (auto&& elt : z)
        std::cout << elt << ", ";
    std::cout << std::endl;

    return 0;
}