cmake_minimum_required(VERSION 3.28)
project(example_cmake_project)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party)
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

add_executable(example_cmake_project_main main.cpp)
target_link_libraries(example_cmake_project_main ${PROJECT_NAME})