#include "explicitRungeKutta.hpp"
#include <Core>

Eigen::Vector<double, CubicTime::dim> CubicTime::calc(const CubicTime::StateAndArg& stateAndArg) const {
    return Eigen::Vector<double, dim> {std::pow(stateAndArg.arg, 3)};
}

Eigen::Vector<double, Harmonic::dim> Harmonic::calc(const Harmonic::StateAndArg& stateAndArg) const {
    return Eigen::Vector<double, dim> {Harmonic::f * stateAndArg.state};
}