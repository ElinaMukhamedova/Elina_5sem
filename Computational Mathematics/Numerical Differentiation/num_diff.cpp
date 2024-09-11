#include <array>
#include <iostream>

template<typename RealType, unsigned int N>
struct DerivativeCoef {
    RealType centralCoef_;
    std::array<RealType, N> otherCoefs_;

    DerivativeCoef(RealType centralCoef, std::array<RealType, N> otherCoefs) {
        centralCoef_ = centralCoef; otherCoefs_ = otherCoefs;
    }
};

template<typename RealType, unsigned int N>
std::array<std::array<RealType, N + 1>, N> createMatrix(const std::array<RealType, N>& points) {
    std::array<RealType, N + 1> alpha;
    for (int i = 0; i != N; ++i)
        alpha[i] = points[i];
    alpha[N] = 0;
    std::array<std::array<RealType, N + 1>, N> matr;
    matr.fill(alpha);
    for (int i = N - 2; i >= 0; --i)
        for (int j = 0; j != N + 1; ++j)
            matr[i][j] = matr[i + 1][j] * alpha[j] / (N - i);
    matr[N - 1][N] = 1;
    return matr;
}

template<typename RealType, unsigned int N>
DerivativeCoef<RealType, N> calcDerivativeCoef(const std::array<RealType, N>& points) {
    auto matr = createMatrix<RealType, N>(points);
    for (int n = 0; n != N; ++n)                 // convert matr to upper triangular
        for (int i = n + 1; i != N; ++i) {
            double k = matr[i][n] / matr[n][n];
            for (int j = 0; j != N + 1; ++j)
                matr[i][j] -= k * matr[n][j];
        }
    for (int i = 0; i != N; ++i) {               // make diagonal elements all equal to 1
        double pivot = matr[i][i];
        for (int j = i; j != N + 1; ++j)
            matr[i][j] = matr[i][j] / pivot;
    }
    for (int n = 0; n != N; ++n)                 // by going top-to-bottom 'clean-up' the matrix,
        for (int i = n + 1; i != N; ++i) {       // id est get rid of everything above the diagonal
            double k = matr[n][i];               // <=> convert to identity matrix
            for (int j = i; j != N + 1; ++j)
                matr[n][j] -= k * matr[i][j];
        }
    std::array<RealType, N> otherCoefs;
    RealType centralCoef = 0;
    for (int i = 0; i != N; ++i) {
        auto k = matr[i][N];
        otherCoefs[i] = k;
        centralCoef -= k;
    }
    return DerivativeCoef<RealType, N>(centralCoef, otherCoefs);
}

int main() {
    std::array<double, 3> points = {1, 2, 3};
    auto answer = calcDerivativeCoef<double, 3>(points);
    std::cout << "A_0 * h = " << answer.centralCoef_ << std::endl;
    int N = answer.otherCoefs_.size();
    for (int i = 0; i != N; ++i)
        std::cout << "A_" << i + 1 << " * h = " << answer.otherCoefs_[i] << std::endl;
    
    return 0;
}