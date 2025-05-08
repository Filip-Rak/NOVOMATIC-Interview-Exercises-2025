# Main executable
add_executable(ex1_main main.cpp src/Trie.cpp)
target_include_directories(ex1_main PRIVATE include)

add_executable(ex1_tests tests/test_trie.cpp src/Trie.cpp)
target_include_directories(ex1_tests PRIVATE include)
target_link_libraries(ex1_tests PRIVATE catch2_amalgamated)
add_test(NAME ex1_tests COMMAND ex1_tests)