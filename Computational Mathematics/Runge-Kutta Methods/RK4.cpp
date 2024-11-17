#include <RungeKuttaMethods/classicRungeKutta.hpp>
#include <iostream>

int main() {
    RK4Table table;
    std::cout << table.aTable[0][0] << std::endl;
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i)
            std::cout << table.aTable[j][i] << " ";
        std::cout << std::endl;
    }
    return 0;
}