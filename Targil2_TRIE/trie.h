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
	void del(string word, TrieNode* ptr);
	TrieNode* search(string word, TrieNode*);
	bool IsflagOrHasSon(TrieNode* ptr);
	trie();
	~trie()
	{
		delete root;
	}
	
	


};

