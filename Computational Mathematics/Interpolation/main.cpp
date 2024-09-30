#include "newton_polynomial.hpp"

int main() {
    std::array<double, 3> points{};
    int N = points.size();

    std::array<double, 2> endpoints = {0, 2};
    double delta = (endpoints[1] - endpoints[0]) / (N - 1);
    for (int i = 1; i < N; ++i)
        points[i] += i * delta;

    return 0;
}