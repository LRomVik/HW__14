#pragma once
#include <string>

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    int freq;
};

TrieNode* getNewNode(void);
bool isNumeric(std::string const& str);
void insert(TrieNode*, std::string);
bool search(TrieNode*, std::string);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, std::string, int depth);
void findMinPrefixes(TrieNode*, char[], int, std::string&);
void autoComplete(TrieNode*, std::string);
void printoutWord(TrieNode*, const std::string);

