#include <iostream>
#include <vector>
using namespace std;
int searchInsertPosition(const vector<int>& numbers, int target)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        // Target found
        if (numbers[i] == target)
        {
            return i;
        }
        // First element greater than target
        if (numbers[i] > target)
        {
            return i;
        }
    }
    // Target is greater than all elements
    return numbers.size();
}
int main()
{
    int n;
    cout << "===== Search Insert Position (Brute Force) =====\n\n";
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> numbers(n);
    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    int target;
    cout << "Enter target element: ";
    cin >> target;
    int position = searchInsertPosition(numbers, target);
    cout << "\nSearch Insert Position = " << position << endl;
    return 0;
}