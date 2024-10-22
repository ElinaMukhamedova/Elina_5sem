#include <array>
#include <iostream>
#include <cmath>
#include <math.h>

template<typename xType, typename yType, unsigned int N>
class NewtonInterpolant {

    std::array<xType, N> points_;
    std::array<yType, N> alpha_;

    public:
    NewtonInterpolant(const std::array<xType, N>& points, const std::array<yType, N>& values) : points_(points), alpha_(values){

        for (int i = 0; i < N; ++i) {
            for (int j = N - 1; j > i; --j)
                alpha_[j] = (alpha_[j] - alpha_[j - 1]) / (points_[j] - points_[j - i - 1]);
        }
    }
    yType evaluate(const xType& x) const {
        yType ans = alpha_[N - 1];
        for (int i = N - 1; i > 0; --i) {
            ans = ans * (x - points_[i - 1]) + alpha_[i - 1];
        }
        return ans;
    }
};

template<typename xType, unsigned int N>
std::array<xType, N + 1> chebyshev_nodes(xType a, xType b) {
    xType centre_point = 0.5 * (a + b);
    xType half_width = 0.5 * (b - a);
    std::array<xType, N + 1> nodes;
    for (int i = 0; i <= N; ++i)
        nodes[i] = centre_point + half_width * std::cos(M_PI * (2 * i + 1) / (2 * N + 2));
    return nodes;
}