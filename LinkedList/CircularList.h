#pragma once
#include "Node.h"                           // same Node as LinkedList

// Singly linked list whose last node points back to the first node
class CircularList
{
private:
	Node* head;                             // nullptr = empty ring

public:
	CircularList();
	~CircularList();                        // must break the ring first!

	void append(int value);                 // new node becomes the last node
	void display() const;                   // 7 -> 2 -> 5 -> 4 -> (back to 7)
	int  length() const;
};
