#include <iostream>
#include <vector>
using namespace std;
bool searchInRotatedArray(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[left] == nums[mid] && nums[mid] == nums[right])
        {
            left++;
            right--;
        }
        else if (nums[left] <= nums[mid])
        {
            if (target >= nums[left] && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (target > nums[mid] && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cout << "========== Search in Rotated Sorted Array II ==========\n\n";
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter rotated sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cout << "Enter target element: ";
    cin >> target;
    bool found = searchInRotatedArray(nums, target);
    cout << "\n---------------------------------\n";
    if (found)
    {
        cout << "Result : True\n";
        cout << "Target element is present in the array.\n";
    }
    else
    {
        cout << "Result : False\n";
        cout << "Target element is not present in the array.\n";
    }
    cout << "---------------------------------\n";
    return 0;
}