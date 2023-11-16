// double_linked_list.cpp

/*
Implements the DoubleLinkedList class for managing linked lists of strings.
It contains the actual code for the class's methods and functions.
*/

#include "double_linked_list.h"

// Default constructor
DoubleLinkedList::DoubleLinkedList()
	:
	head(nullptr), tail(nullptr), it(nullptr), count(0)
{

}

// Copy constructor
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& dll)
	:
	head(nullptr), tail(nullptr), it(nullptr), count(0)
{
	Node* current = dll.head;
	while (current != nullptr)
	{
		insert(current->data);
		current = current->next;
	}
}

// Assignment operator
DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& dll)
{
	if (this == &dll)
	{
		return *this;
	}
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	Node* current = dll.head;
	while (current)
	{
		insert(current->data);
		current = current->next;
	}
	return *this;
}

// Destructor
DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current;
		current = current->next;
		delete temp;
	}
}

// Output operator
std::ostream& operator<<(std::ostream& outputStrm, const DoubleLinkedList& dll)
{
	Node* current = dll.head;
	while (current != nullptr)
	{
		outputStrm << current->data;
		if (current->next != nullptr)
		{
			outputStrm << ' ';
		}
		current = current->next;
	}
	return outputStrm;
}

// Insert a string into the list
bool DoubleLinkedList::insert(const TBString& str)
{
	Node* newNode = new Node(str);

	// early termination
	if (!newNode)
	{
		return false;
	}

	Node* current = head;
	Node* prev = nullptr;

	while (current != nullptr && str > current->data)
	{
		prev = current;
		current = current->next;
	}

	newNode->next = current;
	newNode->prev = prev;

	// head
	if (prev != nullptr)
	{
		prev->next = newNode;
	}
	else
	{
		head = newNode;
	}

	// tail
	if (current != nullptr)
	{
		current->prev = newNode;
	}
	else
	{
		tail = newNode;
	}

	count++;

	return true;
}

// Remove a string from the list
bool DoubleLinkedList::remove(const TBString& str)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data == str)
		{

			// head
			if (current->prev != nullptr)
			{
				current->prev->next = current->next;
			}
			else
			{
				head = current->next;
			}

			// tail
			if (current->next != nullptr)
			{
				current->next->prev = current->prev;
			}
			else
			{
				tail = current->prev;
			}

			delete current;
			count--;
			return true;
		}
		current = current->next;
	}
	return false;
}

// Get the number of strings stored in the list
int DoubleLinkedList::getCount() const
{
	return count;
}

void DoubleLinkedList::resetIteration()
{
	it = head;
}

TBString DoubleLinkedList::next()
{
	TBString str;
	if (it != nullptr)
	{
		str = it->data;
		it = it->next;
	}
	return str;
}

bool DoubleLinkedList::hasMore() const
{
	return it != nullptr;
}
