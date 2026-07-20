#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums)
{
    int n = nums.size();
    vector<int> answer(n);
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                product *= nums[j];
            }
        }
        answer[i] = product;
    }
    return answer;
}
int main()
{
    int n;
    cout << "==========================================\n";
    cout << " Product of Array Except Self (Brute Force)\n";
    cout << "==========================================\n\n";
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> result = productExceptSelf(nums);
    cout << "\nOutput Array:\n";
    for (int value : result)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}