cmake_minimum_required(VERSION 3.30)
project(celestial_mechanics)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(third_party)
add_subdirectory(tests)

add_executable(celestial_mechanics_main main.cpp)

target_link_libraries(celestial_mechanics_main ${PROJECT_NAME})
target_include_directories()