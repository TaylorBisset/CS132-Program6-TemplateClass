// LKList.h

/*
Contains the declaration of the LKList class for managing linked lists of strings.
It defines the structure and interface of the class.
*/

#ifndef LKLIST_H
#define LKLIST_H

#include <string>
#include "TBString.h"

using namespace std;
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

class LKList 
{
public:
	LKList();
	virtual ~LKList();
	LKList(LKList& other);
	// LKList& operator=(const LKList& other);

	bool insert(const TBString& str);
	bool insert_back(const TBString& str);

	bool remove(const TBString& str);

	//void merge(LKList & src);

	void resetIterator()const;
	bool hasMore()const;
	TBString next()const;

	int size() const;
	void clear();

private:
	Node* head, * tail;
	mutable Node* it;
	int count;
};

ostream& operator << (ostream& outStr, const LKList& lst);
#endif // LKLIST_H
