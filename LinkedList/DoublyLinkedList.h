#pragma once
#include "DNode.h"

class DoublyLinkedList
{
private:
	DNode* head;                            // first node
	DNode* tail;                            // last node: makes insertAtEnd O(1)

public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void insertAtFront(int value);
	void insertAtEnd(int value);
	void displayForward() const;    // Forward:  10 <-> 20 <-> 30 <-> NULL
	void displayBackward() const;   // Backward: 30 <-> 20 <-> 10 <-> NULL
	bool deleteValue(int value);            // first match; head, tail or middle
};
