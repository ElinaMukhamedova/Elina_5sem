file(GLOB_RECURSE TEST_FILES test_*.cpp)

foreach (FILE IN LISTS TEST_FILES)

    get_filename_component(EXE_NAME ${FILE} NAME_WE)

    add_executable(${EXE_NAME} ${FILE})

    target_link_libraries(${EXE_NAME} ${PROJECT_NAME} gtest gtest_main)

    add_test(NAME ${EXE_NAME} COMMAND ${EXE_NAME})

endforeach ()
