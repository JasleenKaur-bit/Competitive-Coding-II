#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

public:

    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {

        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty.\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Deleted Element: " << s2.top() << endl;
        s2.pop();
    }

    void front() {

        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty.\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Front Element: " << s2.top() << endl;
    }

    void display() {

        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty.\n";
            return;
        }

        stack<int> temp1 = s1;
        stack<int> temp2 = s2;

        int arr[100];
        int i = 0;

        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        while (!temp1.empty()) {
            arr[i++] = temp1.top();
            temp1.pop();
        }

        for (int j = i - 1; j >= 0; j--) {
            cout << arr[j] << " ";
        }

        cout << endl;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {

    MyQueue q;
    int choice, value;

    cout << "\n===== QUEUE USING STACK =====\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Front\n";
    cout << "4. Display\n";
    cout << "5. Check Empty\n";
    cout << "6. Exit\n";

    do {

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter Element: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.front();
            break;

        case 4:
            cout << "Queue Elements: ";
            q.display();
            break;

        case 5:
            if(q.empty())
                cout << "Queue is Empty.\n";
            else
                cout << "Queue is Not Empty.\n";
            break;

        case 6:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while(choice != 6);

    return 0;
}