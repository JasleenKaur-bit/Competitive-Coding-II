#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class MinStack {
private:
    // Normal stack stores all elements
    stack<int> st;
    // stores the minimum element
    stack<int> minSt;
public:
    MinStack() {
    }
    // Push a value into the stack
    void push(int value) {
        // Push value into the normal stack
        st.push(value);
        // If minimum stack is empty,
        // current value becomes the minimum
        if (minSt.empty()) {
            minSt.push(value);
        }
        else {
            minSt.push(min(value, minSt.top()));
        }
    }
    // Remove the top element
    void pop() {
        // Remove from both stacks
        st.pop();
        minSt.pop();
    }
    // Return the top element
    int top() {
        return st.top();
    }
    // Return the minimum element
    int getMin() {
        return minSt.top();
    }
};
int main() {
    MinStack ms;
    int n;
    // Take number of operations from user
    cout << "Enter number of operations: ";
    cin >> n;
    cout << "\nEnter operations:\n";
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        // Push operation
        if (operation == "push") {
            int value;
            cin >> value;
            ms.push(value);
            cout << "Pushed: " << value << endl;
        }
        // Pop operation
        else if (operation == "pop") {
            ms.pop();
            cout << "Element popped." << endl;
        }
        // Top operation
        else if (operation == "top") {
            cout << "Top element: "
                 << ms.top() << endl;
        }
        // Get minimum operation
        else if (operation == "getMin") {
            cout << "Minimum element: "
                 << ms.getMin() << endl;
        }
        // Invalid operation
        else {
            cout << "Invalid operation!" << endl;
        }
    }
    return 0;
}