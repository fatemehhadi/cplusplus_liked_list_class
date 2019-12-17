
#include <iostream>

#include "linkedlist.h"

using namespace std;

int
main(int argc,char **argv)
{
    LinkedList  llist(LinkedList::DEBUG);

    for(int i = 0; i < argc; i++) 
	llist.push_back(argv[i]);

    cout << "size() = " << llist.size() << endl;
    cout << "Printing list from head to tail: " << endl;
    llist.print();

    return 0;
}
