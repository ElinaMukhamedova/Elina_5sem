#include <BDF/BDF4.hpp>
#include <RungeKuttaMethods/explicitRungeKutta.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <Core>

typename CubicTime::State true_cubicTimeRHS(typename CubicTime::State initialState, typename CubicTime::Argument t) {
    typename CubicTime::State state;
    state[0] = 0.25 * std::pow(t, 4);
    return initialState + state;
}

typename Harmonic::State true_harmonicRHS(typename Harmonic::State initialState, typename Harmonic::Argument t) {
    typename Harmonic::State state;
    state[0] = initialState[0] * std::cos(t) + initialState[1] * std::sin(t);
    state[1] = -initialState[0] * std::sin(t) + initialState[1] * std::cos(t);
    return state;
}

int main() {
    CubicTime cubicTimeRHS;
    auto initialState_cubicTimeRHS = typename CubicTime::State {0};
    auto endTime_cubicTimeRHS = typename CubicTime::Argument {5};
    std::vector<std::array<double, 2>> logSteplogError_cubicTimeRHS;

    Harmonic harmonicRHS;
    auto initialState_harmonicRHS = typename Harmonic::State {0, 1};
    auto endTime_harmonicRHS = typename Harmonic::Argument {5};
    std::vector<std::array<double, 2>> logSteplogError_harmonicRHS;

    std::array<double, 13> step_choice = {1};
    unsigned int n = step_choice.size();
    for (unsigned int i = 1; i < n; ++i)
        step_choice[i] = step_choice[i - 1] / 2;

    IntegrationParameters parameters{0, 1e-5, 1000};

    std::cout << "logStep" << std::endl;
    for (double step : step_choice) {
        parameters.step = step;
        auto integrated_cubicTimeRHS = integrateBDF<BDF5, CubicTime, RK4Table>(initialState_cubicTimeRHS, endTime_cubicTimeRHS, parameters, cubicTimeRHS);       
        auto integrated_harmonicRHS = integrateBDF<BDF5, Harmonic, RK4Table>(initialState_harmonicRHS, endTime_harmonicRHS, parameters, harmonicRHS);
        
        double error_cubicTimeRHS = 0, error_harmonicRHS = 0;
        for (auto StateAndArg : integrated_cubicTimeRHS) {
            auto delta_state = StateAndArg.state - true_cubicTimeRHS(initialState_cubicTimeRHS, StateAndArg.arg);
            double error = delta_state.norm();
            if (error > error_cubicTimeRHS)
                error_cubicTimeRHS = error;
        }
        for (auto StateAndArg : integrated_harmonicRHS) {
            auto delta_state = StateAndArg.state - true_harmonicRHS(initialState_harmonicRHS, StateAndArg.arg);
            double error = delta_state.norm();
            if (error > error_harmonicRHS)
                error_harmonicRHS = error;
        }
        
        double logStep = std::log2(step);
        std::cout << logStep << ", ";
        logSteplogError_cubicTimeRHS.push_back(std::array<double, 2>{logStep, std::log2(error_cubicTimeRHS)});
        logSteplogError_harmonicRHS.push_back(std::array<double, 2>{logStep, std::log2(error_harmonicRHS)});
    }
    
    std::cout << std::endl;
    std::cout << "logError_cubicTimeRHS" << std::endl;
    for (unsigned int i = 0; i < n; ++i)
        std::cout << logSteplogError_cubicTimeRHS[i][1] << ", ";
    std::cout << std::endl;
    std::cout << "logError_harmonicRHS" << std::endl;
    for (unsigned int i = 0; i < n; ++i)
        std::cout << logSteplogError_harmonicRHS[i][1] << ", ";

    return 0;
}