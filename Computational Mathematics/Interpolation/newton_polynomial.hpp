#include <array>
#include <iostream>

template<typename xType, typename yType, unsigned int N>
class NewtonInterpolant {

    std::array<yType, N> alpha_;
    std::array<xType, N> points_;

    public:
    NewtonInterpolant(const std::array<xType, N>& points, const std::array<yType, N>& values) : points_(points){
        std::array<yType, N> alpha = values;
        for (int i = 1; i < N; ++i) 
            if (points_[i] - points_[0] != 0)
                alpha[i] = (alpha[i] - alpha[i - 1]) / (points[i] - points[0]);
        alpha_ = alpha;
    }
    yType predict(const xType& x) const {
        yType ans = alpha_[N - 1];
        for (int i = N - 1; i > 0; --i)
            ans = ans * (x - points_[i]) + alpha_[i - 1];
        return ans;
    }
};
