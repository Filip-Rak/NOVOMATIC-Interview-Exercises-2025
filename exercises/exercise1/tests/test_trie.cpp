#define CATCH_CONFIG_IMPLEMENTATION
#include "catch_amalgamated.hpp"

#include "Trie.h"

TEST_CASE("hello() returns correct message", "[trie]") {
    REQUIRE(hello() == "Hello from Trie");
}
