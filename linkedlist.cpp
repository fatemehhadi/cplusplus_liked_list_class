# include <iostream>

#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList()
{
    tail = NULL;
    head = NULL;
    length = 0;
    NDmode = NORMAL;
};

LinkedList::LinkedList(mode state)
{
    tail = NULL;
    head = NULL;
    length = 0;
    NDmode = NORMAL;
    if ( state == DEBUG)
       NDmode = DEBUG;
};

LinkedList::~LinkedList()
{
    Delete();
}

void LinkedList::push_back(value_type data)
{
    length++;
    
    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);
    if ( NDmode == DEBUG )
        cout << "LinkedList allocating node: "
             << newNode->Data() << endl; 
    if ( NDmode == DEBUG )
        cout << "Node: allocating: "
             << newNode->Data() << endl;
    newNode->SetNext(NULL);

             
    // Create a temp pointer
    Node *tmp = tail;

    if ( tmp != NULL )
    {
        tmp->SetNext(newNode);
    }
    else
    {
        // First node in the list
        head = newNode;
    }
    tail = newNode;
}

void LinkedList::push_front(value_type data)
{
	length++;
	
    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);

    if ( NDmode == DEBUG )
        cout << "LinkedList allocating node: "
             << newNode->Data() << endl; 
             
    // Create a temp pointer
    Node *tmp = head;

    if ( tmp != NULL )
    {
        newNode->SetNext(head);
    }
    else
    {
        // Last node in the list
        newNode->SetNext(NULL);
        tail = newNode;
    }
    head = newNode;
}

size_t LinkedList::size() const
{
    return length;
}

void LinkedList::Delete()
{

    // Create a temp pointer
    Node *tmp = head;
    Node *prv = head;

    // No nodes
    if ( tmp == NULL )
        return;

    // Only node of the list
    if ( tmp->Next() == NULL )
    {
        if ( NDmode == DEBUG )
            cout << "LinkedList allocating node: "
                 << tmp->Data() << endl;
        delete tmp;
        head = NULL;
    }
    else
    {
        for(int i = 0; i < (length-1); i++)
        {   
            tmp = head->Next();
            head->SetNext(tmp->Next());
            tmp->SetNext(prv); 
            prv = tmp;
            
            //cout << endl;
            //cout << "tmp: "<< tmp->Data() << " prv: "
            //     << prv->Data() << " head: "<< head->Data() 
            //     << endl;
        }        
        tail = head;
        head = tmp;
        tail->SetNext(NULL); 
        //cout << endl;
        //print();
        
        for(int i = 0; i < length; i++)
        {  
        	if ( head->Next() != NULL )
        	{
        		tmp = head->Next();
                if ( NDmode == DEBUG )
                    cout << "LinkedList deallocating node: "
                         << head->Data() << endl;
                if ( NDmode == DEBUG )
                    cout << "Node: deallocating: "
                         << head->Data() << endl;                          
                delete head; 
                head = tmp;                 
        	}
        	else
        	{
        		head->SetNext(NULL);
                if ( NDmode == DEBUG )
                    cout << "LinkedList deallocating node: "
                         << head->Data() << endl;
                if ( NDmode == DEBUG )
                    cout << "Node: deallocating: "
                         << head->Data() << endl;                
        		delete head;
        		head = NULL;
        	}
        	//cout << endl;
        	//print();
        }  
    }
}

void LinkedList::print() const
{
    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL )
    {
        cout << "EMPTY" << endl;
        return;
    }

    // One node in the list
    if ( tmp->Next() == NULL )
    {
        cout << tmp->Data() << endl;
    }
    else
    {
        // March and print the list
        do
        {
            cout << tmp->Data() << endl;
            tmp = tmp->Next();
        }
        while ( tmp != NULL );
    }
}