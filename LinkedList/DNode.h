#pragma once

// One element of a doubly linked list
struct DNode
{
	int    data;
	DNode* prev;                            // previous node (nullptr = first)
	DNode* next;                            // next node     (nullptr = last)
};
