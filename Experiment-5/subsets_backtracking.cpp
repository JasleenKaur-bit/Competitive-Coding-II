#include <iostream>
#include <vector>
using namespace std;
void buildSubsets(
    const vector<int>& numbers,
    int start,
    vector<int>& currentSubset,
    vector<vector<int>>& allSubsets)
{
    allSubsets.push_back(currentSubset);
    for (int i = start; i < numbers.size(); i++)
    {
        currentSubset.push_back(numbers[i]);
        buildSubsets(
            numbers,
            i + 1,
            currentSubset,
            allSubsets
        );
        currentSubset.pop_back();
    }
}
vector<vector<int>> generateSubsets(const vector<int>& numbers)
{
    vector<vector<int>> allSubsets;
    vector<int> currentSubset;
    buildSubsets(numbers, 0, currentSubset, allSubsets);
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
    cout << "          SUBSETS - BACKTRACKING\n";
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