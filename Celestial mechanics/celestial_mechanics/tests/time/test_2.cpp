#include <gtest/gtest.h>
#include "celestial_mechanics/time/DutContainer.hpp"
#include "celestial_mechanics/time/Interpolation.hpp"
#include <vector>
#include <string>
#include <cmath>
#include "celestial_mechanics/time/rapidcsv.h"
#include "tests/Paths.hpp"

TEST(DutContainerTest, RapidcsvWorks) {
    std::cout << std::filesystem::current_path() << std::endl;
    std::cout << projectPath() << std::endl;
    std::cout << resourcesPath() << std::endl;

    rapidcsv::Document doc = rapidcsv::Document(resourcesPath() / "dut.csv", rapidcsv::LabelParams(0, -1),
                        rapidcsv::SeparatorParams(';'), rapidcsv::ConverterParams(true));
    std::cout << resourcesPath() << std::endl;
    std::vector<double> MJD_column = doc.GetColumn<double>("MJD");
    std::vector<double> dut_column = doc.GetColumn<double>("UT1-UTC");
    std::vector<double> MJD_nodes;
    std::vector<double> dut_values;
    std::size_t N = dut_column.size();
    for (std::size_t i = 0; i < N; ++i)
        if (std::isnan(dut_column[i]) == false) {
            MJD_nodes.push_back(MJD_column[i]);
            dut_values.push_back(dut_column[i]);
        }
    
    std::cout << dut_column.size() << std::endl;
    std::cout << MJD_column.size() << std::endl;
    std::cout << dut_values.size() << std::endl;
    std::cout << MJD_nodes.size() << std::endl;

    EXPECT_TRUE(true);
}

TEST(DutContainerTest, SpaceSeparatorWorks) {
    rapidcsv::Document doc = rapidcsv::Document(resourcesPath() / "trimmed.csv", rapidcsv::LabelParams(0, -1),
                        rapidcsv::SeparatorParams(' '), rapidcsv::ConverterParams(true));

    std::vector<double> MJD_column = doc.GetColumn<double>("MJD");
    std::vector<double> dut_column = doc.GetColumn<double>("UT1-UTC");
    std::vector<double> MJD_nodes;
    std::vector<double> dut_values;
    std::size_t N = dut_column.size();
    for (std::size_t i = 0; i < N; ++i)
        if (std::isnan(dut_column[i]) == false) {
            MJD_nodes.push_back(MJD_column[i]);
            dut_values.push_back(dut_column[i]);
        }
    
    std::cout << dut_column.size() << std::endl;
    std::cout << MJD_column.size() << std::endl;
    std::cout << dut_values.size() << std::endl;
    std::cout << MJD_nodes.size() << std::endl;

    EXPECT_TRUE(true);
}

TEST(DutContainerTest, ConstructorWorks) {
    DutContainer dut = DutContainer(resourcesPath() / "trimmed.csv", ' ');
    std::cout << dut.N() << std::endl;
    std::cout << dut.MJD_nodes().size() << std::endl;
    std::cout << dut.dut_values().size() << std::endl;
    EXPECT_TRUE(dut.MJD_nodes().size() == dut.N());
    EXPECT_TRUE(dut.dut_values().size() == dut.N());
}