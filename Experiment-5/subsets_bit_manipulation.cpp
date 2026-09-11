#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateSubsets(const vector<int>& numbers)
{
    vector<vector<int>> allSubsets;
    int totalSubsets = 1 << numbers.size();
    for (int mask = 0; mask < totalSubsets; mask++)
    {
        vector<int> currentSubset;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (mask & (1 << i))
            {
                currentSubset.push_back(numbers[i]);
            }
        }
        allSubsets.push_back(currentSubset);
    }
    return allSubsets;
}
void displaySubsets(const vector<vector<int>>& allSubsets)
{
    cout << "\nAll Possible Subsets:\n";
    for (const auto& subset : allSubsets)
    {
        cout << "{ ";
        for (int value : subset)
        {
            cout << value << " ";
        }
        cout << "}\n";
    }
}
int main()
{
    int n;
    cout << "============================================\n";
    cout << "       SUBSETS - BIT MANIPULATION\n";
    cout << "============================================\n";
    cout << "Enter Number of Elements: ";
    cin >> n;
    vector<int> numbers(n);
    cout << "Enter " << n << " Unique Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    cout << "\nInput Array: { ";
    for (int value : numbers)
    {
        cout << value << " ";
    }
    cout << "}\n";
    vector<vector<int>> result = generateSubsets(numbers);
    cout << "Total Subsets: " << result.size() << "\n";
    displaySubsets(result);
    cout << "\nTime Complexity: O(n * 2^n)";
    cout << "\nSpace Complexity: O(n * 2^n)\n";
    cout << "\nProgram Executed Successfully.\n";
    return 0;
}