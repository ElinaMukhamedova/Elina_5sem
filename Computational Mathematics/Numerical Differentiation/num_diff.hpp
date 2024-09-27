#include <array>
#include <iostream>
#include <cmath>

template<typename RealType, unsigned int N>
struct DerivativeCoef {
    RealType centralCoef_;
    std::array<RealType, N> otherCoefs_;
};

template<typename RealType, unsigned int N>
struct logErrors {
    std::array<RealType, N> logSteps_;
    std::array<RealType, N> logCumulatedErrors_;
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
void transformSLE(std::array<std::array<RealType, N + 1>, N>& matr) {
    for (int n = 0; n != N; ++n) {                // convert matr to upper triangular
        bool flag = false;
        int k = n;
        if (matr[k][n] != 0)
            flag = true;
        else
            ++k;
        while (flag != true && k != N) {          // try to find the first row
            if (matr[k][n] != 0) {                // with nonzero n-th entry
                flag = true;                      // and swap it with the n-th row
                std::array<RealType, N + 1> copy = matr[k];
                matr[k] = matr[n];
                matr[n] = copy;
            }
            ++k;
        }
        if (k != N)                               // if there is no such raw,
            for (int i = n + 1; i != N; ++i) {    // just skip this step
                double k = matr[i][n] / matr[n][n];
                for (int j = 0; j != N + 1; ++j)
                    matr[i][j] -= k * matr[n][j];
            }
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
}

template<typename RealType, unsigned int N>
DerivativeCoef<RealType, N> calcDerivativeCoef(const std::array<RealType, N>& points) {
    std::array<std::array<RealType, N + 1>, N> matr = createMatrix<RealType, N>(points);
    transformSLE<RealType, N>(matr);
    std::array<RealType, N> otherCoefs;
    RealType centralCoef = 0;
    for (int i = 0; i != N; ++i) {
        auto k = matr[i][N];
        otherCoefs[i] = k;
        centralCoef -= k;
    }
    return {centralCoef, otherCoefs};
}

template<typename RealType, unsigned int N>
logErrors<RealType, N> errorAnalysis(RealType trueValue, std::array<RealType, N> answers, std::array<RealType, N> steps) {
    std::array<RealType, N> logErrors;
    std::array<RealType, N> logSteps;
    for (int i = 0; i != N; ++i) {
        logSteps[i] = std::log(steps[i]);
        logErrors[i] = std::log(std::abs(trueValue - answers[i]));
    }
    return {logSteps, logErrors};
}