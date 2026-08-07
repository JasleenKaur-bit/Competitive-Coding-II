#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int n = heights.size();
    int maxArea = 0;

    for(int i = 0; i < n; i++)
    {
        int minHeight = heights[i];

        for(int j = i; j < n; j++)
        {
            if(heights[j] < minHeight)
                minHeight = heights[j];

            int width = j - i + 1;
            int area = minHeight * width;

            if(area > maxArea)
                maxArea = area;
        }
    }

    return maxArea;
}

int main()
{
    int n;

    cout << "=========================================\n";
    cout << "Largest Rectangle in Histogram (Brute Force)\n";
    cout << "=========================================\n";

    cout << "Enter Number of Bars: ";
    cin >> n;

    vector<int> heights(n);

    cout << "Enter Heights: ";

    for(int i = 0; i < n; i++)
        cin >> heights[i];

    cout << "\nLargest Rectangle Area = "
         << largestRectangleArea(heights);

    return 0;
}