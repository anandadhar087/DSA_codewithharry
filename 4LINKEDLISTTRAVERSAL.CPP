#include <iostream>
using namespace std;

struct Node      //In C++, a struct (short for structure) is a user-defined data type that allows you to group different variables of different types together
                             
{
    int data;
    Node *next; // In C++, no need for "struct"  , next is a pointer that holds the address of the next Node
};

void linkedListTraversal(Node *ptr)
{
    while (ptr != nullptr) // Use nullptr instead of NULL in C++
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    // Declare pointers to Nodes
    Node *head, *second, *third, *fourth;

    // Allocate memory for nodes in the linked list on the heap
    head = new Node;      // Use new in C++ instead of malloc
    second = new Node;    //In C++, the new keyword is used to dynamically allocate memory on the heap. 
    third = new Node;
    fourth = new Node;

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 66;
    fourth->next = nullptr; // Use nullptr in C++

    // Traverse the list
    linkedListTraversal(head); //function call 

    // Free allocated memory to avoid memory leaks
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}

//// you can take help from YT chanel name Neso Acedemy , Introduction to Linked List 