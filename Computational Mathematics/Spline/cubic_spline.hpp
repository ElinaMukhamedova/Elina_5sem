#include <vector>
#include <type_traits>
#include <iostream>

template <typename Type>
class CubicSplineMatrix {
    std::vector<Type> edge_;
    std::vector<Type> diagonal_;
    public:
        CubicSplineMatrix(std::vector<Type> h){
            std::size_t n = h.size();
            for (std::size_t i = 0; i < n - 2; ++i) {
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
