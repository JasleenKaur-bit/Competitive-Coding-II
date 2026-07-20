#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> lastIndex;
    for (int i = 0; i < nums.size(); i++)
    {
        if (lastIndex.find(nums[i]) != lastIndex.end())
        {
            int distance = i - lastIndex[nums[i]];
            if (distance <= k)
                return true;
        }
        lastIndex[nums[i]] = i;
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