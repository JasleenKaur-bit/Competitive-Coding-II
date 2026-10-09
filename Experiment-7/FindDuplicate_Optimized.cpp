#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Find a meeting point inside the cycle
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // Find the beginning of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;
    if (size < 2 || size > 100001) {
        cout << "Invalid array size." << endl;
        return 1;
    }
    vector<int> nums(size);
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    // Validate the range required by the problem
    int n = size - 1;
    for (int value : nums) {
        if (value < 1 || value > n) {
            cout << "Invalid input: values must be between 1 and "
                 << n << "." << endl;
            return 1;
        }
    }
    Solution obj;
    cout << "Input array: ";
    for (int value : nums) {
        cout << value << " ";
    }
    cout << endl;
    cout << "Duplicate Number: " << obj.findDuplicate(nums) << endl;
    return 0;
}