# Exercise 2 - CMakeLists.txt

# Main executable
add_executable(ex2_main main.cpp triangle.cpp)

# Test executable
add_executable(ex2_tests test_collision.cpp triangle.cpp)
target_link_libraries(ex2_tests PRIVATE Catch2::Catch2WithMain)
add_test(NAME Exercise2_CollisionTests COMMAND ex2_tests)
