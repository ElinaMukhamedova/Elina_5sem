#include "explicitRungeKutta.hpp"
#include <Core>

Eigen::Vector<double, CubicTime0::dim> CubicTime0::calc(const CubicTime0::StateAndArg& stateAndArg) const {
    return Eigen::Vector<double, dim> {std::pow(stateAndArg.arg, 3)};
}

Eigen::Vector<double, Harmonic0::dim> Harmonic0::calc(const Harmonic0::StateAndArg& stateAndArg) const {
    return Eigen::Vector<double, dim> {Harmonic0::f * stateAndArg.state * std::pow(omega, 2)};
}