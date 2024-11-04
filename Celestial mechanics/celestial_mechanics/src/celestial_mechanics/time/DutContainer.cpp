#include <string>
#include <vector>
#include "Interpolation.hpp"
#include "DutContainer.hpp"
#include "rapidcsv.h"

DutContainer::DutContainer(std::filesystem::path abs_path,
                        char separator,
                        std::string MJD_column_name,
                        std::string dut_column_name)
{
    rapidcsv::Document doc = rapidcsv::Document(abs_path,
                                                rapidcsv::LabelParams(0, -1),
                                                rapidcsv::SeparatorParams(separator),
                                                rapidcsv::ConverterParams(true));
    std::vector<double> MJD_column = doc.GetColumn<double>(MJD_column_name);
    std::vector<double> dut_column = doc.GetColumn<double>(dut_column_name);
    std::size_t dut_size = dut_column.size();
    N_ = 0;
    for (std::size_t i = 0; i < dut_size; ++i)
        if (std::isnan(dut_column[i]) == false) {
            MJD_nodes_.push_back(MJD_column[i]);
            dut_values_.push_back(dut_column[i]);
            N_ += 1;
        }
}

std::size_t DutContainer::N() {return N_;}
std::vector<double> DutContainer::MJD_nodes() {return MJD_nodes_;}
std::vector<double> DutContainer::dut_values() {return dut_values_;}

double DutContainer::dut(double mjd) const {
    NewtonInterpolant<double, double> interpolant(MJD_nodes_, dut_values_);
    return interpolant.evaluate(mjd);
}