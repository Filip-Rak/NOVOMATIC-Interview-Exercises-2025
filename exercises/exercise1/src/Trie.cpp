#include "Trie.h"

Trie::Node::Node(bool terminal, const std::string& full_query)
	: terminal(terminal), full_query(full_query) {}

Trie::Trie()
	: root(std::make_unique<Node>()){}

void Trie::add_query(const std::string& query)
{
	// Process each character while advancing through nodes.
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

std::vector<std::string> Trie::get_prefixes(const std::string& prefix) const
{
	// Get to the end of the prefix.
	Node* tgt = root.get();
	for (char c : prefix)
	{
		auto it = tgt->children.find(c);
		if (it != tgt->children.end())
			tgt = it->second.get();
		else
			return {};
	}

	// Using DFS gather all terminal nodes starting from the prefix's end.
	std::vector<std::string> results;
	std::stack<const Node*> stack;
	stack.push(tgt);

	while (!stack.empty())
	{
		const Node* current = stack.top();
		stack.pop();

		// Add terminal's node querry.
		if (current->terminal)
			results.push_back(current->full_query);

		// Add all of these nodes's children to stack.
		for (auto& [_, next_node] : current->children)
			stack.push(next_node.get());
	}

	return results;
}
