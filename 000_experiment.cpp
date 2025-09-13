#include <iostream> // Include iostream for input and output
using namespace std;

// Define a node structure
struct Node {
    int val;         // Value of the node
    Node* next;     // Pointer to the next node
};

// Class for the stack
class Stack {
private:
    Node* top;      // Pointer to the top of the stack

public:
    Stack() { top = nullptr; } // Constructor initializes top to nullptr

    // Push a value onto the stack
    void push(int val) {
        Node* newnode = new Node(); // Create a new node
        newnode->val = val;          // Set the node's value
        newnode->next = top;         // Link the new node to the current top
        top = newnode;               // Update the top to the new node
    }

    // Pop a value from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow" << endl; // Stack is empty
            return;
        }
        cout << "The popped element is: " << top->val << endl;
        Node* temp = top; // Temporary pointer to the top node
        top = top->next;   // Update top to the next node
        delete temp;       // Free the old top node
    }

    // Display the stack elements
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are: ";
        Node* ptr = top; // Start from the top of the stack
        while (ptr != nullptr) {
            cout << ptr->val << " "; // Print each value
            ptr = ptr->next;         // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    Stack stack;              // Create a Stack object
    int choice = 0, val;     // Variable for user choice and value

    cout << "\n********* Stack operations using linked list *********\n";
    while (choice != 4) {
        cout << "\nChoose one from the below options:\n";
        cout << "1. Push\n2. Pop\n3. Show\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter value to be pushed: ";
                cin >> val;
                stack.push(val); // Call the push function
                break;
            }
            case 2: {
                stack.pop(); // Call the pop function
                break;
            }
            case 3: {
                stack.display(); // Call the display function
                break;
            }
            case 4: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Please enter a valid choice." << endl;
                break;
            }
        }
    }
    return 0; // Exit the program
}
