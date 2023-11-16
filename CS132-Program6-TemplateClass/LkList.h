// LKList.h

/*
Contains the declaration of the LKList class for managing linked lists of strings.
It defines the structure and interface of the class.
*/

#ifndef LKLIST_H
#define LKLIST_H

#include <iostream>
#include "TBString.h"

template <typename T>
class Node 
{
public:
	Node() 
	{
		next = prev = nullptr;
	}
	Node(TBString num) 
	{
		data = num;
		next = prev = nullptr;
	}

	TBString data;
	Node* next;
	Node* prev;
};

template <typename T>
class LKList 
{
public:
	LKList();
	virtual ~LKList();
	LKList(LKList& other);
	// LKList& operator=(const LKList& other);

	bool insert(const T& str);
	bool insert_back(const T& str);

	bool remove(const T& str);

	//void merge(LKList & src);

	void resetIterator()const;
	bool hasMore()const;
	T next()const;

	int size() const;
	void clear();

private:
	Node<T>* head, * tail;
	mutable Node<T>* it;
	int count;
};

template <typename T>
ostream& operator << (ostream& outStr, const LKList<T>& lst);
#endif // LKLIST_H
