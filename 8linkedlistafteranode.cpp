#include <iostream>
using namespace std;

struct Node  // In C++, a struct (short for structure) is a user-defined data type that allows you to group different variables of different types together.
{
    int data;
    Node *next; // In C++, no need for "struct". "next" is a pointer that holds the address of the next Node.
};

void linkedListTraversal(Node *ptr)
{
    while (ptr != nullptr) // Use nullptr instead of NULL in C++.
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Function to insert a new node after a given node
Node* insertAfterNode(Node *head, Node *prevNode, int data) {
    Node *ptr = new Node; // Use new in C++ instead of malloc.
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    
    return head;
}

int main()
{
    // Declare pointers to Nodes
    Node *head, *second, *third, *fourth;

    // Allocate memory for nodes in the linked list on the heap
    head = new Node;      // Use new in C++ instead of malloc.
    second = new Node;    
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
    fourth->next = nullptr; // Use nullptr in C++.

    // Traverse the list
    linkedListTraversal(head); // Function call 

    // Insert a new node after the second node
    head = insertAfterNode(head, second, 99); // For example, adding a node with data 99 after "second"

    // Traverse the list again to see the inserted node
    cout << "\nAfter insertion:" << endl;
    linkedListTraversal(head);

    // Free allocated memory to avoid memory leaks
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
