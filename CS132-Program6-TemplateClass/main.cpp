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
#include "LkList.h"
#include "LkList.cpp"

void changer(LkList<TBString>& list);

int main()
{
    LkList<TBString> list1;
    LkList<TBString> list2;
    LkList<TBString> modList1;
    LkList<TBString> modList2;

    // read infile1
    std::ifstream infile1("infile1.txt");
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
        std::cout << "Error opening infile1.txt" << std::endl;
    }

    // read infile2
    std::ifstream infile2("infile2.txt");
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
        std::cout << "Error opening infile2.txt" << std::endl;
    }

    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    std::cout << std::endl << "- v - v - v - v - v - After reading files - v - v - v - v - v -" << std::endl << std::endl;

    modList1 = list1;
    modList2 = list2;

    // output sizes
    std::cout << "Size of list1: " << list1.size() << std::endl;
    std::cout << "Size of list2: " << list2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "Size of modList1: " << modList1.size() << std::endl;
    std::cout << "Size of modList2: " << modList2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "Created Count from TBString: " << TBString::getCreatedCount() << std::endl;
    std::cout << "Current Count from TBString: " << TBString::getCurrentCount() << std::endl;

    std::cout << std::endl << "- v - v - v - v - v - After removing from lists - v - v - v - v - v -" << std::endl << std::endl;
    // remove list1 strings from modList1
    TBString str1;
    modList1.resetIterator();
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
    modList2.resetIterator();
    while (modList2.hasMore())
    {
        try 
        {
            str2 = modList2.next();
        }
        catch (const std::bad_alloc& e) 
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
        if (list1.remove(str2))
        {
            modList2.remove(str2);
            std::cout << "Removed from list1 and modList2" << std::endl;
        }
    }

    std::cout << "Size of list1: " << list1.size() << std::endl;
    std::cout << "Size of list2: " << list2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "Size of modList1: " << modList1.size() << std::endl;
    std::cout << "Size of modList2: " << modList2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "Created Count from TBString: " << TBString::getCreatedCount() << std::endl;
    std::cout << "Current Count from TBString: " << TBString::getCurrentCount() << std::endl;

    std::cout << std::endl << "- v - v - v - v - v - After Changer function - v - v - v - v - v -" << std::endl << std::endl;

    changer(modList1);
    std::cout << "Inside changer function: size of modList1 is " << modList1.size() << std::endl;
    std::cout << std::endl;
    changer(modList2);
    std::cout << "Inside changer function: size of modList2 is " << modList2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "Created Count from TBString: " << TBString::getCreatedCount() << std::endl;
    std::cout << "Current Count from TBString: " << TBString::getCurrentCount() << std::endl;

    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";

    std::ofstream outfile1("outfile1.txt");
    modList1.resetIterator();
    int wordCount = 0;

    while (modList1.hasMore())
    {

        outfile1 << modList1.next() << " ";
        wordCount++;

        if (wordCount % 10 == 0)
        {
            outfile1 << std::endl;
        }
    }
    outfile1.close();

    std::ofstream outfile2("outfile2.txt");
    modList2.resetIterator();
    wordCount = 0;

    while (modList2.hasMore())
    {

        outfile2 << modList2.next() << " ";
        wordCount++;

        if (wordCount % 10 == 0)
        {
            outfile2 << std::endl;
        }
    }
    outfile2.close();

    // modification added for main() requirements in assignment details
    LkList<int> intList;
    for (int i = 20; i > 0; i -= 2)
        intList.insert(i);

    for (int i = 25; i > 0; i -= 5)
        intList.insert(i);

    std::cout << "intlist: " << intList << "  size:" << intList.size() << std::endl << std::endl;

    LkList<double> dblList;
    for (double i = 10.9; i > 0; i -= .57)
        dblList.insert(i);

    for (double i = 24.8; i > 5; i -= .64)
        dblList.insert(i);

    std::cout << "dblList: " << dblList << "  size:" << dblList.size() << std::endl;

    std::cout << "\n- - - - - - - - - - - - - - - - - Final - - - - - - - - - - - - - - - - -\n\n";

    // Output sizes of the lists
    std::cout << "Size of list1: " << list1.size() << std::endl;
    std::cout << "Size of list2: " << list2.size() << std::endl;
    std::cout << "Size of modList1: " << modList1.size() << std::endl;
    std::cout << "Size of modList2: " << modList2.size() << std::endl;
    std::cout << std::endl;

    // Output the first 5 words from modList1 using iterators
    std::cout << "First 5 words from modList1:\t";
    modList1.resetIterator();
    for (int i = 0; i < 5 && modList1.hasMore(); ++i)
    {
        std::cout << modList1.next() << " ";
    }
    std::cout << std::endl;

    // Output the first 5 words from modList2 using iterators
    std::cout << "First 5 words from modList2:\t";
    modList2.resetIterator();
    for (int i = 0; i < 5 && modList2.hasMore(); ++i)
    {
        std::cout << modList2.next() << " ";
    }
    std::cout << std::endl;

    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";

    exit(0);
}

