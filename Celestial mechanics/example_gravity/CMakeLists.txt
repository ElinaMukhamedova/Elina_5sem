cmake_minimum_required(VERSION 3.30)
project(example_gravity)
set(CMAKE_CXX_STANDARD 20)      

add_subdirectory(GeographicLib)

add_executable(example_gravity_main main.cpp)

target_link_libraries(example_gravity_main GeographicLib)