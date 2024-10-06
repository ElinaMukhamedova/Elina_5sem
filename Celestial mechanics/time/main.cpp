#include <iostream>
#include <format_and_duration/Time.hpp>

int main() {
    Time today = Time::fromCalendar(2024, 10, 6);
    std::cout << today.jdInt() << std::endl;

    return 0;
}