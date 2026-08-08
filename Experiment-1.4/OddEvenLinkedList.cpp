#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
void insertNode(Node* &head, int value)
{
    Node* newNode = new Node(value);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void display(Node* head)
{
    while(head != NULL)
    {
        cout << head->data;
        if(head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
Node* oddEvenList(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while(even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
int main()
{
    Node* head = NULL;
    int n;
    cout << "========== Odd Even Linked List ==========\n\n";
    cout << "Enter number of nodes : ";
    cin >> n;
    cout << "Enter node values : ";
    for(int i=0;i<n;i++)
    {
        int value;
        cin >> value;
        insertNode(head,value);
    }
    cout << "\nOriginal Linked List : ";
    display(head);
    head = oddEvenList(head);
    cout << "Rearranged Linked List : ";
    display(head);
    return 0;
}