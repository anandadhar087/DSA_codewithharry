#include <iostream>
using namespace std;

// Node structure definition
struct Node {
    int data;        // Data of the node
    Node* next;      // Pointer to the next node
};

// Class to represent the stack
class Stack {
private:
    Node* top;       // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() : top(nullptr) {} // Initialize top to nullptr

    // Push function to add an element to the stack
    void push(int val) {
        Node* ptr = new Node(); // Create a new node
        if (ptr == nullptr) {   // Check if memory allocation was successful
            cout << "Not able to push the element. Memory error." << endl;
            return;
        }
        ptr->data = val; // Set the data of the new node
        ptr->next = top; // Point new node to the current top
        top = ptr;       // Update top to the new node
        cout << "Item " << val << " pushed" << endl;
    }

    // Pop function to remove the top element from the stack
    void pop() {
        if (top == nullptr) { // Check for stack underflow
            cout << "Stack Underflow" << endl;
        } else {
            cout << "The popped element is " << top->data << endl; // Show the popped element
            Node* temp = top;  // Temporarily store the top node
            top = top->next;   // Move top pointer to the next node
            delete temp;       // Delete the old top node
        }
    }
};

// Main function to demonstrate stack operations
int main() {
    Stack s; // Create a stack object

    // Example operations
    s.push(10);  // Push 10 into the stack
    s.push(20);  // Push 20 into the stack
    s.pop();     // Pop the top element
    s.pop();     // Pop the next element
    s.pop();     // Attempt to pop from an empty stack

    return 0;
}
