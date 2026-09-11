#include <iostream>
using namespace std;
// Node structure for the linked list
class Node
{
public:
    int data;
    Node* next;
    // Initialize a new node
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
// Inserts a new node at the end of the linked list
void insertNode(Node* &head, int value)
{
    Node* newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    // Traverse to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
// Displays all elements of the linked list
void display(Node* head)
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
// Rearranges the linked list by odd and even positions
Node* oddEvenList(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    // Separate nodes at odd and even positions
    while (even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    // Connect the odd-position list with the even-position list
    odd->next = evenHead;
    return head;
}
int main()
{
    Node* head = NULL;
    int n;
    cout << "========== Odd Even Linked List ==========\n\n";
    // Take the number of nodes
    cout << "Enter number of nodes : ";
    cin >> n;
    // Take node values as input
    cout << "Enter node values : ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insertNode(head, value);
    }
    // Display the original linked list
    cout << "\nOriginal Linked List : ";
    display(head);
    // Rearrange nodes according to their positions
    head = oddEvenList(head);
    // Display the rearranged linked list
    cout << "Rearranged Linked List : ";
    display(head);
    return 0;
}