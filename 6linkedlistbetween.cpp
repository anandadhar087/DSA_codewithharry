#include <iostream>  //cwh
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Function to insert a node at a specific index
Node* insertAtIndex(Node* head, int data, int index)
{
    Node* ptr2 = new Node(); // Use new in C++
    Node* ptr = head;
    int i = 0;

    // Traverse to the index where the new node is to be inserted
    while (i != index - 1)   // imp for placing ptr before 
    {
        ptr = ptr->next;  // This updates ptr to point to the next node in the list, effectively "moving" the pointer one step forward in the linked list.
        i++;
    }
    ptr2->data = data;
    ptr2->next = ptr->next;
    ptr->next = ptr2;

    return head;
}

// Function to traverse and print the linked list
void linkedListTraversal(Node* ptr2)
{
    while (ptr2 != nullptr)
    {
        cout << "Element: " << ptr2->data << endl;
        ptr2 = ptr2->next;
    }
}

int main()
{
    // Declare pointers to nodes
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;

    // Initialize linked list
    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 41;
    third->next = fourth;
    fourth->data = 66;
    fourth->next = nullptr;

    // Display original list
    cout << "Original List:" << endl;
    linkedListTraversal(head);

    // Insert a new node at index 2
    head = insertAtIndex(head, 25, 2);

    // Display updated list
    cout << "\nList after insertion at index 2:" << endl;
    linkedListTraversal(head);

    // Insert a new node at index 4
    head = insertAtIndex(head, 55, 4);

    // Display updated list
    cout << "\nList after insertion at index 4:" << endl;
    linkedListTraversal(head);

    // Free allocated memory to avoid memory leaks
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}