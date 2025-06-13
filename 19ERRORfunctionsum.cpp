#include <iostream>
using namespace std;

// Function to calculate the sum of two numbers
int add(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2, sum;

    // Input two numbers
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Call the add function and store the result in sum
    sum = add(num1, num2);

    // Output the result
    cout << "The sum of " << num1 << " and " << num2 << " is " << sum << "." << endl;

    return 0;
}

// a function is a reusable block of code designed to perform a specific task. Functions help organize code, improve readability, and reduce redundancy by allowing you to call the same piece of code multiple times from different parts of your program.