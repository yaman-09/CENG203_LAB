#include "CircularList.h"
#include <iostream>
using namespace std;

CircularList::CircularList()
{
	head = nullptr;
}

CircularList::~CircularList()
{
	if (head == nullptr)
		return;

	// break the ring first: delete from head->next until we are back at head
	Node* cur = head->next;
	while (cur != head)
	{
		Node* nextNode = cur->next;
		delete cur;
		cur = nextNode;
	}
	delete head;
	head = nullptr;
}

void CircularList::append(int value)
{
	Node* newNode = new Node;
	newNode->data = value;

	if (head == nullptr)                     // empty ring: the only node points to itself
	{
		newNode->next = newNode;
		head = newNode;
		return;
	}

	Node* last = head;                       // last node = the one whose next is head
	while (last->next != head)
		last = last->next;

	newNode->next = head;                    // new last node points back to head
	last->next = newNode;
}

void CircularList::display() const
{
	if (head == nullptr)
	{
		cout << "(empty ring)" << endl;
		return;
	}

	Node* cur = head;
	do
	{
		cout << cur->data << " -> ";
		cur = cur->next;
	} while (cur != head);
	cout << "(back to " << head->data << ")" << endl;
}

int CircularList::length() const
{
	if (head == nullptr)
		return 0;

	int count = 0;
	Node* cur = head;
	do
	{
		count++;
		cur = cur->next;
	} while (cur != head);
	return count;
}
