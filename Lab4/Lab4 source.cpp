#include <iostream>

using namespace std;
struct nodeType
{
	char letter;
	nodeType* prev;
	nodeType* next;
};

void createList(nodeType*& first, nodeType*& last);
void printList(nodeType*& first);
void reversePrintList(nodeType*& last);
//void insertNode(nodeType*& first, char letter);

int main()
{
	nodeType* first,* last;
	char letter;

	createList(first, last);

	//cout << "Enter a letter to insert" << endl;
	//cin >> letter;
	//insertNode(first, letter);
	printList(first);
	reversePrintList(last);

	system("PAUSE");
	return 0;
}

void createList(nodeType*& first, nodeType*& last) {

	char letter;
	nodeType* newNode, * current;

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

	while (letter != 'z') {
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
		letter = newNode->letter;
		cout << endl;
	}
	/*char letter;
	nodeType* newNode, * current;

	first = NULL;
	last = NULL;*/



	///*cout << "Enter a letter (Enter 0 to stop)." << endl;
	//cin >> letter;
	//cout << endl;*/

	//newNode = new nodeType;
	//newNode->prev = NULL;
	//newNode->next = NULL;
	//cout << "Enter a letter (Enter ! to stop)." << endl;
	//cin >> letter;
	////newNode->letter = letter;
	//cout << endl;

	//while (letter != '!') {
	//	
	//	current = new nodeType;
	//	current->prev = newNode;
	//	current->next = NULL;
	//	newNode = current;

	//	if (first == NULL) {
	//		first = newNode;
	//		last = newNode;
	//	}
	//	else {
	//		last->next = newNode;
	//		last = newNode;
	//	}

	//	cout << "Enter a letter (Enter ! to stop)." << endl;
	//	cin >> letter;
	//	cout << endl;
	//}
}

void printList(nodeType*& first) {
	nodeType* current = new nodeType;
	current = first;
	while (current != NULL) {
		cout << current->letter << endl;
		current = current->next;
	}
}

void reversePrintList(nodeType*& last) {
	nodeType* current = new nodeType;
	current = last;

	while (current != NULL) {
		cout << current->letter << endl;
		current = current->prev;
	}
}