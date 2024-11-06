#include <cmath>
#include <vector>
#include <numbers>
#include <iostream>
#include "Exception.hpp"

double Kepler(double ecc, double meanAnomaly, double E) {return E - ecc * std::sin(E) - meanAnomaly;}
double KeplerPrime(double ecc, double E) {return 1 - ecc * std::cos(E);}

std::vector<double> solveKepler(double ecc, double meanAnomaly, unsigned int maxIter, double tol) {
    std::vector<double> approximations;
    bool solution_found = false;
    unsigned int iter = 0;
    double E_prev = meanAnomaly / (1 - ecc);
    approximations.push_back(E_prev);
    double E;
    while (solution_found == false && iter < maxIter) {
        E = E_prev - Kepler(ecc, meanAnomaly, E_prev) / KeplerPrime(ecc, E_prev);
        if (std::abs(E - E_prev) <= tol)
            solution_found = true;
        approximations.push_back(E);
        E_prev = E;
        iter += 1;
    }
    if (solution_found == false)
        throw Exception("solver failed to converge");
    return approximations;
}

int main() {
    std::vector<double> ecc_choice = {0.1, 0.2, 0.5, 0.8};
    double M = std::numbers::pi_v<double> / 4;
    for (double ecc : ecc_choice) {
        std::vector<double> errors;
        std::vector<double> approximations = solveKepler(ecc, M, 5, 1e-12);
        unsigned int Iter = approximations.size();
        double E_star = approximations[Iter - 1];
        std::cout << "ecc = " << ecc << "   E = " << E_star << "   Kepler(E) = " << Kepler(ecc, M, E_star) << std::endl;
        std::vector<double> log10_errors;
        for (unsigned int i = 0; i < Iter; ++i) {
            log10_errors.push_back(std::log10(std::abs(E_star - approximations[i])));
            std::cout << log10_errors[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}