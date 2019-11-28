#include "trie.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

	void trie::insert(string word,TrieNode* ptr)
	{
		/*transform (word.begin(), word.end(), word.begin(),
			[](unsigned char c) { return std::tolower(c); });*/
		
		for (int i = 0; i < word.length(); i++)
		{
			if (!ptr->Children[word[i] - 97])
			{
				
				ptr->Children[word[i] - 97] = new TrieNode();
				ptr->Children[word[i] - 97]->parent = ptr;
			}
			if(i<word.length()-1)
			ptr = ptr->Children[word[i] - 97];
		}
		
		ptr->Children[word[word.length()-1]-97]->EndOfWord=true;

	}

	bool trie::del(string word, TrieNode* ptr)
	{
	//	transform(word.begin(), word.end(), word.begin(),//converts to lower case
	//		[](unsigned char c) { return std::tolower(c); });

		//a pointer to the last letter
		TrieNode* LastLetter = search(word, ptr);


		//if the word dos not exsist
		if (!search(word, ptr))
			return false;

		//if the word is a prefix of a other word delete only the flag
		for (int i = 0; i < 26; i++)
		{
			if (LastLetter->Children[i])//cheacking if the end of the word has a son
			{
				LastLetter->EndOfWord = false;
				return true;
			}
		}

		//deletes the word from bottom up each ,itration we cheak if the parent has a son or a flag
		int counter = 0;
		TrieNode* current = LastLetter;
		while (!HasflagOrSon(current->parent) && current->parent != root)
		{
			counter++;
			current = current->parent;
		}
		current->parent->Children[word[counter]-'a'] = NULL;
		delete current;

	}
		

	
	TrieNode* trie::search(string word, TrieNode* ptr)
	{
		//transform(word.begin(), word.end(), word.begin(),//converts to lower case
		//	[](unsigned char c) { return std::tolower(c); });

		for (int i = 0; i < word.length(); i++)//scan the tree 
		{
			if ((ptr->Children[word[i] - 97]))//if the leaf represnting the letter is not NULL 
				{
				if ((i < word.length() - 1))
					ptr = ptr->Children[word[i] - 97];//move on to the next letter
				}
			else
				return false;
		}
		if (ptr->Children[word[word.length()-1] - 97] &&
			ptr->Children[word[word.length()-1] - 97]->EndOfWord)
			//check if the last letter is a end of word

			return	ptr->Children[word[word.length()-1] - 97];
		return NULL;
				
	}
	//cheks if the node is end of word or has a son 
	bool trie::HasflagOrSon(TrieNode* ptr)
	{
		int counter = 0;
		if (ptr->EndOfWord)
			return true; 

		for (int i = 0; i < 26; i++)
		{
			if (ptr->Children[i])//cheacking if the end of the word has a son
			{
				counter++;
				if (counter>1)
				return true;
			}
		}
		return false;
	}

	  void trie::printAutoSuggestions1(string PartOfWord)
	{
		  char str[50];
		  for (int i = 0; i < PartOfWord.length(); i++)
		  {
			  str[i] = PartOfWord[i];
		  }
		  if(printAutoSuggestions2(PartOfWord))
		  printAutoSuggestions3(  printAutoSuggestions2(PartOfWord),str,0, PartOfWord);

		
	}
	  //gets a string and returns a poniter to the node ending with the lasst letter 
	 TrieNode* trie::printAutoSuggestions2(string PartOfWord)
	{
		 TrieNode* ptr = root;
		 for (int i = 0; i < PartOfWord.length(); i++)
		 {
			 if ((ptr->Children[PartOfWord[i] - 97]))
			 {
				 ptr = ptr->Children[PartOfWord[i] - 97];
			 }
			 else
			 {
				 cout << "No string exist with this prefix\n";
				 return NULL;
			 }
		 }
		 return ptr;

	}
	 //cheaks if the node is a leaf 
	 bool isLeafNode(TrieNode* ptr)
	 {
		 int  counter = 0;
		 	 for (int j = 0; j < 26; j++)
		 	 {
		 		 if (ptr->Children[j])//cheacking if the end of the word has a son
		 		 {
		 			 counter++;	
					 break;
		 		 }
		 	 }
			 if (counter == 0)
				 return true;
			 return false;

	 }
	 //prints the words on the 
	 void trie::printAutoSuggestions3(TrieNode* ptr, char str[], int level,string PartOfword)
	 {

		
			 // If node is leaf node, it means end of string, so a null  is added and string is printed	 
		 if (isLeafNode(ptr))
			 {
				 str[level] = '\0';
				 cout<< PartOfword << str << endl;
			 }

			 
			 for (int i = 0; i < 26; i++)
			 {
				 // if  child is found 
				 // add parent key to str and 
				 // call the print function recursively 
				 // for child node 
				 if (ptr->Children[i])
				 {
					 str[level] = i + 'a';
					 printAutoSuggestions3(ptr->Children[i], str, level + 1, PartOfword);
				 }
			 }
		 
		
	 }

	trie::trie()
	{
	root = new TrieNode;
	}
