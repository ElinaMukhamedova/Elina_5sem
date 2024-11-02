#include <gtest/gtest.h>
#include <time/DutContainer.hpp>
#include <time/Interpolation.hpp>
#include <vector>
#include <filesystem>
#include <string>
#include <time/rapidcsv.h>

TEST(DutContainerTest, RapidcsvWorks) {
    std::filesystem::path path_ = std::filesystem::current_path();
    std::cout << "Current directory path: " << path_  << std::endl;
    std::cout << "Current file path: " << __FILE__ << std::endl;
    rapidcsv::Document doc = rapidcsv::Document("/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/celestial_mechanics/dut.csv");
    std::vector<double> MJD_nodes = doc.GetColumn<double>("MJD");
    std::vector<double> dut_values = doc.GetColumn<double>("UT1-UTC");
    unsigned int N = dut_values.size();
    EXPECT_TRUE(N > 0);
}