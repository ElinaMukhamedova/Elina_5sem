cmake_minimum_required(VERSION 3.28.1)
project(BDF)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(third_party)

enable_testing()
add_subdirectory(tests)

add_executable(run_BDF BDF.cpp)

target_link_libraries(run_BDF BDF)