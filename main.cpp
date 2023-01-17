#include <iostream>
#include <conio.h>
#include "trie.h"

int main(){
	
	TrieNode* storage = getNewNode();
	insert(storage, "category");
	insert(storage, "catalog");
	insert(storage, "city");
	insert(storage, "citro");
	insert(storage, "bag");
	insert(storage, "big");
	insert(storage, "bagage");
	insert(storage, "man");
	insert(storage, "map");
	insert(storage, "manual");
	insert(storage, "trigonometry");
	insert(storage, "trie");
	insert(storage, "trump");

	std::cout << "Let start enter the first letters of the word and click 'Enter':" << std::endl;
	bool online = true;
	std::string prefWord;
	while (online){
		std::cin >> prefWord;
		if (isNumeric(prefWord) || prefWord.empty()) continue;
		std::cout << std::endl;
		printoutWord(storage, prefWord);
		std::cout << std::endl;
		prefWord.clear();
	}
}