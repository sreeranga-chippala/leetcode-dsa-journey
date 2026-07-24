/*
Problem: Largest Rectangle in Histogram

LeetCode:
https://leetcode.com/problems/largest-rectangle-in-histogram/

Goal:
Given the heights of histogram bars,
find the area of the largest rectangle.

Approach:
Monotonic Increasing Stack

For every bar:

1. Find the Previous Smaller Element (PSE).
2. Find the Next Smaller Element (NSE).

These two boundaries determine the maximum width
over which the current bar can extend while
remaining the smallest height.

Rectangle Area:

height × width

where

width = NSE - PSE - 1

Key Insight:
Treat every bar as the limiting (minimum) height
of a rectangle and calculate the largest rectangle
it can form.

Time Complexity: O(n)

Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> nse(n);
        vector<int> pse(n);

        stack<int> stk;

        // Find Next Smaller Element
        for(int i = n - 1; i >= 0; i--){

            while(!stk.empty() &&
                  heights[i] <= heights[stk.top()]){
                stk.pop();
            }

            if(stk.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = stk.top();
            }

            stk.push(i);
        }

        // Clear stack
        while(!stk.empty()){
            stk.pop();
        }

        // Find Previous Smaller Element
        for(int i = 0; i < n; i++){

            while(!stk.empty() &&
                  heights[i] <= heights[stk.top()]){
                stk.pop();
            }

            if(stk.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = stk.top();
            }

            stk.push(i);
        }

        int maxArea = 0;

        // Calculate maximum rectangle area
        for(int i = 0; i < n; i++){

            int width = nse[i] - pse[i] - 1;

            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main(){

    Solution obj;

    vector<int> heights = {2,1,5,6,2,3};

    cout << obj.largestRectangleArea(heights);

    return 0;
}