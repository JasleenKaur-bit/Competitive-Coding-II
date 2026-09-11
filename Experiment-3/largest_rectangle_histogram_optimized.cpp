#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// Finds the largest rectangle using a monotonic stack
int findLargestRectangle(vector<int> &bars)
{
    stack<int> indexStack;
    int maximumArea = 0;
    // Add a sentinel bar to process remaining elements
    bars.push_back(0);
    int n = bars.size();
    for (int current = 0; current < n; current++)
    {
        // Process bars taller than the current bar
        while (!indexStack.empty() &&
               bars[indexStack.top()] > bars[current])
        {
            int currentHeight = bars[indexStack.top()];
            indexStack.pop();
            // Find the nearest smaller bar on the left
            int leftBoundary;
            if (indexStack.empty())
                leftBoundary = -1;
            else
                leftBoundary = indexStack.top();
            // Calculate width and area of the rectangle
            int currentWidth = current - leftBoundary - 1;
            int currentArea = currentHeight * currentWidth;
            // Update the maximum area
            if (currentArea > maximumArea)
                maximumArea = currentArea;
        }
        // Store the current bar index in the stack
        indexStack.push(current);
    }
    // Remove the sentinel bar
    bars.pop_back();
    return maximumArea;
}
int main()
{
    int totalBars;
    // Display program title
    cout << "=============================================\n";
    cout << " Largest Rectangle in Histogram (Optimized)\n";
    cout << "=============================================\n";
    // Take the number of histogram bars
    cout << "Enter Total Number of Bars : ";
    cin >> totalBars;
    vector<int> histogram(totalBars);
    // Take the height of each bar
    cout << "Enter Height of Each Bar : ";
    for (int i = 0; i < totalBars; i++)
    {
        cin >> histogram[i];
    }
    // Display the entered histogram
    cout << "\nHistogram : ";
    for (int value : histogram)
    {
        cout << value << " ";
    }
    cout << "\n";
    // Calculate the maximum rectangle area
    int answer = findLargestRectangle(histogram);
    cout << "\nMaximum Rectangle Area = " << answer << endl;
    // Display algorithm complexity
    cout << "\nTime Complexity : O(n)";
    cout << "\nSpace Complexity : O(n)";
    cout << "\n\nProgram Executed Successfully.\n";
    return 0;
}