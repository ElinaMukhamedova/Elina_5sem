#include <array>
#include <iostream>

template<typename xType, typename yType, unsigned int N>
class NewtonInterpolant {

    std::array<xType, N> points_;
    std::array<yType, N> alpha_;

    public:
    NewtonInterpolant(const std::array<xType, N>& points, const std::array<yType, N>& values) : points_(points){
        std::array<yType, N> alpha = values;
        for (int i = 0; i < N; ++i) {
            for (int j = N - 1; j > i; --j)
                alpha[j] = (alpha[j] - alpha[j - 1]) / (points_[j] - points_[j - i - 1]);
        }
        alpha_ = alpha;
    }
    yType predict(const xType& x) const {
        yType ans = alpha_[N - 1];
        for (int i = N - 1; i > 0; --i) {
            ans = ans * (x - points_[i - 1]) + alpha_[i - 1];
        }
        return ans;
    }
};

template<typename xType, typename yType, unsigned int N>
class Plot {

    std::array<xType, N> x_data;
    std::array<yType, N> y_data;
    

};