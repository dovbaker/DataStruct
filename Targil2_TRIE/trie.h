#pragma once
#include <cstddef>

#include "TrieNode.h"
#include <string>
using namespace std;
class trie
{
private:
	TrieNode* root;
public:
	TrieNode* getRoot() { return root; }
	void insert(string word,TrieNode *);
	bool del(string word, TrieNode* ptr);
	TrieNode* search(string word, TrieNode*);
	bool HasflagOrSon(TrieNode* ptr);
	void printAutoSuggestions1(string PartOfWord);
	TrieNode* printAutoSuggestions2(string PartOfWord);
	void printAutoSuggestions3(TrieNode* ptr, char str[], int level,string PartOfword);
	trie();
	~trie()
	{
		delete root;
	}
	
	


};

