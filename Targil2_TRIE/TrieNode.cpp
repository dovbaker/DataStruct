#include "TrieNode.h"

TrieNode::TrieNode()
{
	for (size_t j = 0; j < 26; j++)
	{
		Children[j]=nullptr;
	}
}
