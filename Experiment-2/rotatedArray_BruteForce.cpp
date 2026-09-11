#include <iostream>
#include <vector>
using namespace std;
int linearSearch(const vector<int>& arr, int key)
{
    for (int index = 0; index < arr.size(); index++)
    {
        if (arr[index] == key)
        {
            return index;
        }
    }
    return -1;
}
int main()
{
    int size;
    cout << "===== Search in Rotated Sorted Array (Brute Force) =====\n\n";
    cout << "Enter number of elements: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter rotated sorted array:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter target element: ";
    cin >> key;
    int result = linearSearch(arr, key);
    if (result == -1)
        cout << "\nElement not found.";
    else
        cout << "\nElement found at index: " << result;
    return 0;
}