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

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
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
