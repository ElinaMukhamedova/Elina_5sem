#include <array>
#include <vector>
#include <cmath>
#include "Exception.hpp"

template<typename RealType, unsigned int N, typename Callable>
std::vector<std::array<RealType, N>> solve(
    const Callable& func,
    const std::array<RealType, N> initialGuess,
    const RealType tol,
    const unsigned int nIteration) {
        std::vector<std::array<RealType, N>> approximations;
        std::array<RealType, N> v_prev = initialGuess;
        approximations.push_back(v_prev);
        std::array<RealType, N> v;
        bool solution_found = false;
        unsigned int i = 0;
        double delta;
        while (solution_found == false && i < nIteration) {
            delta = 0;
            for (unsigned int j = 0; j < N; ++j) {
                v[j] = func(v_prev)[j];
                delta += std::abs(v[j] - v_prev[j]);
            }
            approximations.push_back(v);
            if (delta <= tol)
                solution_found = true;
            v_prev = v;
            i += 1;
        }
        if (solution_found == false)
            throw Exception("solver failed to converge");
        return approximations;
    }