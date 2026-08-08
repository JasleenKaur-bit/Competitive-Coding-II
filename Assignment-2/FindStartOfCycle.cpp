#include <iostream>
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
// Create linked list
Node* createList(const vector<int>& values)
{
    if (values.empty())
        return nullptr;
    Node* head = new Node(values[0]);
    Node* current = head;
    for (int i = 1; i < values.size(); i++)
    {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}
// Connect last node to the given position
// Position is 1-based; 0 means no cycle
void createCycle(Node* head, int position)
{
    if (head == nullptr || position == 0)
        return;
    Node* cycleStart = nullptr;
    Node* current = head;
    int index = 1;
    while (current->next != nullptr)
    {
        if (index == position)
            cycleStart = current;
        current = current->next;
        index++;
    }
    if (cycleStart != nullptr)
        current->next = cycleStart;
}
// Find starting node of cycle using Floyd's Algorithm
Node* findCycleStart(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    // Step 1: Detect cycle
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            // Step 2: Find starting point
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
int main()
{
    cout << "=============================================\n";
    cout << "       FIND START OF THE CYCLE\n";
    cout << "        USING FLOYD'S ALGORITHM\n";
    cout << "=============================================\n\n";
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    vector<int> values(n);
    cout << "Enter node values : ";
    for (int i = 0; i < n; i++)
        cin >> values[i];
    Node* head = createList(values);
    int position;
    cout << "Enter position where last node connects\n";
    cout << "(1-based position, 0 = No Cycle) : ";
    cin >> position;
    createCycle(head, position);
    Node* cycleStart = findCycleStart(head);
    cout << "\n---------------------------------------------\n";
    if (cycleStart != nullptr)
    {
        cout << "Result : Cycle Detected\n";
        cout << "Cycle starts at node value : "
             << cycleStart->data << "\n";
        cout << "Cycle starts at position : "
             << position << "\n";
    }
    else
    {
        cout << "Result : No Cycle Found\n";
    }
    cout << "---------------------------------------------\n";
    return 0;
}