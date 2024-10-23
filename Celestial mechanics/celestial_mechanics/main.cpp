#include <iostream>
#include "time/Time.hpp"

int main() {
    Time today = Time::fromCalendar(2024, 10, 7, 20, 49, 13);
    std::cout << today.jdFrac() << std::endl;

    return 0;
}