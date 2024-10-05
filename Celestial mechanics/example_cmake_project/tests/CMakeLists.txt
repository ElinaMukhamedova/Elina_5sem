file(GLOB_RECURSE FILE_TESTS test_*.cpp)

foreach (FILE_TEST IN LISTS FILE_TESTS)
    get_filename_component(EXE_NAME ${FILE_TEST} NAME_WE)
    add_executable(${EXE_NAME} ${FILE_TEST})
    target_link_libraries(${EXE_NAME} ${PROJECT_NAME} gtest gtest_main)
    add_test(NAME ${EXE_NAME} COMMAND ${EXE_NAME})
endforeach()