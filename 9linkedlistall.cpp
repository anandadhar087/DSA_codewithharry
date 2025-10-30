#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void linkedListTraversal(Node* ptr) {
    while (ptr != nullptr) { // Use nullptr instead of NULL in C++
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Case 1: Insert at the beginning
Node* insertAtFirst(Node* head, int data) {
    Node* ptr = new Node; // Use new in C++ instead of malloc
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Case 2: Insert at a given index
Node* insertAtIndex(Node* head, int data, int index) {
    Node* ptr = new Node;
    Node* p = head;
    int i = 0;

    while (i != index - 1 && p != nullptr) { // Check p to avoid invalid access
        p = p->next;
        i++;
    }

    if (p != nullptr) { // Insert only if index is valid
        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;
    }

    return head;
}

// Case 3: Insert at the end
Node* insertAtEnd(Node* head, int data) {
    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = nullptr;

    if (head == nullptr) {
        return ptr;
    }

    Node* p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = ptr;
    
    return head;
}

// Case 4: Insert after a given node
Node* insertAfterNode(Node* head, Node* prevNode, int data) {
    if (prevNode == nullptr) return head; // Check for null pointer

    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main() {
    // Allocate memory for nodes in the linked list on the heap
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;

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

    cout << "Linked list before insertion" << endl;
    linkedListTraversal(head);

    // Uncomment to test various insert functions:
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    // head = insertAtEnd(head, 56);
    head = insertAfterNode(head, third, 45);

    cout << "\nLinked list after insertion" << endl;
    linkedListTraversal(head);

    // Free allocated memory to prevent memory leaks
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
 