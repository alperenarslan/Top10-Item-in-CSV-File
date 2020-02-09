#pragma once
#include "Linkedlist.h"

class Hashtable
{
	static const int tablesize = 20000;
	LinkedList table[tablesize];
	int hash(string filename);
	Node* top_ten[10];
public:

	Hashtable();
	~Hashtable();

	void insert(string f, string d, int q);

	void topten();
};

