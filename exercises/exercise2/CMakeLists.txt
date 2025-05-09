# Exercise 1 - CMakeLists.txt

set(EX1_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TRIE_SRC src/Trie.cpp)

# Main executable
add_executable(ex1_main main.cpp ${TRIE_SRC})
target_include_directories(ex1_main PRIVATE ${EX1_INCLUDE_DIR})

# Test executable
add_executable(ex1_tests tests/test_trie.cpp ${TRIE_SRC})
target_include_directories(ex1_tests PRIVATE ${EX1_INCLUDE_DIR})
target_link_libraries(ex1_tests PRIVATE catch2_amalgamated)
add_test(NAME Exercise1_TrieTests COMMAND ex1_tests)
