// main.cpp

/*
 Name:          Taylor Bisset
 Section:       A
 Program Name:  CS132-Program6-TemplateClass 

 Description:   This program modifies my previous Linked List project 
                into a template class. It should still keep the original purpose: 
                Manages sorted doubly linked lists of strings.
                Reads data from input files, manipulates lists,
                and writes results to output files.

Repo:           https://github.com/TaylorBisset/CS132-Program6-TemplateClass 
                https://github.com/TaylorBisset/CS132-Program4-LinkedList 
*/

#include <iostream>
#include <fstream>
#include "double_linked_list.h"

using namespace std;

void changer(DoubleLinkedList list);

int main()
{
    DoubleLinkedList list1;
    DoubleLinkedList list2;
    DoubleLinkedList modList1;
    DoubleLinkedList modList2;

    // read infile1
    ifstream infile1("infile1.txt");
    if (infile1.is_open())
    {
        TBString word;
        while (infile1 >> word)
        {
            list1.insert(word);
        }
        infile1.close();
    }
    else
    {
        cout << "Error opening infile1.txt" << endl;
    }

    // read infile2
    ifstream infile2("infile2.txt");
    if (infile2.is_open())
    {
        TBString word;
        while (infile2 >> word)
        {
            list2.insert(word);
        }
        infile2.close();
    }
    else
    {
        cout << "Error opening infile2.txt" << endl;
    }

    cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    cout << endl << "- v - v - v - v - v - After reading files - v - v - v - v - v -" << endl << endl;

    modList1 = list1;
    modList2 = list2;

    // output sizes
    cout << "Size of list1: " << list1.getCount() << endl;
    cout << "Size of list2: " << list2.getCount() << endl;
    cout << endl;
    cout << "Size of modList1: " << modList1.getCount() << endl;
    cout << "Size of modList2: " << modList2.getCount() << endl;
    cout << endl;
    cout << "Created Count from TBString: " << TBString::getCreatedCount() << endl;
    cout << "Current Count from TBString: " << TBString::getCurrentCount() << endl;

    cout << endl << "- v - v - v - v - v - After removing from lists - v - v - v - v - v -" << endl << endl;
    // remove list1 strings from modList1
    TBString str1;
    modList1.resetIteration();
    while (modList1.hasMore())
    {
        str1 = modList1.next();
        if (list2.remove(str1))
        {
            modList1.remove(str1);
        }
    }

    // remove list2 strings from modList2
    TBString str2;
    modList2.resetIteration();
    while (modList2.hasMore())
    {
        str2 = modList2.next();
        if (list1.remove(str2))
        {
            modList2.remove(str2);
        }
    }

    cout << "Size of list1: " << list1.getCount() << endl;
    cout << "Size of list2: " << list2.getCount() << endl;
    cout << endl;
    cout << "Size of modList1: " << modList1.getCount() << endl;
    cout << "Size of modList2: " << modList2.getCount() << endl;
    cout << endl;
    cout << "Created Count from TBString: " << TBString::getCreatedCount() << endl;
    cout << "Current Count from TBString: " << TBString::getCurrentCount() << endl;

    cout << endl << "- v - v - v - v - v - After Changer function - v - v - v - v - v -" << endl << endl;

    changer(modList1);
    cout << "Inside changer function: size of modList1 is " << modList1.getCount() << endl;
    cout << endl;
    changer(modList2);
    cout << "Inside changer function: size of modList2 is " << modList2.getCount() << endl;
    cout << endl;
    cout << "Created Count from TBString: " << TBString::getCreatedCount() << endl;
    cout << "Current Count from TBString: " << TBString::getCurrentCount() << endl;

    cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";

    ofstream outfile1("outfile1.txt");
    modList1.resetIteration();
    int wordCount = 0;

    while (modList1.hasMore())
    {

        outfile1 << modList1.next() << " ";
        wordCount++;

        if (wordCount % 10 == 0)
        {
            outfile1 << endl;
        }
    }
    outfile1.close();

    ofstream outfile2("outfile2.txt");
    modList2.resetIteration();
    wordCount = 0;

    while (modList2.hasMore())
    {

        outfile2 << modList2.next() << " ";
        wordCount++;

        if (wordCount % 10 == 0)
        {
            outfile2 << endl;
        }
    }
    outfile2.close();

    return 0;
}

void changer(DoubleLinkedList list)
{
    TBString zip("ZIP");
    TBString zap("ZAP");
    list.insert(zip);
    list.insert(zap);
    cout << "Inside changer function: size of list is " << list.getCount() << endl;
}


/*

In this program you will be modifying the Linked List class from program 4 to be a template class.

Here are some of the steps for converting the LkList class to a LkList template:

Programming Note: the following assumes that your program runs before we start this process.....you should verify that now.
Use File Explorer to make a copy of folder where you wrote your program 4, then rename the copy folder to Template Linked List
If the Node class was an inner class you may want to move it before the LkList class
Copy the code out of the LkList.cpp into the LkList.h below where the class is defined....
removing any copied include or using namespace statements
Place the  template <typename T>  before the class definition and all the member functions
For the member function definitions you will have to change the class name from LkList to LkList< T >
Replace all your references to MYString to T
Make the changes as needed.....until the red underscores go away.....or at least most of them.
This process of converting a class to templates may give you some strange errors, 
and this is why I give you a whole class to work on this with some assistance.  
If you are having problems getting things to work and aren't able to finish it in the class time given, 
then I would recommend to come to the Open Lab times after class or my office hours on Wednesday and Friday.

Modifications to Main if you are modifying program 4:

Do the normal requirements from program 4

read into list1 and list2
make modlist1 and modlist2 and remove the word as before
cout the size of the 4 lists
cout the first 5 words from modlist1 and modlist2 using iterators
add the following modifications to main to create other types of LinkedList

```
    LinkedList<int> intList;
    for (int i = 20; i > 0; i -= 2)
       intList.insert(i);

    for (int i = 25; i > 0; i -= 5)
       intList.insert(i);

    cout << "intlist: " << intList << "  size:" << intList.size() << endl << endl;

    LinkedList<double> dblList;
    for (double i = 10.9; i > 0; i -= .57)
       dblList.insert(i);

    for (double i = 24.8; i > 5; i -= .64)
       dblList.insert(i);

    cout << "dblList: " << dblList << "  size:" << dblList.size() << endl << endl;
```

*/
