#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { //write your answer here
	int i; //variable
	string ilzam; //character
	cout << "\enter the rollnumber of the student: "; //output
	cin >> i; //save to variable i
	cout << "\rnter the name of the student: "; //output
	cin.ignore();
	getline(cin, ilzam);
	Node* newnode = new Node();
	newnode->rollNumber = i; //mengarahkan newnode ke rollNumber
	newnode->name = ilzam; //mengarahkan newnode ke name  

	if (LAST == NULL || i <= LAST->rollNumber) {
		if (LAST != NULL && i == LAST->rollNumber) {
			cout << "\n duplicate number no allowed" << endl; //output
			return; //pengembali nilai
		}
		newnode->next = LAST;
		if (LAST != NULL);
		LAST = newnode;
		return; //pengembali nilai
	}

	Node* current = LAST;
	while (current->next != NULL && i > current->next->rollNumber)
		current = current->next;

	if (current->next != NULL && i > current->next->rollNumber) {
		cout << "\ndublicate roll numbers not allowed" << endl;
		return; //pengembali nilai
	}

	newnode->next = current->next;
	if (current->next != NULL)
		current->next = newnode; //mengarahkan current ke newnode
	current->next = newnode;
}
bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;
	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //write your answer here
	Node* previous, * current; //delnode untuk menghapus
	previous = current = NULL;
		return false;
	if (current->next != NULL)
	if (previous != NULL)
		previous->next = current->next;
	else
		LAST = current->next;
	delete current;
	return true;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
			}
			case '2': {
				obj.delNode();
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}