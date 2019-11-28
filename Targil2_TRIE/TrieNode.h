#pragma once
class TrieNode
{
	public :
	
	
	
	bool EndOfWord ;
	TrieNode* parent;
	TrieNode* Children[26];//each index is referd to a letter

	TrieNode()
	{
		EndOfWord = false;
		parent = NULL;
		for (int j = 0; j < 26; j++)
		{
			Children[j] = NULL;
		}
	}
	


	~TrieNode()
	{
		for (int i = 0; i < 26; i++)
		{
			if (!Children[i])
			{
				delete Children[i];
				Children[i] = NULL;//activate dsctr in all children
			}
		}
	}
	
};

