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
    Interpolant(const std::vector<xType>& nodes, const std::vector<yType>& values) {
        std::size_t nodesSize = nodes.size();
        std::size_t valuesSize = values.size();
        std::size_t N = valuesSize >= nodesSize ? nodesSize : valuesSize;
        for (std::size_t i = 0; i < N; ++i) {
            nodes_.push_back(nodes[i]);
            values_.push_back(values[i]);
        }
    }
    yType evaluate(xType x) const {
        auto iter = std::lower_bound(nodes_.begin(), nodes_.end(), x);
        int index = iter - nodes_.begin();

        const bool singleNode = nodes_.size() == 1;
        const int fixer = singleNode ? 1 : 0;

        const bool condition = index != 0;
        xType a = condition ? nodes_[index - 1] : nodes_[0];
        xType b = condition ? *iter : nodes_[1 - fixer];
        yType value_a = condition ? values_[index - 1] : values_[0];
        yType value_b = condition ? values_[index] : values_[1 - fixer];

        double slope = singleNode ? 0 : (value_b - value_a) / (b - a);
        return slope * (x - a) + value_a;
    }
};