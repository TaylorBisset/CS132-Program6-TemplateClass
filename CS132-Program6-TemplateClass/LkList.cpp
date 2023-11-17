// LkList.cpp

/*
Implements the LkList class for managing linked lists of strings.
It contains the actual code for the class's methods and functions.
*/

#include "LkList.h"

template <typename T>
LkList<T>::LkList() 
{
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
}

template <typename T>
LkList<T>::~LkList() 
{ 
	clear();
}

template <typename T>
LkList<T>::LkList(LkList& other) 
{
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
	other.resetIterator();
	while (other.hasMore())
	insert_back(other.next());
}

template <typename T>
//LkList& LkList::operator=(const LkList& rhs){}
int LkList<T>::size() const 
{
	return count;
}

template <typename T>
bool LkList<T>::insert_back(const T& str) 
{
	if (count == 0) 
	{ // empty list
		head = tail = new Node<T>(str);
	}
	else 
	{ // >1 count, then add back
		Node<T>* temp = new Node<T>(str);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	count++;
	return true;
}

template <typename T>
bool LkList<T>::remove(const T& str) 
{
	Node<T>* temp = head;
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
			Node<T>* before = temp->prev;
			Node<T>* after = temp->next;
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

template <typename T>
bool LkList<T>::insert(const T& str) 
{
	bool didInsert = false;
	if (count == 0) 
	{ // empty list
		head = tail = new Node<T>(str);
		didInsert = true;
	}
	else if (count == 1) 
	{ // List only one node
		if (head->data != str) 
		{
			if (head->data < str) 
			{ // add at back
				tail = new Node<T>(str);
			}
			else if (head->data > str) 
			{ // add at front
				head = new Node<T>(str);
			}
			tail->prev = head;
			head->next = tail;
			didInsert = true;
		}
	}
	else 
	{ // List > one node
		Node<T>* temp = head;
		while (temp != nullptr && str > temp->data) 
		{
			temp = temp->next;
		}
		if (temp != nullptr && temp->data == str) // already in container
			return false;
		if (temp != nullptr) 
		{ // add before end
			Node<T>* before = temp->prev;
			Node<T>* after = temp;
			temp = new Node<T>(str);
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
			tail = new Node<T>(str);
			tail->prev = temp;
			temp->next = tail;
			didInsert = true;
		}
	}
	count += (didInsert ? 1 : 0);
	return didInsert;
}

template <typename T>
void LkList<T>::clear()
{
	while (head != nullptr)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
	count = 0;
}

template <typename T>
void LkList<T>::resetIterator() const 
{
	it = head;
}

template <typename T>
bool LkList<T>::hasMore() const 
{
	return (it != nullptr);
}

template <typename T>
T LkList<T>::next() const 
{   
	// best: const TBString& LkList::next() const
	//{
	//Node* temp = it; // better
	//it = it->next;
	//return TBString(temp->data);
	// "normal" not so good
	T str = it->data;
	it = it->next;
	return str;
}

template <typename T>
std::ostream& operator<<(std::ostream& outStr, const LkList<T>& lst)
{
	lst.resetIterator();
	while (lst.hasMore())
		outStr << lst.next() << " ";
	return outStr;
}

//void LkList::merge(LkList & src) 
//{
//}
