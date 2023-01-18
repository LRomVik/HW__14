#include "Trie.h"
#include <iostream>

TrieNode* getNewNode() {

	TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;
	pNode->freq = 1;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;

	return pNode;
}


bool isNumeric(std::string const& str) {

	auto it = str.begin();
	while (it != str.end() && std::isdigit(*it))
		it++;
	return !str.empty() && it == str.end();
}


void insert(TrieNode* root, std::string key) {

	TrieNode* node = root;

	for (int i = 0; i < key.length(); i++) {

		int index = key[i] - 'a';

		if (!node->children[index])
			node->children[index] = getNewNode();
		else {
			(node->children[index]->freq)++;
		}
        node = node->children[index];
	}
	node->isEndOfWord = true;
}
bool search(TrieNode* root, std::string key) {

	TrieNode* node = root;

	for (int i = 0; i < key.length(); i++) {

		int index = key[i] - 'a';
		if (!node->children[index])
			return false;

		node = node->children[index];
	}
        return (node != nullptr && node->isEndOfWord);
}
bool isEmpty(TrieNode* root) {

	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return false;
	return true;
}
TrieNode* remove(TrieNode* root, std::string key, int depth = 0) {

	if (!root)
		return nullptr;

	if (depth == key.size()) {

		if (root->isEndOfWord)
			root->isEndOfWord = false;

		if (isEmpty(root)) {
			delete (root);
			root = nullptr;
		}
        return root;
	}
	int index = key[depth] - 'a';
	root->children[index] = remove(root->children[index], key, depth + 1);

	if (isEmpty(root) && root->isEndOfWord == false) {
		delete (root);
		root = nullptr;
	}
	return root;
}
void findMinPrefixes(TrieNode* root, char buf[], int ind, std::string& res) {

	if (ind == 0) {
		root->freq = 0;
	}
    if (root == nullptr)
		return;

	if (root->freq == 1) {

		buf[ind] = '\0';
		res += buf;
		res += ' ';
		std::cout << buf << " ";
		return;
	}
    for (int i = 0; i < ALPHABET_SIZE; i++) {

		if (root->children[i] != nullptr) {

			buf[ind] = i + 'a';
			std::cout << (int)buf[ind];
			findMinPrefixes(root->children[i], buf, ind + 1, res);
		}
	}
}
//Вывод слов из словаря
void autoComplete(TrieNode* root, std::string wordPrefix) {

	if (root->isEndOfWord)
        std::cout << wordPrefix << std::endl;

	for (int i = 0; i < ALPHABET_SIZE; i++)

		if (root->children[i]) {

			char child = 'a' + i;
			autoComplete(root->children[i], wordPrefix + child);
		}
}
//Поиск в префиксном дереве конца префикса введенного
void printoutWord(TrieNode* root, const std::string query) {

	TrieNode* current = root;
	for (char a : query) {

		int ind = a - 'a';

		if (!current->children[ind]) {
			std::cout << "No words found in the library" << std::endl;
			return;
		}
        current = current->children[ind];
	}
    autoComplete(current, query);
}

