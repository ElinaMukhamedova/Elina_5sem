#include <string>
#include <vector>
#include "Interpolation.hpp"
#include "DutContainer.hpp"

double DutContainer::dut(double mjd) const {
    NewtonInterpolant<double, double> interpolant(MJD_nodes, dut_values);
    return interpolant.evaluate(mjd);
}