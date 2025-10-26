#include <iostream> // iostream is a header in C++.
using namespace std;

void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    // Code for Insertion

     if(size>=capacity){
        return -1;
    }

    for (int i = size - 1; i >= index; i--)
    {                        // i = total index, index = specific index, i starts from the last valid index (size - 1) and goes down to the insertion index.
        arr[i + 1] = arr[i]; //  During each iteration, i is decremented (with i--) to move through the array from right to left.
    }
    arr[index] = element;
    return 1; // 1 means success
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 1;

    display(arr, size);
    indInsertion(arr, size, element, 100, index); // Capacity = 100
    size += 1;     // sized increased by one element that's whi +1
    display(arr, size);

    return 0;
}

// in linked list , array traversal is donr
// in binary search , array should be sorted
// o(n) means it traverse in linear search       worst case
// o(log n) means it divide multiple times in binary search     worst case

// element in array are stored in contiguous memory location while  a linked list is not stored in contiguous memory locations.