#include <vector>

class DutContainer {
    std::vector<double> MJD_nodes;
    std::vector<double> dut_values;
    unsigned int N;

    public:
        DutContainer(std::vector<double> nodes, std::vector<double> values) : MJD_nodes(nodes), dut_values(values){}
        double dut(double mjd) const;
};