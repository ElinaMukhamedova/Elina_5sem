file(GLOB_RECURSE SOURCE *.cpp *.hpp)

add_library(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} sofa)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})