#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void linkedListTraversal(Node* ptr)
{
    while (ptr != nullptr)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element from the linked list
Node* deleteFirst(Node* head)
{
    Node* ptr = head;
    head = head->next;
    delete ptr;
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
Node* deleteAtIndex(Node* head, int index)
{
    Node* p = head;
    Node* q = head->next;
    for (int i = 0; i < index - 1; i++) // index-1 means first element cannot be deleted from index 0 , deletion start from index 1, for index 1 we have to run it for zero time 
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    delete q;
    return head;
}

// Case 3: Deleting the last element
Node* deleteAtLast(Node* head)
{
    Node* p = head;
    Node* q = head->next;
    while (q->next != nullptr)
    {
        p = p->next;
        q = q->next;
    }

    p->next = nullptr;
    delete q;
    return head;
}

// Case 4: Deleting the element with a given value from the linked list
Node* deleteByValue(Node* head, int value)
{
    Node* p = head;
    Node* q = head->next;
    while (q->data != value && q->next != nullptr)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        delete q;
    }
    return head;
}

int main()
{
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = nullptr;

    cout << "Linked list before deletion" << endl;
    linkedListTraversal(head);

    // Uncomment the function you want to test
    // head = deleteFirst(head); // For deleting first element of the linked list
    // head = deleteAtIndex(head, 2);
    head = deleteAtLast(head);
    // head = deleteByValue(head, 3);

    cout << "Linked list after deletion" << endl;
    linkedListTraversal(head);

    return 0;
}
