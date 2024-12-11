#include <string>
#include <vector>
#include "celestial_mechanics/Interpolation.hpp"
#include "TSIcontainer.hpp"
#include "celestial_mechanics/rapidcsv.h"

TSIcontainer TSIcontainer::buildFromFile(std::filesystem::path path_to_file,
                                            char separator,
                                            std::string JD_column_name, 
                                            std::string TSI_column_name)
{
    rapidcsv::Document doc = rapidcsv::Document(path_to_file,
                                                rapidcsv::LabelParams(0, -1),
                                                rapidcsv::SeparatorParams(separator),
                                                rapidcsv::ConverterParams(true));

    std::vector<double> JD_column = doc.GetColumn<double>(JD_column_name);
    std::vector<double> TSI_column = doc.GetColumn<double>(TSI_column_name);
    std::size_t TSI_size = TSI_column.size();

    std::vector<double> nodes;
    std::vector<double> values;

    for (std::size_t i = 0; i < TSI_size; ++i)
        if (std::isnan(TSI_column[i]) == false) {
            nodes.push_back(JD_column[i]);
            values.push_back(TSI_column[i]);
        }


    return TSIcontainer{nodes, values};
}

const std::vector<double>& TSIcontainer::JD_nodes() const {return JD_nodes_;}
const std::vector<double>& TSIcontainer::TSI_values() const {return TSI_values_;}

double TSIcontainer::tsi(double jd) const {
    return interpolant_.evaluate(jd);
}