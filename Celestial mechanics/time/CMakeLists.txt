cmake_minimum_required(VERSION 3.30)
project(time)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(third_party)
add_subdirectory(tests)