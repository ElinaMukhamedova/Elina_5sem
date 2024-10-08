#include "num_diff.hpp"

int main() {
    std::array<double, 2> points_2 = {1, 2};
    auto answer_2 = calcDerivativeCoef<double, 2>(points_2);
    std::cout << "A_0 * h = " << answer_2.centralCoef_ << std::endl;
    int N_2 = answer_2.otherCoefs_.size();
    for (int i = 0; i != N_2; ++i)
        std::cout << "A_" << i + 1 << " * h = " << answer_2.otherCoefs_[i] << std::endl;
    
    std::cout << "~~~~~~~~~~~~~~~~~" << std::endl;

    std::array<double, 3> points = {1, 2, 3};
    auto answer = calcDerivativeCoef<double, 3>(points);
    std::cout << "A_0 * h = " << answer.centralCoef_ << std::endl;
    int N = answer.otherCoefs_.size();
    for (int i = 0; i != N; ++i)
        std::cout << "A_" << i + 1 << " * h = " << answer.otherCoefs_[i] << std::endl;
    
    std::cout << "~~~~~~~~~~~~~~~~~" << std::endl;
    
    std::array<double, 16> steps;
    int n = steps.size();
    steps.fill(1);
    for (int i = 1; i != n; ++i)
        steps[i] = steps[i - 1] / 10;
//    for (auto el : steps)
//        std::cout << el << std::endl;
    
    std::array<double, 3> exp_3 = {1, 2, 3};
    std::array<double, 16> answers_3;
    auto coef_3 = calcDerivativeCoef<double, 3>(exp_3);
    for (int i = 0; i != 16; ++i) {
        answers_3[i] = coef_3.centralCoef_  / steps[i] * std::exp(1);
        for (int j = 0; j != 3; ++j)
            answers_3[i] += coef_3.otherCoefs_[j] / steps[i] * std::exp(1 + steps[i] * (j + 1));
    }
    std::cout << "N = " << 3 << std::endl;
    for (auto el : answers_3)
        std::cout << el << std::endl;
    logErrors<double, 16> errors_3 = errorAnalysis<double, 16>(std::exp(1), answers_3, steps);
    for (int i = 0; i != 16; ++i)
        std::cout << "log error = " << errors_3.logCumulatedErrors_[i] << ", log step = " << errors_3.logSteps_[i] << std::endl;

    std::cout << "~~~~~~~~~~~~~~~~~" << std::endl;

    std::array<double, 4> exp_4 = {1, 2, 3, 4};
    std::array<double, 16> answers_4;
    auto coef_4 = calcDerivativeCoef<double, 4>(exp_4);
    for (int i = 0; i != 16; ++i) {
        answers_4[i] = coef_4.centralCoef_ / steps[i] * std::exp(1);
        for (int j = 0; j != 4; ++j)
            answers_4[i] += coef_4.otherCoefs_[j] / steps[i] * std::exp(1 + steps[i] * (j + 1));
    }
    std::cout << "N = " << 4 << std::endl;
    for (auto el : answers_4)
        std::cout << el << std::endl;
    logErrors<double, 16> errors_4 = errorAnalysis<double, 16>(std::exp(1), answers_4, steps);
    for (int i = 0; i != 16; ++i)
        std::cout << "log error = " << errors_4.logCumulatedErrors_[i] << ", log step = " << errors_4.logSteps_[i] << std::endl;
    
    std::cout << "~~~~~~~~~~~~~~~~~" << std::endl;

    std::array<double, 5> exp_5 = {1, 2, 3, 4, 5};
    std::array<double, 16> answers_5;
    auto coef_5 = calcDerivativeCoef<double, 5>(exp_5);
    for (int i = 0; i != 16; ++i) {
        answers_5[i] = coef_5.centralCoef_ / steps[i] * std::exp(1);
        for (int j = 0; j != 5; ++j)
            answers_5[i] += coef_5.otherCoefs_[j] / steps[i] * std::exp(1 + steps[i] * (j + 1));
    }
    std::cout << "N = " << 5 << std::endl;
    for (auto el : answers_5)
        std::cout << el << std::endl;
    logErrors<double, 16> errors_5 = errorAnalysis<double, 16>(std::exp(1), answers_5, steps);
    for (int i = 0; i != 16; ++i)
        std::cout << "log error = " << errors_5.logCumulatedErrors_[i] << ", log step = " << errors_5.logSteps_[i] << std::endl;
    
    std::cout << "~~~~~~~~~~~~~~~~~" << std::endl;

    std::array<double, 2> exp_2 = {1, 2};
    std::array<double, 16> answers_2;
    auto coef_2 = calcDerivativeCoef<double, 2>(exp_2);
    for (int i = 0; i != 16; ++i) {
        answers_2[i] = coef_2.centralCoef_ / steps[i] * std::exp(1);
        for (int j = 0; j != 2; ++j)
            answers_2[i] += coef_2.otherCoefs_[j] / steps[i] * std::exp(1 + steps[i] * (j + 1));
    }
    std::cout << "N = " << 2 << std::endl;
    for (auto el : answers_2)
        std::cout << el << std::endl;
    logErrors<double, 16> errors_2 = errorAnalysis<double, 16>(std::exp(1), answers_2, steps);
    for (int i = 0; i != 16; ++i)
        std::cout << "log error = " << errors_2.logCumulatedErrors_[i] << ", log step = " << errors_2.logSteps_[i] << std::endl;

    return 0;
}