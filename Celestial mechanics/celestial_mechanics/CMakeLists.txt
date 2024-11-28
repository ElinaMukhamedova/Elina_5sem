cmake_minimum_required(VERSION 3.28.1)
project(celestial_mechanics)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(third_party)

add_executable(ReferenceSystemConverter main.cpp)
target_link_libraries(ReferenceSystemConverter celestial_mechanics gtest gtest_main sofa Eigen)

enable_testing()
add_subdirectory(tests)