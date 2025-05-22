#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;  // No need for "struct" in C++, next is a pointer to the next Node
};

// Function to traverse the linked list
void linkedListTraversal(Node *ptr) {
    while (ptr != nullptr) {  // Use nullptr instead of NULL in C++
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Function to insert a node at the beginning of the linked list
Node * insertAtFirst(Node *head, int data) {
    Node *ptr = new Node;  // Use new in C++ instead of malloc
    ptr->next = head;    // name of new node is ptr
    ptr->data = data;
    return ptr;
}

int main() {
    // Declare pointers to Nodes
    Node *head, *second, *third, *fourth;

    // Allocate memory for nodes in the linked list on the heap
    head = new Node;      // Use new in C++ instead of malloc
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
    fourth->next = nullptr;  // Use nullptr in C++

    // Traverse the list
    linkedListTraversal(head);  // Function call

    // Insert a new element at the beginning of the list
    head = insertAtFirst(head, 36);
    linkedListTraversal(head);

    // Free allocated memory to avoid memory leaks
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}

// yt NESO ACEDEMY