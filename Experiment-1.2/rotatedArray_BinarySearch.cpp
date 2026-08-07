#include <iostream>
#include <vector>
using namespace std;
int searchElement(const vector<int>& arr, int key)
{
    int start = 0;
    int finish = arr.size() - 1;
    while (start <= finish)
    {
        int middle = start + (finish - start) / 2;
        if (arr[middle] == key)
        {
            return middle;
        }
        if (arr[start] <= arr[middle])
        {
            if (key >= arr[start] && key < arr[middle])
            {
                finish = middle - 1;
            }
            else
            {
                start = middle + 1;
            }
        }
        else
        {
            if (key > arr[middle] && key <= arr[finish])
            {
                start = middle + 1;
            }
            else
            {
                finish = middle - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int size;
    cout << "===== Search in Rotated Sorted Array (Binary Search) =====\n\n";
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
    int result = searchElement(arr, key);
    if (result == -1)
        cout << "\nElement not found.";
    else
        cout << "\nElement found at index: " << result;
    return 0;
}