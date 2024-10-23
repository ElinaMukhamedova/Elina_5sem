#include <vector>
#include <type_traits>

template <typename Type>
class CubicSplineMatrix {
    const std::vector<Type> edge_;
    const std::vector<Type> diagonal_;
    public:
        CubicSplineMatrix(std::vector<Type> h){
            std::size_t n = h.size()
            std::vector<Type> edge_(n - 2);
            std::vector<Type> diagonal_(n - 1);
            for (std::size_t i = 0; i < n - 2; ++i) {
                edge_[i] = h[i + 1];
                diagonal_[i] = 2 * (h[i] + h[i + 1]);
            }
            diagonal_[n - 2] = h[n - 2] + h[n - 1];
        }
        const std::vector<Type> getEdge_() {return edge_;}
        const std::vector<Type> getDiagonal_() {return diagonal_;}
};

template <typename numeratorType, typename denominatorType>
using DivisionType  = decltype(std::declval<numeratorType>() / std::declval<denominatorType>());

template <typename Type>
using DifferenceType  = decltype(std::declval<Type>() / std::declval<Type>());

template <typename mType, typename cType>
std::vector<DivisionType<cType, mType>> solve(
    const CubicSplineMatrix<mType>& matrix,
    const std::vector<cType>& column){
        
    }