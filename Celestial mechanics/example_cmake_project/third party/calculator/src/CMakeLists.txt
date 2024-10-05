file(GLOB_RECURSE SOURCE *.cpp)

add_library(calculator ${SOURCE})

target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})