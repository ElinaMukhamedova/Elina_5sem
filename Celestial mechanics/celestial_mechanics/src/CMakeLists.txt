file(GLOB_RECURSE SOURCE *.cpp *.hpp)

add_library(time ${SOURCE})

target_link_libraries(time sofa)
target_include_directories(time PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})