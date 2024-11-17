#pragma once

#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>

template<typename xType, typename yType>
class Interpolant {

    std::vector<xType> nodes_;
    std::vector<yType> values_;

    public:
    Interpolant() {}
    Interpolant(const std::vector<xType>& nodes, const std::vector<yType>& values) : nodes_(nodes), values_(values){}
    yType evaluate(xType x) {
        auto iter = std::lower_bound(nodes_.begin(), nodes_.end(), x);
        int index = iter - nodes_.begin();
        const bool condition = index != 0;
        xType a = condition ? nodes_[index - 1] : nodes_[0];
        xType b = condition ? *iter : nodes_[1];
        yType value_a = condition ? values_[index - 1] : values_[0];
        yType value_b = condition ? values_[index] : values_[1];
        double slope = (value_b - value_a) / (b - a);
        return slope * (x - a) + value_a;
    }
};