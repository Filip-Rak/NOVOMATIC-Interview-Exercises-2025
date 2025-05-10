# Exercise 2 - CMakeLists.txt

# Fetch SFML
include(FetchContent)

FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.6.2
)

FetchContent_MakeAvailable(SFML)

# Main executable
add_executable(ex2_main main.cpp triangle.cpp)
target_link_libraries(ex2_main PRIVATE sfml-graphics sfml-window sfml-system)

# Test executable
add_executable(ex2_tests test_collision.cpp triangle.cpp)
target_link_libraries(ex2_tests PRIVATE Catch2::Catch2WithMain)
add_test(NAME Exercise2_CollisionTests COMMAND ex2_tests)
