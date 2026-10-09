#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // Compare each element with the following elements
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        return -1;
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
    // Check that the input follows the problem constraints
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