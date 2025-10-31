#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Function to traverse the circular linked list
void linkedListTraversal(Node *head) {
    if (!head) return; // Check for an empty list

    Node *ptr = head;
    do {
        cout << "Element is " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

// Function to insert a node at the beginning of the circular linked list
Node* insertAtFirst(Node *head, int data) {
    Node *ptr = new Node;
    ptr->data = data;

    if (!head) {
        // If the list is empty, point the new node to itself
        ptr->next = ptr;
        return ptr;
    }

    Node *p = head;
    while (p->next != head) {
        p = p->next;
    }
    // At this point, p points to the last node of the circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

// Function to free the circular linked list
void freeCircularList(Node *head) {
    if (!head) return; // If list is empty, no need to free

    Node *current = head;
    Node *nextNode;

    do {
        nextNode = current->next; // Save the next node
        delete current;           // Free the current node
        current = nextNode;       // Move to the next node
    } while (current != head);    // Stop when we come back to the head
}

// Main function to test the circular linked list
int main() {
    Node *head = nullptr;

    // Create a circular linked list using insertAtFirst
    head = insertAtFirst(head, 1);
    head = insertAtFirst(head, 6);
    head = insertAtFirst(head, 3);
    head = insertAtFirst(head, 4);

    cout << "Linked list before insertion:" << endl;
    linkedListTraversal(head);

    // Insert a new node at the beginning
    head = insertAtFirst(head, 7);

    cout << "\nLinked list after insertion:" << endl;
    linkedListTraversal(head);

    // Free the circular linked list to avoid memory leaks
    freeCircularList(head);

    return 0;
}

//!head: This checks whether the head pointer is nullptr (or NULL in older C++ code). The ! operator negates the condition, so it evaluates to true if head is nullptr.

//return;: If the condition is true (i.e., the linked list is empty), the function exits immediately without executing any further code.