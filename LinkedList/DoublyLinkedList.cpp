#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
	DNode* cur = head;
	while (cur != nullptr)
	{
		DNode* nextNode = cur->next;
		delete cur;
		cur = nextNode;
	}
	head = nullptr;
	tail = nullptr;
}

void DoublyLinkedList::insertAtFront(int value)
{
	DNode* newNode = new DNode;
	newNode->data = value;
	newNode->prev = nullptr;                 // it becomes the first node
	newNode->next = head;

	if (head == nullptr)                     // empty list: also the last node
		tail = newNode;
	else
		head->prev = newNode;

	head = newNode;
}

void DoublyLinkedList::insertAtEnd(int value)
{
	DNode* newNode = new DNode;
	newNode->data = value;
	newNode->next = nullptr;                 // it becomes the last node
	newNode->prev = tail;

	if (tail == nullptr)                     // empty list: also the first node
		head = newNode;
	else
		tail->next = newNode;

	tail = newNode;                          // O(1) thanks to tail
}

void DoublyLinkedList::displayForward() const
{
	cout << "Forward:  ";
	for (DNode* cur = head; cur != nullptr; cur = cur->next)
		cout << cur->data << " <-> ";
	cout << "NULL" << endl;
}

void DoublyLinkedList::displayBackward() const
{
	cout << "Backward: ";
	for (DNode* cur = tail; cur != nullptr; cur = cur->prev)
		cout << cur->data << " <-> ";
	cout << "NULL" << endl;
}

bool DoublyLinkedList::deleteValue(int value)
{
	DNode* victim = head;
	while (victim != nullptr && victim->data != value)
		victim = victim->next;

	if (victim == nullptr)                   // empty list or not found
		return false;

	if (victim->prev != nullptr)             // not the head
		victim->prev->next = victim->next;
	else
		head = victim->next;                 // it was the head

	if (victim->next != nullptr)             // not the tail
		victim->next->prev = victim->prev;
	else
		tail = victim->prev;                 // it was the tail

	delete victim;
	return true;
}
