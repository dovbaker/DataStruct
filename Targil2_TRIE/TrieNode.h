#pragma once
class TrieNode
{
	public :
	
	
	
	bool EndOfWord = false;
	TrieNode* parent=nullptr;
	TrieNode ** Children = new  TrieNode * [26];//each index is referd to a letter
	TrieNode();
		


	~TrieNode()
	{
		for (size_t i = 0; i < 26; i++)
		{
			if (!Children[i])
			{
				delete Children[i];
				Children[i] = nullptr;//activate dsctr in all children
			}
		}
		delete Children;
		Children = nullptr;
	}
	
};

