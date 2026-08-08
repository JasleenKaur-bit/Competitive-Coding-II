#include <iostream>
using namespace std;
// Node structure
struct Node
{
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
// Insert Node
void insertNode(Node*& head, int value)
{
    Node* newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
// Display Linked List
void displayList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
// Reverse Linked List
Node* reverseList(Node* head)
{
    Node* previous = NULL;
    Node* current = head;
    while (current != NULL)
    {
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    return previous;
}
// Optimized Palindrome Check
bool isPalindrome(Node* head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secondHalf = reverseList(slow->next);
    Node* firstHalf = head;
    Node* temp = secondHalf;
    while (temp != NULL)
    {
        if (firstHalf->data != temp->data)
        {
            return false;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }
    return true;
}
int main()
{
    Node* head = NULL;
    int n;
    cout << "========== Palindrome Linked List (Optimized) ==========\n\n";
    cout << "Enter number of nodes : ";
    cin >> n;
    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insertNode(head, value);
    }
    cout << "\nLinked List : ";
    displayList(head);
    if (isPalindrome(head))
    {
        cout << "\nResult : TRUE";
        cout << "\nThe linked list is a palindrome.\n";
    }
    else
    {
        cout << "\nResult : FALSE";
        cout << "\nThe linked list is not a palindrome.\n";
    }
    return 0;
}