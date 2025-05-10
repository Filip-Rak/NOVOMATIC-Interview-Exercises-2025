# Exercise 2 - CMakeLists.txt

# SFML Dependency
include(FetchContent)

FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.6.2
)

FetchContent_MakeAvailable(SFML)

# Main Executable
add_executable(ex2_main 
	src/main.cpp
	src/triangle.cpp
	src/visualization.cpp
)	
target_include_directories(ex2_main PRIVATE include)
target_link_libraries(ex2_main PRIVATE sfml-graphics sfml-window sfml-system)

# Unit Tests
add_executable(ex2_tests 
	tests/test_collision.cpp 
	src/triangle.cpp
)
target_include_directories(ex2_tests PRIVATE include)
target_link_libraries(ex2_tests PRIVATE Catch2::Catch2WithMain)
add_test(NAME Exercise2_CollisionTests COMMAND ex2_tests)
