#include <array>
#include <iostream>
#include <cmath>
#include <numeric>

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
std::array<std::array<RealType, N>, N> createMatrix(const std::array<RealType, N>& points) {
    std::array<std::array<RealType, N>, N> matr;
    matr.fill(points);
    for (int i = N - 2; i >= 0; --i)
        for (int j = 0; j < N; ++j)
            matr[i][j] = matr[i + 1][j] * points[j] / (N - i);
    return matr;
}

template<typename RealType, unsigned int N>
void transformSLE(std::array<std::array<RealType, N>, N>& matr, std::array<RealType, N>& vect) {
    for (int col = 0, row = 0; col < N && row < N; ++col) {
        int sel_row = row;
        for (int i = row; i < N; ++i) {
            if (std::abs(matr[i][col]) > std::abs(matr[i][col]))
                sel_row = i;
        }
        if (std::abs(matr[sel_row][col]) != 0) {
            std::swap(matr[sel_row], matr[row]);
            std::swap(vect[sel_row], vect[row]);

            RealType pivot = matr[row][col];
            for (int j = 0; j < N; ++j)
                matr[row][j] = matr[row][j] / pivot;
            vect[row] = vect[row] / pivot;

            for (int i = 0; i < N; ++i) {
                RealType first = matr[i][col];
                if (i != row) {
                    for (int j = col; j < N; ++j)
                        matr[i][j] -= first * matr[row][j];
                    vect[i] -= first * vect[row];
                }
            }

            ++row;
        }
    }
}

template<typename RealType, unsigned int N>
DerivativeCoef<RealType, N> calcDerivativeCoef(const std::array<RealType, N>& points) {
    std::array<std::array<RealType, N>, N> matr = createMatrix<RealType, N>(points);
    std::array<RealType, N> otherCoefs;
    otherCoefs.fill(0);
    otherCoefs[N - 1] = 1;
    transformSLE<RealType, N>(matr, otherCoefs);
    //RealType centralCoef = std::accumulate(otherCoefs.begin(), otherCoefs.end(), 0, std::minus<RealType>());
    RealType centralCoef = 0;
    for (RealType el : otherCoefs)
        centralCoef -= el;
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