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
// Creates a linked list from user-provided values
Node* createLinkedList(const vector<int>& values)
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
// Creates a cycle by connecting the last node
// to the node at the given 1-based position
void createCycle(Node* head, int position)
{
    if (head == nullptr || position == 0)
        return;
    Node* cycleNode = nullptr;
    Node* current = head;
    int index = 1;
    while (current->next != nullptr)
    {
        if (index == position)
            cycleNode = current;
        current = current->next;
        index++;
    }
    // Valid position supplied by the user
    if (cycleNode != nullptr)
        current->next = cycleNode;
}
// Floyd's Cycle Detection Algorithm
bool detectCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        // Both pointers meet only when a cycle exists
        if (slow == fast)
            return true;
    }
    return false;
}
int main()
{
    cout << "=====================================================\n";
    cout << "       CYCLE DETECTION USING FLOYD'S ALGORITHM\n";
    cout << "=====================================================\n\n";
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    if (n <= 0)
    {
        cout << "\nInvalid number of nodes.\n";
        return 0;
    }
    vector<int> values(n);
    cout << "\nEnter node values :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    Node* head = createLinkedList(values);
    int position;
    cout << "\nEnter cycle starting position (0 = No Cycle) : ";
    cin >> position;
    if (position < 0 || position > n)
    {
        cout << "\nInvalid cycle position.\n";
        return 0;
    }
    createCycle(head, position);
    cout << "\n=====================================================\n";
    cout << "                    RESULT\n";
    cout << "=====================================================\n";
    if (detectCycle(head))
    {
        cout << "Status           : Cycle Detected\n";
        cout << "Detection Method : Floyd's Slow-Fast Pointer\n";
    }
    else
    {
        cout << "Status           : No Cycle Found\n";
        cout << "Detection Method : Floyd's Slow-Fast Pointer\n";
    }
    cout << "Time Complexity  : O(n)\n";
    cout << "Space Complexity : O(1)\n";
    cout << "=====================================================\n";
    return 0;
}