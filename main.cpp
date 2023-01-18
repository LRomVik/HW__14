#include <iostream>
#include <conio.h>
#include "trie.h"

int main(){
	
	TrieNode* library = getNewNode();
	insert(library, "category");
	insert(library, "catalog");
	insert(library, "city");
	insert(library, "citro");
	insert(library, "bag");
	insert(library, "big");
	insert(library, "bagage");
	insert(library, "man");
	insert(library, "map");
	insert(library, "manual");
	insert(library, "trigonometry");
	insert(library, "trie");
	insert(library, "trump");

	std::cout << "Let start to write in Latin first letters of the word and click 'Enter':" << std::endl;
	bool enter = true;
	std::string prefWord;
	while (enter){
		std::cin >> prefWord;
		if (isNumeric(prefWord) || prefWord.empty()) continue;
		std::cout << std::endl;
		printoutWord(library, prefWord);
		std::cout << std::endl;
	}
}