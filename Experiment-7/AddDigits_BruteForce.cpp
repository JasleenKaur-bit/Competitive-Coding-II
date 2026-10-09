#include <iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        // Keep adding digits until one digit remains
        while (num >= 10) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
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