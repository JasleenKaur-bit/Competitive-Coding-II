#include <iostream>
#include <vector>
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
// Create Linked List
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
// Brute Force Palindrome Check
bool isPalindrome(Node* head)
{
    vector<int> values;
    while (head != NULL)
    {
        values.push_back(head->data);
        head = head->next;
    }
    int left = 0;
    int right = values.size() - 1;
    while (left < right)
    {
        if (values[left] != values[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main()
{
    Node* head = NULL;
    int n;
    cout << "========== Palindrome Linked List (Brute Force) ==========\n\n";
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