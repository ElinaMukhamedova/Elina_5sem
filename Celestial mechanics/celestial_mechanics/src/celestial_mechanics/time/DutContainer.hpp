#include <vector>
#include <string>
#include <filesystem>

class DutContainer {
    std::vector<double> MJD_nodes_;
    std::vector<double> dut_values_;
    std::size_t N_;

    public:
        DutContainer() {}
        DutContainer(const std::vector<double>& nodes, const std::vector<double>& values) : MJD_nodes_(nodes), dut_values_(values){}
        DutContainer(std::filesystem::path abs_path, char separator = ',', std::string MJD_column_name = "MJD", std::string dut_column_name = "UT1-UTC");
        
        std::size_t N();
        std::vector<double> MJD_nodes();
        std::vector<double> dut_values();
        
        double dut(double mjd) const;
};