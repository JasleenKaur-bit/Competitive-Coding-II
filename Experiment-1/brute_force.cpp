#include <iostream>
#include <vector>

using namespace std;
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j] && (j - i) <= k)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << "Enter value of k: ";
    cin >> k;
    if (containsNearbyDuplicate(nums, k))
        cout << "Output : True";
    else
        cout << "Output : False";
    return 0;
}