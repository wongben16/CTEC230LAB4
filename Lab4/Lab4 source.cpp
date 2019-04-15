#include <iostream>

using namespace std;
struct nodeType
{
	int number;
	nodeType* prev;
	nodeType* next;
};

void createList(nodeType*& first, nodeType*& last);
void displayList(nodeType*& first);
void displayListReverse(nodeType*& last);
void insertNode(nodeType*& first, nodeType*& last, int num);
void deleteNode(nodeType*& first, nodeType*& last, int num);

int main()
{
	nodeType* first,* last;
	char letter;

	createList(first, last);

	deleteNode(first, last, 25); // case 1 – can’t delete from an empty list
	insertNode(first, last, 37); // case 1- insert into empty
	insertNode(first, last, 14); // case 2 – insert beginning of non-empty list
	insertNode(first, last, 68); // case 3A – insert at end of list of non-empty list
	insertNode(first, last, 47); // case 3B – insert middle of non-empty list
	displayList(first); // if your “insert” function works, it will display sorted/order
	deleteNode(first, last, 32); // case 4 – item not in list
	deleteNode(first, last, 47); // case 3 – item in middle of list
	displayList(first);
	displayListReverse(last);
	deleteNode(first, last, 14); // case 2 – item to delete at front of list
	displayList(first);
	displayListReverse(last);

	system("PAUSE");
	return 0;
}

void createList(nodeType*& first, nodeType*& last) {

	int num;
	nodeType* newNode, * current;

	first = NULL;
	last = NULL;

	cout << "Enter a letter (Enter -999 to stop)." << endl;
	cin >> num;
	cout << endl;

	newNode = new nodeType;
	newNode->prev = NULL;
	newNode->next = NULL;
	cout << "Enter a letter (Enter -999 to stop)." << endl;
	cin >> newNode->number;
	cout << endl;

	while (num != -999) {
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

		cout << "Enter a letter (Enter -999 to stop)." << endl;
		cin >> newNode->number;
		num = newNode->number;
		cout << endl;
	}

	//IGNORE BAD CODE DOESNT WORK                                                                                                                                                           
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

void displayList(nodeType*& first) {
	nodeType* current = new nodeType;
	current = first;
	while (current != NULL) {
		cout << current->number << endl;
		current = current->next;
	}
}

void displayListReverse(nodeType*& last) {
	nodeType* current = new nodeType;
	current = last;

	while (current != NULL) {
		cout << current->number << endl;
		current = current->prev;
	}
}


void insertNode(nodeType*& first, nodeType*& last, int num) {
	nodeType* current = new nodeType;
	current = first;

	if (num = 37) {
		current->number = 37;
		current->prev = NULL;
		current->next = NULL;
		first = current;
		last = current;
	}
	else if (num = 14) {
		current->number = 14;
		current->prev = NULL;
		current->next = first;
		first = current;
	}
	else if (num = 68) {
		current->number = 68;
		current->prev = current->next->next;
		current->next = NULL;
		last = current;
	}
	else {
		current->number = 47;
		current->prev = current->next;
		current->next = current->next->next;
	}

}

void deleteNode(nodeType*& first, nodeType*& last, int num) {
	nodeType* current = new nodeType;
	current = first;
	
	while (current->number != num) {
		current = current->next;
		if (current->next == NULL) {
			cout << "Cannot delete non existing node." << endl;
		}
	}

	if (num = 47) {
		while (first->number != 47) {
			first = first->next;
		}
		while (last->number != 47) {
			last = last->prev;
		}
		current = first;
		first = first->prev;
		first->next = first->next->next;
		last = last->next;
		last->prev = last->prev->prev;
	}


}