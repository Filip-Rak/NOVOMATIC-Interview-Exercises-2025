# Exercise 1 - CMakeLists.txt

# Main executable
add_executable(ex1_main main.cpp trie.cpp)

# Test executable
add_executable(ex1_tests test_trie.cpp trie.cpp)
target_link_libraries(ex1_tests PRIVATE Catch2::Catch2WithMain)
add_test(NAME Exercise1_TrieTests COMMAND ex1_tests)
