#include <iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        // Handle zero separately
        if (num == 0) {
            return 0;
        }
        // Calculate the digital root directly
        return 1 + (num - 1) % 9;
    }
};
int main() {
    Solution obj;
    int num;
    cout << "Enter a non-negative integer: ";
    cin >> num;
    if (num < 0) {
        cout << "Invalid input. Enter a non-negative integer." << endl;
        return 1;
    }
    cout << "Input: " << num << endl;
    cout << "Digital Root: " << obj.addDigits(num) << endl;
    return 0;
}