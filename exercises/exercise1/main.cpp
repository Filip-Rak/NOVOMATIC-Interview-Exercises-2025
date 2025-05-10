#include <iostream>
#include <string>

#include "Trie.h"

void handle_input(const std::string& line, Trie& trie)
{
	// Define commands.
	const std::string ADD_COMMAND = "add: ";
	const std::string QUERY_COMMAND = "ask: ";

	if (line.starts_with(ADD_COMMAND))
	{
		// Extract the query & eliminate whitespaces.
		std::string query = line.substr(ADD_COMMAND.size());
		query.erase(0, query.find_first_not_of(' '));

		// Execute the command.
		trie.add_query(query);
	}
	else if (line.starts_with(QUERY_COMMAND))
	{
		// Extract the query & eliminate whitespaces.
		std::string query = line.substr(QUERY_COMMAND.size());
		query.erase(0, query.find_first_not_of(' '));

		// Execute the command & print the result.
		auto results = trie.get_prefixes(query);
		for (const std::string& result : results)
			std::cout << "result: " << result << "\n";
	}
}

int main()
{
	Trie trie;

	std::string line;
	while (std::getline(std::cin, line))
	{
		handle_input(line, trie);
	}
}