void changer(LkList<TBString>& list)
{
    TBString zip("ZIP");
    TBString zap("ZAP");
    list.insert(zip);
    list.insert(zap);
    std::cout << "Inside changer function: size of list is " << list.size() << std::endl;
}

/*

OUTPUT: 

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

- v - v - v - v - v - After reading files - v - v - v - v - v -

Size of list1: 3049
Size of list2: 2922

Size of modList1: 3049
Size of modList2: 2922

Created Count from TBString: 11944
Current Count from TBString: 5971

- v - v - v - v - v - After removing from lists - v - v - v - v - v -

Size of list1: 3049
Size of list2: 2922

Size of modList1: 3049
Size of modList2: 2922

Created Count from TBString: 17917
Current Count from TBString: 5973

- v - v - v - v - v - After Changer function - v - v - v - v - v -

Inside changer function: size of list is 3051
Inside changer function: size of modList1 is 3051

Inside changer function: size of list is 2924
Inside changer function: size of modList2 is 2924

Created Count from TBString: 17929
Current Count from TBString: 5977

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
intlist: 2 4 5 6 8 10 12 14 15 16 18 20 25   size:13

dblList: 0.07 0.64 1.21 1.78 2.35 2.92 3.49 4.06 4.63 5.2 5.6 5.77 6.24 
6.34 6.88 6.91 7.48 7.52 8.05 8.16 8.62 8.8 9.19 9.44 9.76 10.08 10.33 
10.72 10.9 11.36 12 12.64 13.28 13.92 14.56 15.2 15.84 16.48 17.12 17.76 
18.4 19.04 19.68 20.32 20.96 21.6 22.24 22.88 23.52 24.16 24.8   size:51

- - - - - - - - - - - - - - - - - Final - - - - - - - - - - - - - - - - -

Size of list1: 3049
Size of list2: 2922
Size of modList1: 3051
Size of modList2: 2924

First 5 words from modList1:    1685 a about air along
First 5 words from modList2:    a a as a and

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

*/

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
then I would recommstd::end to come to the Open Lab times after class or my office hours on Wednesday and Friday.

Modifications to Main if you are modifying program 4:

Do the normal requirements from program 4

read into list1 and list2
make modlist1 and modlist2 and remove the word as before
std::cout the size of the 4 lists
std::cout the first 5 words from modlist1 and modlist2 using iterators
add the following modifications to main to create other types of LinkedList

```
    LinkedList<int> intList;
    for (int i = 20; i > 0; i -= 2)
       intList.insert(i);

    for (int i = 25; i > 0; i -= 5)
       intList.insert(i);

    std::cout << "intlist: " << intList << "  size:" << intList.size() << std::endl << std::endl;

    LinkedList<double> dblList;
    for (double i = 10.9; i > 0; i -= .57)
       dblList.insert(i);

    for (double i = 24.8; i > 5; i -= .64)
       dblList.insert(i);

    std::cout << "dblList: " << dblList << "  size:" << dblList.size() << std::endl << std::endl;
```

*/
