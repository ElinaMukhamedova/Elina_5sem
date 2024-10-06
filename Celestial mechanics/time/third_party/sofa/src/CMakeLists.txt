file(GLOB_RECURSE SOURCE *.cpp)
add_library(sofa ${SOURCE})
target_include_directories(sofa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})