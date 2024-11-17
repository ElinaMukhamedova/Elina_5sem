cmake_minimum_required(VERSION 3.28.1)
project(RungeKuttaMethods)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(third_party)

enable_testing()
add_subdirectory(tests)

add_executable(run_RK4 RK4.cpp)

target_link_libraries(run_RK4 RungeKuttaMethods)