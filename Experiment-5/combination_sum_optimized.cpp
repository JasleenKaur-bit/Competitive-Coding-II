#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findCombinations(
    const vector<int>& candidates,
    int start,
    int remaining,
    vector<int>& current,
    vector<vector<int>>& result)
{
    if (remaining == 0)
    {
        result.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        if (candidates[i] > remaining)
            break;
        current.push_back(candidates[i]);
        findCombinations(
            candidates,
            i,
            remaining - candidates[i],
            current,
            result
        );
        current.pop_back();
    }
}
int main()
{
    int n, target;
    cout << "============================================\n";
    cout << "       COMBINATION SUM - OPTIMIZED\n";
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
    sort(candidates.begin(), candidates.end());
    vector<int> current;
    vector<vector<int>> result;
    findCombinations(
        candidates,
        0,
        target,
        current,
        result
    );
    cout << "\nCandidates: { ";
    for (int value : candidates)
        cout << value << " ";
    cout << "}\n";
    cout << "Target: " << target << "\n";
    cout << "\nValid Combinations:\n";
    if (result.empty())
    {
        cout << "No combination found.\n";
    }
    else
    {
        for (const auto& combination : result)
        {
            cout << "[ ";
            for (int value : combination)
                cout << value << " ";
            cout << "]\n";
        }
    }
    cout << "\nTotal Combinations: "
         << result.size() << "\n";
    cout << "\nApproach: Backtracking with Start Index";
    cout << "\nTime Complexity: Exponential";
    cout << "\nAuxiliary Space: O(target / minimum candidate)\n";
    cout << "\nProgram Executed Successfully.\n";
    return 0;
}