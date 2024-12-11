#pragma once

#include <vector>
#include <array>
#include <string>
#include <filesystem>
#include "celestial_mechanics/Interpolation.hpp"
#include "celestial_mechanics/rapidcsv.h"

class TSIcontainer {
    std::vector<double> JD_nodes_;
    std::vector<double> TSI_values_;
    Interpolant<double, double> interpolant_;

    public:
        TSIcontainer(const std::vector<double>& nodes, const std::vector<double>& values) : JD_nodes_(nodes), TSI_values_(values), interpolant_(nodes, values){}
        
        static TSIcontainer buildFromFile(std::filesystem::path path_to_file,
                                            char separator = ' ',
                                            std::string JD_column_name = "JD", 
                                            std::string TSI_column_name = "TSI");

        const std::vector<double>& JD_nodes() const;
        const std::vector<double>& TSI_values() const;
        
        double tsi(double jd) const;
};