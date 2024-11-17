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

    for (std::size_t i = 0; i < dut_size; ++i)
        if (std::isnan(dut_column[i]) == false) {
            MJD_nodes_.push_back(MJD_column[i]);
            dut_values_.push_back(dut_column[i]);
        }
    
    interpolant_ = Interpolant<double, double>(MJD_nodes_, dut_values_);
}

const std::vector<double>& DutContainer::MJD_nodes() const {return MJD_nodes_;}
const std::vector<double>& DutContainer::dut_values() const {return dut_values_;}

double DutContainer::dut(double mjd) const {
    Interpolant<double, double> interpolant(MJD_nodes_, dut_values_);
    return interpolant.evaluate(mjd);
}