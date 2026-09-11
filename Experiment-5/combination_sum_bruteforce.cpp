#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
void explore(
    const vector<int>& candidates,
    int remaining,
    vector<int>& current,
    set<vector<int>>& uniqueCombinations)
{
    if (remaining == 0)
    {
        vector<int> combination = current;
        sort(combination.begin(), combination.end());
        uniqueCombinations.insert(combination);
        return;
    }
    if (remaining < 0)
        return;
    for (int value : candidates)
    {
        current.push_back(value);
        explore(
            candidates,
            remaining - value,
            current,
            uniqueCombinations
        );
        current.pop_back();
    }
}
int main()
{
    int n, target;
    cout << "============================================\n";
    cout << "       COMBINATION SUM - BRUTE FORCE\n";
    cout << "============================================\n";
    cout << "Enter Number of Candidates: ";
    cin >> n;
    vector<int> candidates(n);
    cout << "Enter " << n << " Distinct Positive Values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> candidates[i];
    }
    cout << "Enter Target Value: ";
    cin >> target;
    vector<int> current;
    set<vector<int>> uniqueCombinations;
    explore(candidates, target, current, uniqueCombinations);
    cout << "\nCandidates: { ";
    for (int value : candidates)
        cout << value << " ";
    cout << "}\n";
    cout << "Target: " << target << "\n";
    cout << "\nValid Combinations:\n";
    if (uniqueCombinations.empty())
    {
        cout << "No combination found.\n";
    }
    else
    {
        for (const auto& combination : uniqueCombinations)
        {
            cout << "[ ";
            for (int value : combination)
                cout << value << " ";
            cout << "]\n";
        }
    }
    cout << "\nTotal Unique Combinations: "
         << uniqueCombinations.size() << "\n";
    cout << "\nApproach: Brute Force with Duplicate Filtering";
    cout << "\nTime Complexity: Exponential";
    cout << "\nAuxiliary Space: O(target / minimum candidate)\n";
    cout << "\nProgram Executed Successfully.\n";
    return 0;
}