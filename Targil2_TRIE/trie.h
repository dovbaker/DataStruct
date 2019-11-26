#pragma once
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
	trie();
	~trie()
	{
		delete root;
	}
	
	


};

