// double_linked_list.h

/*
Contains the declaration of the DoubleLinkedList class for managing linked lists of strings.
It defines the structure and interface of the class.
*/

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "TBString.h"
#include "node.h"

class DoubleLinkedList
{
public:
    // Default constructor
    DoubleLinkedList();

    // Copy constructor
    DoubleLinkedList(const DoubleLinkedList& dll);

    // Assignment operator
    DoubleLinkedList& operator=(const DoubleLinkedList& dll);

    // Destructor
    ~DoubleLinkedList();

    // Output operator
    friend std::ostream& operator<<(std::ostream& outputStrm, const DoubleLinkedList& dll);

    // Insert a string into the list
    bool insert(const TBString& str);

    // Remove a string from the list
    bool remove(const TBString& str);

    // Get the number of strings stored in the list
    int getCount() const;

    // Iterator functions
    void resetIteration();
    TBString next();
    bool hasMore() const;

private:
    Node* head;
    Node* tail;
    mutable Node* it;
    int count;
};

#endif // !DOUBLE_LINKED_LIST_H

/*

Example using the iterator member functions:

```
// assuming DoubleLinkedList list has been created and filled with data

list.resetIteration( );     // puts iterator at head of list
while( list.hasMore( ) )    // is there another word in the list
{
  cout << list.next( );     // get the word and advance the iterator
}
```

*/
