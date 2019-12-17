//
//  Program 6. The purpose of this excercise is to gain   
//  experience with class design and implementation issues.
//  Course: CSYE 6205
//  Assignment number: 6 (f)
//  Author of LinkedList Class (last/first): Hadi Fatemeh

using namespace std;

class LinkedList
{

public:
    typedef char *value_type;
    enum mode { NORMAL = 0, DEBUG = 1 };
    //Ctors/Dtors
    LinkedList();                  // Default Ctor (NORMAL mode)
    LinkedList(mode);              // NORMAL or DEBUG mode
    ~LinkedList();                 // Dtor
    
    void   push_back(value_type);  // Append string to list
    void   push_front(value_type); // Prepend string to list
    size_t size()  const;          // Return current size (number of linked nodes)
    void   print() const;          // Print list, forwad from first to last node
    
    // Node class
    struct Node
    {
    private:
        value_type data;
        Node* next;
    public:        
        Node() {};
        void SetData(value_type aData)
        {
           data = new char;
           data = aData;
        };
        void SetNext(Node* aNext) { next = aNext; };
        value_type Data() { return data; };
        Node* Next() { return next; }; 
    };
    
private:
    Node *tail;
    Node *head;
    void Delete();
    int length;
    mode NDmode;
};    