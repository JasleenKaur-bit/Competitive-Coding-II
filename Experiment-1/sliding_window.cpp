#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> window;
    for (int i = 0; i < nums.size(); i++)
    {
        if (window.count(nums[i]))
            return true;
        window.insert(nums[i]);
        if (window.size() > k)
        {
            window.erase(nums[i - k]);
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