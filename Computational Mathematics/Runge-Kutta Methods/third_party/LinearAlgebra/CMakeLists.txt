file(GLOB_RECURSE SOURCE *.c *.h)
add_library(eigen ${SOURCE})
target_include_directories(eigen PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/eigen/Eigen")