#include <gtest/gtest.h>
#include "celestial_mechanics/time/DutContainer.hpp"
#include "celestial_mechanics/time/Interpolation.hpp"
#include <vector>
#include <string>
#include "celestial_mechanics/time/rapidcsv.h"
#include "tests/Paths.hpp"

TEST(DutContainerTest, RapidcsvWorks) {
    std::filesystem::path path_ = std::filesystem::current_path();
    // std::cout << "Current directory path: " << path_  << std::endl;
    // std::cout << "Current file path: " << __FILE__ << std::endl;
    rapidcsv::Document doc = rapidcsv::Document(resourcesPath() / "dut.csv");
    std::cout << resourcesPath() << std::endl;
    std::vector<double> MJD_nodes = doc.GetColumn<double>("MJD");
    std::vector<double> dut_values = doc.GetColumn<double>("UT1-UTC");
    unsigned int N = dut_values.size();
    EXPECT_TRUE(N > 0);
}