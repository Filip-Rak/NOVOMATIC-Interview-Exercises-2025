# Exercise 3 - CMakeLists.txt

# Main executable
add_executable(ex3_main main.cpp)

# Test executable
add_executable(ex3_tests test_calculate.cpp)
target_link_libraries(ex3_tests PRIVATE Catch2::Catch2WithMain)
add_test(NAME Exercise3_CalculateTests COMMAND ex3_tests)
