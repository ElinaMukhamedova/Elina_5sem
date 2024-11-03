#include <vector>
#include <cmath>
#include <math.h>

template<typename xType, typename yType>
class NewtonInterpolant {

    std::vector<xType> nodes_;
    std::vector<yType> alpha_;
    std::size_t N_;

    public:
    NewtonInterpolant(const std::vector<xType>& nodes, const std::vector<yType>& values) : nodes_(nodes), alpha_(values), N_(values.size()){

        for (int i = 0; i < N_; ++i) {
            for (int j = N_ - 1; j > i; --j)
                alpha_[j] = (alpha_[j] - alpha_[j - 1]) / (nodes_[j] - nodes_[j - i - 1]);
        }
    }
    yType evaluate(const xType& x) const {
        yType ans = alpha_[N_ - 1];
        for (int i = N_ - 1; i > 0; --i) {
            ans = ans * (x - nodes_[i - 1]) + alpha_[i - 1];
        }
        return ans;
    }
};