#include "BDF4.hpp"
#include <Core>

Eigen::Vector<double, CubicTime::dim> CubicTime::calc(const CubicTime::StateAndArg& stateAndArg) const {
    return Eigen::Vector<double, dim> {std::pow(stateAndArg.arg, 3)};
}

Eigen::Vector<double, Harmonic::dim> Harmonic::calc(const Harmonic::StateAndArg& stateAndArg) const {
    return Eigen::Vector<double, dim> {Harmonic::f * stateAndArg.state * std::pow(omega, 2)};
}

double CubicTime::calcDif(const CubicTime::State& first, const CubicTime::State& second) const{
    return (first-second).norm();
}

double Harmonic::calcDif(const Harmonic::State& first, const Harmonic::State& second) const{
    return (first-second).norm();
}