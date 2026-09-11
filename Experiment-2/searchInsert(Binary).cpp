#include <iostream>
#include <vector>
using namespace std;
int findInsertPosition(const vector<int>& arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int middle = start + (end - start) / 2;
        if (arr[middle] == target)
        {
            return middle;
        }
        else if (target > arr[middle])
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    return start;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> numbers(n);
    cout << "Enter " << n << " sorted distinct elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    int target;
    cout << "Enter the target element: ";
    cin >> target;
    int position = findInsertPosition(numbers, target);
    cout << "\nSearch Insert Position = " << position << endl;
    return 0;
}