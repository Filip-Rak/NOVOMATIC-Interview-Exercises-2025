#include "Trie.h"

Trie::Node::Node(bool terminal, const std::string& full_query)
	: terminal(terminal), full_query(full_query) {}

Trie::Trie()
	: root(std::make_unique<Node>()){}

void Trie::add_query(const std::string& query)
{
	// Add each character while advancing through nodes.
	Node* tgt = root.get();
	for (char c : query)
	{
		// Character is present -> advance. Character not present -> map it to a new node -> advance.
		auto [it, _] = tgt->children.try_emplace(c, std::make_unique<Node>());
		tgt = it->second.get();
	}

	// Mark the last inserted node as terminal.
	tgt->terminal = true;
	tgt->full_query = query;
}

std::vector<std::string> Trie::get_prefixes(const std::string& query) const
{
	
}
