#pragma once

#include <vector>
#include <array>
#include <string>
#include <filesystem>
#include "Interpolation.hpp"

class DutContainer {
    std::vector<double> MJD_nodes_;
    std::vector<double> dut_values_;
    Interpolant<double, double> interpolant_;

    public:
        DutContainer(const std::vector<double>& nodes, const std::vector<double>& values) : MJD_nodes_(nodes), dut_values_(values){
            interpolant_ = Interpolant<double, double>(MJD_nodes_, dut_values_);
        }
        DutContainer(std::filesystem::path abs_path, char separator = ',', std::string MJD_column_name = "MJD", std::string dut_column_name = "UT1-UTC");
        

        const std::vector<double>& MJD_nodes() const;
        const std::vector<double>& dut_values() const;
        
        double dut(double mjd) const;

        const std::array<double, 2> MinMaxDerivative() const;
};