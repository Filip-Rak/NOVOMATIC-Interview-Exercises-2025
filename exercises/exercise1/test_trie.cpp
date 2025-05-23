#include <catch2/catch_all.hpp>

#include "trie.h"

TEST_CASE("Single word insertion & prefix match", "[trie]")
{
	Trie trie;
	trie.add_query("apple");
	auto result = trie.get_prefixes("app");
	REQUIRE(result == std::vector<std::string>{"apple"});
}

TEST_CASE("Multiple insertions", "[trie]")
{
	Trie trie;
	trie.add_query("apple");
	trie.add_query("app");
	trie.add_query("application");
	trie.add_query("people");

	auto result = trie.get_prefixes("app");
	REQUIRE_THAT(
		result,
		Catch::Matchers::UnorderedEquals(std::vector<std::string>{"apple", "app", "application"})
	);
}

TEST_CASE("Prefix not found", "[trie]")
{
	Trie trie;
	trie.add_query("banana");

	auto result = trie.get_prefixes("app");
	REQUIRE(result.empty());
}

TEST_CASE("Empty prefix returns all inserted strings", "[trie]") {
	Trie trie;
	trie.add_query("dog");
	trie.add_query("door");
	trie.add_query("dorm");

	auto result = trie.get_prefixes("");
	REQUIRE_THAT(
		result, 
		Catch::Matchers::UnorderedEquals(std::vector<std::string>{"dog", "door", "dorm"})
	);
}

TEST_CASE("get_prefixes matches multiple word queries with shared prefix", "[trie]") 
{
	Trie trie;
	trie.add_query("Kiedy jest nowy rok w Chinach?");
	trie.add_query("Kiedy jest nowy rok w Tajlandii?");
	trie.add_query("Nowy rok?");

	auto result = trie.get_prefixes("Kiedy jest nowy rok");
	REQUIRE_THAT(
		result,
		Catch::Matchers::UnorderedEquals(
			std::vector<std::string>{"Kiedy jest nowy rok w Chinach?", "Kiedy jest nowy rok w Tajlandii?"}
		));
}

TEST_CASE("Trie is case insensitive", "[trie]")
{
	Trie trie;
	trie.add_query("caRt");
	trie.add_query("car");
	trie.add_query("CArTMAN");
	trie.add_query("cRab");

	auto result = trie.get_prefixes("cA");
	REQUIRE_THAT(
		result,
		Catch::Matchers::UnorderedEquals(
			std::vector<std::string>{"caRt", "car", "CArTMAN"}
		));
}