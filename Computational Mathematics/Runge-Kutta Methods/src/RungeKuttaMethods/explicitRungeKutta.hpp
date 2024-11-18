#include <array>
#include <vector>
#include <cmath>
#include <type_traits>
#include <Core>

struct RK4Table {
    static constexpr unsigned int stages = 4;
    static constexpr std::array<std::array<double, stages>, stages>
        aTable = {{ {0, 0, 0, 0}, {0.5, 0, 0, 0}, {0, 0.5, 0, 0}, {0, 0, 1, 0} }};
    static constexpr std::array<double, stages> cColumn = {0, 0.5, 0.5, 1};
    static constexpr std::array<double, stages> bString = {(double)1/6, (double)1/3, (double)1/3, (double)1/6};
};

class CubicTime {
    public:
        static constexpr unsigned int dim = 1;
        using Argument = double;
        using State = Eigen::Vector<double, dim>;
        struct StateAndArg {
            State state;
            Argument arg;
        };
        Eigen::Vector<double, dim> calc(const StateAndArg& stateAndArg) const;
};

class Harmonic {
    public:
        static constexpr unsigned int dim = 2;
        using Argument = double;
        using State = Eigen::Vector<double, dim>;
        struct StateAndArg {
            State state;
            Argument arg;
        };
        const Eigen::Matrix<double, dim, dim> f{{0, 1}, {-1, 0}};
        Eigen::Vector<double, dim> calc(const StateAndArg& stateAndArg) const;
};

template<typename Table, typename RHS>
std::vector<typename RHS::StateAndArg> integrate (
    const typename RHS::State& initialState,
    const typename RHS::Argument& endTime,
    double step,
    const RHS& rhs) {
        Table Butcher_table;
        auto aTable_ = Butcher_table.aTable;
        auto bString_ = Butcher_table.bString;
        auto cColumn_ = Butcher_table.cColumn;
        auto stages_ = Butcher_table.stages;
        auto dim_ = rhs.dim;
        std::vector<typename RHS::State> Ks;
        std::vector<typename RHS::StateAndArg> solution;
        typename RHS::Argument currentTime = 0;
        typename RHS::State currentState = initialState;
        typename RHS::State nextState;
        typename RHS::StateAndArg currentStateAndArg;
        while (currentTime < endTime) {
            currentStateAndArg.state = currentState;
            currentStateAndArg.arg = currentTime;
            solution.push_back(currentStateAndArg);

            Ks.push_back(rhs.calc(currentStateAndArg));
            for (std::size_t i = 1; i < stages_; ++i) {
                typename RHS::State K_sum = Ks[0];
                for (std::size_t j = 0; j < i; ++j)
                    K_sum += aTable_[i][j] * Ks[j];
                typename RHS::StateAndArg x;
                x.state = currentState + step * K_sum;
                x.arg = currentTime + step * cColumn_[i];
                Ks.push_back(rhs.calc(x));
            }

            nextState = currentState;
            for (std::size_t i = 0; i < stages_; ++i)
                nextState += step * bString_[i] * Ks[i];
            
            currentTime += step;
            currentState = nextState;
        }
        return solution;
    }