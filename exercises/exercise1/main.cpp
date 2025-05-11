/*	Exercise 1: szukajka.pl's search engine admin
*	----------------------------------------------
*	Autor: Filip Rak
* 
*	Description:
*		Implements a simple search engine suggestion module using a Trie,
*		allowing for prefix-based autocomplete.
* 
*	Input:
*		- "add: [query]" -> Add the query to trie. 
*		- "ask: [query]" -> Get all querries matching the prefix.
*		- whitespaces between the end of the command and the start of the query will be ignored.
* 
*	Output: 
*		- each [ask query] will be followed by every output mathcing the prefix
*		  in format: result: [matching query]
* 
*	Notes:
*     - Implementation is split into trie.h and trie.cpp in this directory.
*/

#include <iostream>
#include <string>

#include "trie.h"

void handle_input(const std::string& line, Trie& trie)
{
	// Define commands.
	const std::string COMMAND_ADD = "add:";
	const std::string COMMAND_ASK = "ask:";

	if (line.starts_with(COMMAND_ADD))
	{
		// Extract the query & eliminate whitespaces.
		std::string query = line.substr(COMMAND_ADD.size());
		query.erase(0, query.find_first_not_of(' '));

		// Execute the command.
		trie.add_query(query);
	}
	else if (line.starts_with(COMMAND_ASK))
	{
		// Extract the query & eliminate whitespaces.
		std::string query = line.substr(COMMAND_ASK.size());
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