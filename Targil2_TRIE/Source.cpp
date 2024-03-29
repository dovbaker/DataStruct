//dov baker 203301072
//david bretler 206301384
#include <iostream>
#include <list>
#include <string>
#include "trie.h"

using namespace std;


int main()
{

	char ch;
	string wrd;
	trie tr;
	

	cout << "\nTRIE PROGRAM" << endl;
	cout << "\nChoose one of the following" << endl;
	cout << "1: add a new item" << endl;
	cout << "2: delete an item" << endl;
	cout << "3: check if an item exists " << endl;
	cout << "4: complete the possible item name " << endl;
	cout << "5: exit " << endl;
	do
	{
		cin >> ch;

		switch (ch)
		{
		case '1':
			cout << "Enter a word to insert " << endl;
			cin >> wrd;
			tr.insert(wrd,tr.getRoot());
			break;
		case '2':
			cout << "Enter a word to del " << endl;
			cin >> wrd;
			if (!tr.del(wrd,tr.getRoot())) cout << "ERROR\n";
			break;
		case '3':
			cout << "Enter a word to search " << endl;
			cin >> wrd;
			if (tr.search(wrd,tr.getRoot()))
				cout << "exists\n";
			else
				cout << "does not exist\n";
			break;

		case '4':
			cout << "Enter a prefix to complete " << endl;
			cin >> wrd;
			
			 tr.printAutoSuggestions1(wrd);

			
				
			break;
		case '5':cout << "bye " << endl; break;
		default: cout << "ERROR " << endl;  break;
		}//switch
	} while (ch != '5');

	return 0;
}