#include <vector>
#include <type_traits>
#include <iostream>
#include <cmath>

template <typename Type>
class CubicSplineMatrix {
    std::vector<Type> edge_;
    std::vector<Type> diagonal_;
    
    public:
        CubicSplineMatrix(std::vector<Type> h){
            std::size_t n = h.size();
            for (std::size_t i = 0; i < n - 1; ++i) {
                edge_.push_back(h[i + 1]);
                diagonal_.push_back(2 * (h[i] + h[i + 1]));
            }
            diagonal_.push_back(2 * (h[n - 2] + h[n - 1]));
        }
        std::vector<Type> getEdge_() const {return edge_;}
        std::vector<Type> getDiagonal_() const {return diagonal_;}
};

template <typename numeratorType, typename denominatorType>
using DivisionType  = decltype(std::declval<numeratorType>() / std::declval<denominatorType>());

template <typename Type>
using DifferenceType  = decltype(std::declval<Type>() - std::declval<Type>());

template <typename mType, typename cType>
std::vector<DivisionType<cType, mType>> inner_second_derivatives (
    const CubicSplineMatrix<mType>& matrix,
    const std::vector<cType>& column) {
        std::vector<mType> a = matrix.getDiagonal_();
        std::vector<mType> b = matrix.getEdge_();
        
        std::size_t k = column.size();
        std::vector<mType> m(k - 1);
        std::vector<cType> d(k - 1);
        m[0] = b[0] / a[0];
        d[0] = column[0] / a[0];
        for (std::size_t i = 1; i < k - 1; ++i) {
            m[i] = b[i] / (a[i] - m[i - 1] * b[i - 1]);
            d[i] = (column[i] - d[i - 1] * b[i - 1]) / (a[i] - m[i - 1] * b[i - 1]);
        }
        std::vector<DivisionType<cType, mType>> z(k);
        z[k - 1] = (column[k - 1] - d[k - 2] * b[k - 2]) / (a[k - 1] - m[k - 2] * b[k - 2]);
        for (int i = k - 2; i >= 0; --i) {
            z[i] = d[i] - m[i] * z[i + 1];
        }
        return z;
    }

template <typename xType, typename yType>
class CubicSpline{

    using DeltaXType = DifferenceType<xType>;
    using DerivativeType = DivisionType<DifferenceType<yType>, DeltaXType>;
    using SecondDerivativeType = DivisionType<DifferenceType<DerivativeType>, DeltaXType>;

    std::vector<xType> nodes_;
    std::vector<yType> values_;
    std::vector<DeltaXType> steps_;
    std::vector<SecondDerivativeType> second_derivatives_;

    public:
        CubicSpline(
            const std::vector<xType>& nodes,
            const std::vector<yType>& values
            ) : nodes_(nodes), values_(values){
                int n = nodes.size() - 1;
                steps_.push_back(nodes[1] - nodes[0]);
                std::vector<DerivativeType> b;
                b.push_back((values[1] - values[0]) / steps_[0]);
                std::vector<DerivativeType> u;
                for (int i = 1; i < n; ++i) {
                    steps_.push_back(nodes[i + 1] - nodes[i]);
                    b.push_back((values[i + 1] - values[i]) / steps_[i]);
                    u.push_back(6 * (b[i] - b[i - 1]));
                }
                CubicSplineMatrix<DeltaXType> matrix = CubicSplineMatrix<DeltaXType>(steps_);
                std::vector<SecondDerivativeType> z_inner = inner_second_derivatives<DeltaXType, DerivativeType>(matrix, u);
                second_derivatives_.push_back(0);
                for (SecondDerivativeType z : z_inner) {
                    second_derivatives_.push_back(z);
                }
                second_derivatives_.push_back(0);
            }
        
        std::vector<DeltaXType> getSteps(){
            return steps_;
        }

        yType interpolate(const xType& x) {
            int k;
            int N = nodes_.size();
            for (int i = 0; i < N - 1; ++i)
                if (x >= nodes_[i] && x <= nodes_[i + 1])
                    k = i;
            return std::pow(x-nodes_[k], 3) * second_derivatives_[k+1]/(6*steps_[k]) +
                    std::pow(nodes_[k + 1]-x, 3) * second_derivatives_[k]/(6*steps_[k]) +
                    (x - nodes_[k]) * (values_[k+1]/steps_[k] - second_derivatives_[k+1]*steps_[k]/6) +
                    (nodes_[k+1] - x) * (values_[k]/steps_[k] - second_derivatives_[k]*steps_[k]/6);
        }
};