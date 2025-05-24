#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;  // Pointer to the next node
};

// Function to traverse and print the linked list
void linkedListTraversal(Node* ptr) {
    while (ptr != nullptr) {  // Traverse until the end of the list
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Function to insert a node at the end of the linked list in C++
Node* insertAtEnd(Node* head, int data) {
    Node* ptr2 = new Node();  // Allocate memory for the new node using `new`
    ptr2->data = data;
    ptr2->next = nullptr;     // Set the new node's next pointer to nullptr

    if (head == nullptr) {
        // If the list is empty, the new node becomes the head
        return ptr2;
    }

    Node* ptr = head;

    // Traverse to the last node
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }

    // Link the last node's next pointer to the new node
    ptr->next = ptr2;

    return head;
}

int main() {
    // Declare pointers to Nodes
    Node *head, *second, *third, *fourth;

    // Allocate memory for nodes in the linked list on the heap
    head = new Node;     
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
    fourth->next = nullptr;

    // Traverse the original list
    cout << "Original Linked List:" << endl;
    linkedListTraversal(head);

    // Insert a new node at the end of the linked list
    head = insertAtEnd(head, 99);  // Inserting a new node with data 99 at the end

    // Traverse the list after insertion
    cout << "\nLinked List after inserting 99 at the end:" << endl;
    linkedListTraversal(head);

    // Free allocated memory to avoid memory leaks
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
