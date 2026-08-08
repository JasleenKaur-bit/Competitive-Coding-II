#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
Node* createLinkedList(vector<int>& values)
{
    if(values.empty())
        return nullptr;
    Node* head = new Node(values[0]);
    Node* temp = head;
    for(int i=1;i<values.size();i++)
    {
        temp->next = new Node(values[i]);
        temp = temp->next;
    }
    return head;
}
void createCycle(Node* head,int position)
{
    if(position==0)
        return;
    Node* cycleNode=nullptr;
    Node* temp=head;
    int index=1;
    while(temp->next!=nullptr)
    {
        if(index==position)
            cycleNode=temp;
        temp=temp->next;
        index++;
    }
    temp->next=cycleNode;
}
bool detectCycle(Node* head)
{
    unordered_set<Node*> visited;
    while(head!=nullptr)
    {
        if(visited.count(head))
            return true;
        visited.insert(head);
        head=head->next;
    }
    return false;
}
int main()
{
    cout << "=====================================================\n";
    cout << "          CYCLE DETECTION USING HASH SET\n";
    cout << "=====================================================\n\n";
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    vector<int> values(n);
    cout << "\nEnter node values :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    Node* head = createLinkedList(values);
    int pos;
    cout << "\nEnter cycle starting position (0 = No Cycle) : ";
    cin >> pos;
    createCycle(head, pos);
    cout << "\n=====================================================\n";
    cout << "                    RESULT\n";
    cout << "=====================================================\n";
    if (detectCycle(head))
    {
        cout << "Status           : Cycle Detected\n";
        cout << "Detection Method : HashSet / Visited Nodes\n";
    }
    else
    {
        cout << "Status           : No Cycle Found\n";
        cout << "Detection Method : HashSet / Visited Nodes\n";
    }
    cout << "=====================================================\n";
    return 0;
}