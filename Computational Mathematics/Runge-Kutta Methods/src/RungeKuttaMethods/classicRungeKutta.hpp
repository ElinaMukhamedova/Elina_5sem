#include <array>
#include <vector>
#include <cmath>
#include <EigenLib/Core>

struct RK4Table {
    static constexpr unsigned int stages = 4;
    static constexpr std::array<std::array<double, stages>, stages>
        aTable = {{ {0, 0, 0, 0}, {0.5, 0, 0, 0}, {0, 0.5, 0, 0}, {0, 0, 1, 0} }};
    static constexpr std::array<double, stages> cColumn = {0, 0.5, 0.5, 1};
    static constexpr std::array<double, stages> bString = {(double)1/6, (double)1/3, (double)1/3, (double)1/6};
};

class Cubic {
    public:
        static constexpr unsigned int dim = 1;
        using Argument = double;
        using State = Eigen::Vector<double, dim>;
        struct StateAndArg {
            State state;
            Argument arg;
        };
        Eigen::Vector<double, dim> calc(const StateAndArg& stateAndArg) const {
            return Eigen::Vector<double, dim> {std::pow(stateAndArg.arg, 3)};
        }
};

template<typename Table, typename RHS>
std::vector<typename RHS::StateAndArg> integrate (
    const typename RHS::StateAndArg& initialState,
    const typename RHS::Argument& endTime,
    double step,
    const RHS& rhs) {
    }