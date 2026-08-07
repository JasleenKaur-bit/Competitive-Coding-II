#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int findLargestRectangle(vector<int> &bars)
{
    stack<int> indexStack;
    int maximumArea = 0;
    // Sentinel Bar
    bars.push_back(0);
    int n = bars.size();
    for (int current = 0; current < n; current++)
    {
        while (!indexStack.empty() &&
               bars[indexStack.top()] > bars[current])
        {
            int currentHeight = bars[indexStack.top()];
            indexStack.pop();
            int leftBoundary;
            if (indexStack.empty())
                leftBoundary = -1;
            else
                leftBoundary = indexStack.top();
            int currentWidth = current - leftBoundary - 1;
            int currentArea = currentHeight * currentWidth;
            if (currentArea > maximumArea)
                maximumArea = currentArea;
        }
        indexStack.push(current);
    }
    bars.pop_back();
    return maximumArea;
}
int main()
{
    int totalBars;
    cout << "=============================================\n";
    cout << " Largest Rectangle in Histogram (Optimized)\n";
    cout << "=============================================\n";
    cout << "Enter Total Number of Bars : ";
    cin >> totalBars;
    vector<int> histogram(totalBars);
    cout << "Enter Height of Each Bar : ";
    for (int i = 0; i < totalBars; i++)
    {
        cin >> histogram[i];
    }
    cout << "\nHistogram : ";
    for (int value : histogram)
    {
        cout << value << " ";
    }
    cout << "\n";
    int answer = findLargestRectangle(histogram);
    cout << "\nMaximum Rectangle Area = " << answer << endl;
    cout << "\nTime Complexity : O(n)";
    cout << "\nSpace Complexity : O(n)";
    cout << "\n\nProgram Executed Successfully.\n";
    return 0;
}