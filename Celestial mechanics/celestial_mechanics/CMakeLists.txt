cmake_minimum_required(VERSION 3.28.1)
project(celestial_mechanics)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(third_party)

enable_testing()
add_subdirectory(tests)

#add_executable(celestial_mechanics_main main.cpp)

#target_link_libraries(celestial_mechanics_main PRIVATE sofa GeographicLib time)