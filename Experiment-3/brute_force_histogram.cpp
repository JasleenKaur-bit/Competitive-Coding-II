#include <iostream>
#include <vector>
using namespace std;
/*
    Purpose:
    Finds the largest rectangular area that can be formed
    in a histogram using the Brute Force approach.
*/
int largestRectangleArea(vector<int>& heights)
{
    int n = heights.size();
    int maxArea = 0;
    // Select each bar as the starting point of the rectangle
    for (int i = 0; i < n; i++)
    {
        // Initially, the minimum height is the height of the first bar
        int minHeight = heights[i];
        // Extend the rectangle from the current starting position
        for (int j = i; j < n; j++)
        {
            // Update the minimum height within the current range
            if (heights[j] < minHeight)
                minHeight = heights[j];
            // Calculate the width of the current rectangle
            int width = j - i + 1;
            // Calculate the area using minimum height and width
            int area = minHeight * width;
            // Update maximum area if the current area is larger
            if (area > maxArea)
                maxArea = area;
        }
    }
    // Return the largest rectangle area found
    return maxArea;
}
int main()
{
    int n;
    // Display the program title
    cout << "=========================================\n";
    cout << "Largest Rectangle in Histogram (Brute Force)\n";
    cout << "=========================================\n";
    // Take the number of histogram bars as input
    cout << "Enter Number of Bars: ";
    cin >> n;
    // Create a vector to store the heights of all bars
    vector<int> heights(n);
    // Take the height of each histogram bar as input
    cout << "Enter Heights: ";
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    // Calculate and display the largest rectangle area
    cout << "\nLargest Rectangle Area = "
         << largestRectangleArea(heights);
    return 0; // Indicate successful program execution
}