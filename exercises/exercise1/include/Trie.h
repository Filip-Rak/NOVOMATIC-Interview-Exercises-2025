#pragma once

#include <unordered_map>
#include <string>
#include <memory>

class Trie
{
	/* Types */
	struct Node
	{
		/* Attributes */
		bool terminal;
		std::string full_query;
		std::unordered_map<char, std::unique_ptr<Node>> children;

		/* Constructor */
		Node(bool terminal = false, const std::string& full_query = "");
	};

	/* Attributes */
	std::unique_ptr<Node> root;

public:
	/* Consturctor */
	Trie();

	/* Public Methods */
	void add_query(const std::string& query);
	std::vector<std::string> get_prefixes(const std::string& query) const;
};