#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedList::insertAtFront(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

void LinkedList::display() const {
	for (Node* cur = head; cur != nullptr; cur = cur->next)
		cout << cur->data << "->";
	cout << "NULL" << endl;
}

bool LinkedList::isEmpty() const {
	return head == nullptr;
}

// ===================== Week 3 =====================

// Q2: new node becomes the last node
void LinkedList::insertAtEnd(int value) {
	Node* newNode = new Node;		// (1) allocate
	newNode->data = value;			// (2) set data
	newNode->next = nullptr;		// (3) last node has no successor

	if (head == nullptr) {			// empty list: new node is the head
		head = newNode;
		return;
	}

	Node* cur = head;				// walk to the last node
	while (cur->next != nullptr)
		cur = cur->next;
	cur->next = newNode;			// (4) predecessor -> new node
}

// Q2: number of nodes
int LinkedList::length() const {
	int count = 0;
	for (Node* cur = head; cur != nullptr; cur = cur->next)
		count++;
	return count;
}

// Q2: call insertAtEnd() for every element
void LinkedList::createFromArray(const int arr[], int n) {
	for (int i = 0; i < n; i++)
		insertAtEnd(arr[i]);
}

// Q3: index of the first match or -1
int LinkedList::search(int value) const {
	int index = 0;
	for (Node* cur = head; cur != nullptr; cur = cur->next) {	// also checks the last node
		if (cur->data == value)
			return index;
		index++;
	}
	return -1;						// not found (0 is a valid index)
}

// Q4: change EVERY matching node, return how many were changed
int LinkedList::update(int oldValue, int newValue) {
	int changed = 0;
	for (Node* cur = head; cur != nullptr; cur = cur->next) {	// no break
		if (cur->data == oldValue) {
			cur->data = newValue;
			changed++;
		}
	}
	return changed;
}

// Q5: 0-based, index == 0 -> front, index == length() -> end
bool LinkedList::insertAt(int index, int value) {
	if (index < 0 || index > length())
		return false;				// list unchanged

	Node* newNode = new Node;
	newNode->data = value;

	if (index == 0) {				// new first node: head changes
		newNode->next = head;
		head = newNode;
		return true;
	}

	Node* prev = head;				// node at position index - 1
	for (int i = 0; i < index - 1; i++)
		prev = prev->next;

	newNode->next = prev->next;		// (3) new node -> successor
	prev->next = newNode;			// (4) predecessor -> new node
	return true;
}

// Q6: remove the first node with that value and free its memory
bool LinkedList::deleteValue(int value) {
	if (head == nullptr)			// empty list
		return false;

	if (head->data == value) {		// head node
		Node* victim = head;
		head = head->next;
		delete victim;
		return true;
	}

	Node* prev = head;				// middle or last node
	while (prev->next != nullptr && prev->next->data != value)
		prev = prev->next;

	if (prev->next == nullptr)		// value not found
		return false;

	Node* victim = prev->next;
	prev->next = victim->next;		// bypass
	delete victim;					// free memory (no leak)
	return true;
}

// Q7: move all nodes of otherList to the end of this list, then empty otherList
void LinkedList::merge(LinkedList& otherList) {
	if (this == &otherList || otherList.head == nullptr)
		return;

	if (head == nullptr) {			// this list is empty
		head = otherList.head;
	}
	else {
		Node* cur = head;			// last node of this list
		while (cur->next != nullptr)
			cur = cur->next;
		cur->next = otherList.head;	// move the nodes, no copy
	}
	otherList.head = nullptr;		// otherList no longer owns them (no double delete)
}
