// LkList.cpp

/*
Implements the LkList class for managing linked lists of strings.
It contains the actual code for the class's methods and functions.
*/

#include "LkList.h"
#include <iostream>
using namespace std;
LKList::LKList() 
{
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
}
LKList::~LKList() 
{ 
	//TODO need to write this destructor
}
LKList::LKList(LKList& other) 
{
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
	other.resetIterator();
	while (other.hasMore())
	insert_back(other.next());
}
//LKList& LKList::operator=(const LKList& rhs){}
int LKList::size() const 
{
	return count;
}
bool LKList::insert_back(const TBString& str) 
{
	if (count == 0) 
	{ // empty list
		head = tail = new Node(str);
	}
	else 
	{ // >1 count, then add back
		Node* temp = new Node(str);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	count++;
	return true;
}
bool LKList::remove(const TBString& str) 
{
	Node* temp = head;
	bool removed = false;
	if (count == 0)
		return false;
	else if (count == 1) 
	{
		if (temp->data == str) 
		{
			head = tail = nullptr;
			removed = true;
		}
	}
	else if (tail->data == str) 
	{
		temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		removed = true;
	}
	else if (head->data == str) 
	{
		temp = head;
		head = head->next;
		head->prev = nullptr;
		removed = true;
	}
	else 
	{
		while (temp != nullptr && temp->data != str)
			temp = temp->next;
		if (temp != nullptr && temp->data == str) 
		{ // found target in middle
			Node* before = temp->prev;
			Node* after = temp->next;
			before->next = after;
			after->prev = before;
			removed = true;
		}
		else 
		{
			removed = false;
		}
	}
	if (removed == true) 
	{
		delete temp;
		--count;
	}
	return removed;
}
bool LKList::insert(const TBString& str) 
{
	bool didInsert = false;
	if (count == 0) 
	{ // empty list
		head = tail = new Node(str);
		didInsert = true;
	}
	else if (count == 1) 
	{ // List only one node
		if (head->data != str) 
		{
			if (head->data < str) 
			{ // add at back
				tail = new Node(str);
			}
			else if (head->data > str) 
			{ // add at front
				head = new Node(str);
			}
			tail->prev = head;
			head->next = tail;
			didInsert = true;
		}
	}
	else 
	{ // List > one node
		Node* temp = head;
		while (temp != nullptr && str > temp->data) 
		{
			temp = temp->next;
		}
		if (temp != nullptr && temp->data == str) // already in container
			return false;
		if (temp != nullptr) 
		{ // add before end
			Node* before = temp->prev;
			Node* after = temp;
			temp = new Node(str);
			if (before != nullptr) 
			{ // insert
				before->next = temp;
				temp->prev = before;
			}
			else 
			{
				head = temp;
			}
			after->prev = temp;
			temp->next = after;
			didInsert = true;
		}
		else 
		{ // add after tail
			temp = tail;
			tail = new Node(str);
			tail->prev = temp;
			temp->next = tail;
			didInsert = true;
		}
	}
	count += (didInsert ? 1 : 0);
	return didInsert;
}
void LKList::clear() 
{
	if (count == 0)
		return;
	while (tail != head) 
	{
		tail = tail->prev;
		delete tail->next;
	}
	delete head;
	head = tail = nullptr;
	count = 0;
}
void LKList::resetIterator() const 
{
	it = head;
}
bool LKList::hasMore() const 
{
	return (it != nullptr);
}
TBString LKList::next() const 
{ // best: const TBString& LKList::next() const
	//{
	//Node* temp = it; // better
	//it = it->next;
	//return TBString(temp->data);
	// "normal" not so good
	TBString str = it->data;
	it = it->next;
	return str;
}
ostream& operator << (ostream& outStr, const LKList& lst) 
{
	lst.resetIterator();
	while (lst.hasMore())
		outStr << lst.next() << " ";
	return outStr;
}
//void LKList::merge(LKList & src) 
//{
//}
