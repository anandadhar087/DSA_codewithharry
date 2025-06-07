#include <iostream>
using namespace std;

struct stack {
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* ptr) {
    if (ptr->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(struct stack* ptr) {
    if (ptr->top == ptr->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct stack* s = new stack; // Dynamically allocate memory for the stack structure
    s->size = 80;
    s->top = -1;
    s->arr = new int[s->size]; // Allocate memory for the array

    // Pushing an element manually
    s->arr[0] = 7;    // original output before // is not empty but //out this line and next line will give result empty
    s->top++;

    // Check if stack is empty
    if (isEmpty(s)) {
        cout << "The stack is empty" << endl;
    } else {
        cout << "The stack is not empty" << endl;
    }

    // Free allocated memory to avoid memory leaks
    delete[] s->arr;
    delete s;

    return 0;
}
