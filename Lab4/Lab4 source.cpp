#include <iostream>

using namespace std;
struct nodeType
{
	char letter;
	nodeType* prev;
	nodeType* next;
};

void createList(nodeType*& first, nodeType*& last);


int main()
{
	nodeType* first,* last;

	createList(first, last);

	

	system("PAUSE");
	return 0;
}

void createList(nodeType*& first, nodeType*& last) {

	char letter;
	nodeType* newNode,* current; 

	first = NULL;
	last = NULL;

	cout << "Enter a letter (Enter 0 to stop)." << endl;
	cin >> letter;
	cout << endl;

	newNode = new nodeType;
	newNode->prev = NULL;
	newNode->next = NULL;
	cout << "Enter a letter (Enter 0 to stop)." << endl;
	cin >> newNode->letter;
	cout << endl;

	while (letter != '0') {
		current = new nodeType;
		current->prev = newNode;
		current->next = NULL;
		newNode = current;

		if (first == NULL) {
			first = newNode;
			last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}

		cout << "Enter a letter (Enter 0 to stop)." << endl;
		cin >> newNode->letter;
		cout << endl;
	}


}