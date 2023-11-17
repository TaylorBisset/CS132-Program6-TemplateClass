// LkList.h

/*
Contains the declaration of the LkList class for managing linked lists of TBStrings.
Combining traditional linked list features with additional functionalities.
It includes the traditional Gang of Four plus features plus an output operator, 
and insertion, removal, and count functions. 
It also includes Iterator functions. These functions act to facilitate in list traversal.
*/

#ifndef LKLIST_H
#define LKLIST_H

#include <iostream>
#include <string>
#include "TBString.h"

template <typename T>
class Node 
{
public:
	Node();
	Node(T data);

	T data;
	Node* next;
	Node* prev;
};

template <typename T>
Node<T>::Node() : next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr), prev(nullptr) {}

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
std::ostream& operator<<(std::ostream& outStr, const LkList<T>& lst);

#endif // LKLIST_H
