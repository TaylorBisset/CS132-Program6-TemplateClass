// LkList.h

/*
Contains the declaration of the LkList class for managing linked lists of strings.
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
class LkList 
{
public:
	LkList();
	virtual ~LkList();
	LkList(LkList& other);
	// LkList& operator=(const LkList& other);

	bool insert(const T& str);
	bool insert_back(const T& str);

	bool remove(const T& str);

	//void merge(LkList & src);

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
std::ostream& operator << (std::ostream& outStr, const LkList<T>& lst);


#endif // LKLIST_H

#include "LkList.cpp"
