#define CATCH_CONFIG_IMPLEMENTATION
#include <catch2/catch_all.hpp>

#include "Trie.h"

TEST_CASE("hello() returns correct message", "[trie]") 
{
    REQUIRE(hello() == "Hello from Trie");
}
