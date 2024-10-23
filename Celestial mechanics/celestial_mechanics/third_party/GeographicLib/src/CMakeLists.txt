file(GLOB_RECURSE SOURCE *.cpp *.hpp *.hh)
add_library(GeographicLib ${SOURCE})
target_include_directories(GeographicLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/GeographicLib-2.4")