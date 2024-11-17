file(GLOB_RECURSE SOURCE *.h)
add_library(Eigen INTERFACE ${SOURCE})
target_include_directories(Eigen INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/Eigen")