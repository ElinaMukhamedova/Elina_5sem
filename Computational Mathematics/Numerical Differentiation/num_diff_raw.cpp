#include <array>
#include <iostream>

int main() {
    //std::array<double, 4> alpha = {2, 4, 6, 0};
    std::array<double, 3> alpha = {1, 2, 0};
    //std::array<double, 3> alpha = {-1, 1, 0};

    std::cout << "alpha" << std::endl;
    for (auto el : alpha)
        std::cout << el << ' ';
    std::cout << std::endl;

    //std::array<std::array<double, 4>, 3> matr;
    std::array<std::array<double, 3>, 2> matr;

    matr.fill(alpha);
    int N = matr.size();
    std::cout << "fill" << std::endl;
    for (auto raw : matr) {
        for (auto el : raw)
            std::cout << el << ' ';
        std::cout << std::endl;
    }
    for (int i = N - 2; i >= 0; --i)
        for (int j = 0; j != N + 1; ++j)
            matr[i][j] = matr[i + 1][j] * alpha[j] / (N - i);
    matr[N - 1][N] = 1;
    std::cout << "matr" << std::endl;
    for (auto raw : matr) {
        for (auto el : raw)
            std::cout << el << ' ';
        std::cout << std::endl;
    }
    for (int n = 0; n != N; ++n) {
        for (int i = n + 1; i != N; ++i) {
            double k = matr[i][n] / matr[n][n];
            for (int j = 0; j != N + 1; ++j)
                matr[i][j] -= k * matr[n][j];
        }
        std::cout << "matr" << std::endl;
        for (int i = 0; i != N; ++i) {
            for (int j = 0; j != N + 1; ++j)
                std::cout << matr[i][j] << ' ';
            std::cout << std::endl;
        }
    }

    for (int i = 0; i != N; ++i) {
        double pivot = matr[i][i];
        for (int j = i; j != N + 1; ++j)
            matr[i][j] = matr[i][j] / pivot;
    }
    std::cout << "matr" << std::endl;
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != N + 1; ++j)
            std::cout << matr[i][j] << ' ';
        std::cout << std::endl;
    }

    for (int n = 0; n != N; ++n)
        for (int i = n + 1; i != N; ++i) {
            double k = matr[n][i];
            for (int j = i; j != N + 1; ++j)
                matr[n][j] -= k * matr[i][j];
        }

    std::cout << "matr" << std::endl;
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != N + 1; ++j)
            std::cout << matr[i][j] << ' ';
        std::cout << std::endl;
    }

    //std::array<double, 3> otherCoefs;
    std::array<double, 2> otherCoefs;

    for (int i = 0; i != N; ++i)
        otherCoefs[i] = matr[i][N];
    double centralCoef = 0;
    for (auto el : otherCoefs)
        centralCoef -= el;
    std::cout << "Coefficients" << std::endl;
    std::cout << "A_0 = " << centralCoef << std::endl;
    for (int i = 0; i != N; ++i)
        std::cout << "A_" << i + 1 << " = " << otherCoefs[i] << std::endl;

    return 0;
}