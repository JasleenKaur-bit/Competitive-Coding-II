#include <iostream>
#include <queue>
using namespace std;
class MyStack
{
private:
    queue<int> q1, q2;
public:
    // Adds an element to the stack
    void push(int x)
    {
        q2.push(x);
        // Move existing elements behind the new element
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        // Make q1 the main queue
        swap(q1, q2);
    }
    // Removes the top element from the stack
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty.\n";
            return;
        }
        cout << "Popped Element: " << q1.front() << endl;
        q1.pop();
    }
    // Displays the top element of the stack
    void top()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty.\n";
            return;
        }
        cout << "Top Element: " << q1.front() << endl;
    }
    // Displays all stack elements
    void display()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty.\n";
            return;
        }
        queue<int> temp = q1;
        cout << "Stack Elements: ";
        // Display elements without modifying the original queue
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
    // Checks whether the stack is empty
    bool empty()
    {
        return q1.empty();
    }
};
int main()
{
    MyStack s;
    int choice, value;
    cout << "\n===== STACK USING QUEUE =====\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Top\n";
    cout << "4. Display\n";
    cout << "5. Check Empty\n";
    cout << "6. Exit\n";
    do
    {
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.top();
            break;
        case 4:
            s.display();
            break;
        case 5:
            if (s.empty())
                cout << "Stack is Empty.\n";
            else
                cout << "Stack is Not Empty.\n";
            break;
        case 6:
            cout << "Program Ended.\n";
            break;
        default:
            cout << "Invalid Choice.\n";
        }
    } while (choice != 6);
    return 0;
}