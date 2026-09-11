#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums)
{
    int n = nums.size();
    vector<int> answer(n, 1);
    for (int i = 1; i < n; i++)
    {
        answer[i] = answer[i - 1] * nums[i - 1];
    }
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    return answer;
}
int main()
{
    int n;
    cout << "=============================================\n";
    cout << " Product of Array Except Self (Prefix-Suffix)\n";
    cout << "=============================================\n\n";
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
