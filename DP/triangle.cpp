/*
Problem: Triangle

LeetCode:
https://leetcode.com/problems/triangle/

Goal:
Given a triangle of numbers, find the minimum path sum
from the top to the bottom.

From each position, you can move to:

    1. The same column in the next row
    2. The next column in the next row

For example:

        2
       3 4
      6 5 7
     4 1 8 3

From 2, we can move to 3 or 4.

Approach:
Bottom-Up Dynamic Programming with O(N) Space

Start with the last row:

    dp = last row of triangle

Here:

    dp[j]

represents the minimum path sum from position j
in the current processed row down to the bottom.

For a position triangle[i][j], there are two choices:

    Down:
        dp[j]

    Down-right:
        dp[j + 1]

Therefore:

    dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])

Process the triangle from the second-last row toward
the top.

Because each row only needs information from the row
directly below it, we do not need a complete 2D DP table.

Key Insight:

Instead of starting from the top and trying to calculate
all possible paths, start from the bottom where the minimum
path sums are already known.

Each row updates the DP values of the row below it.

Eventually:

    dp[0]

contains the minimum path sum from the top to the bottom.

PseudoCode : 

Copy the last row into DP

For every row from bottom to top:

    For every element in that row:

        Choose the smaller of:
            DP value directly below
            DP value diagonally below-right

        Add the current triangle value

        Store the result in DP

Return DP[0]


Complexity Analysis : 

Time Complexity: O(N²)
Space Complexity: O(N)

where:
N = number of rows in the triangle.

The triangle contains O(N²) elements, and the DP array
contains N elements.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        // Start DP with the last row
        vector<int> dp = triangle[n - 1];

        // Process rows from bottom to top
        for(int i = n - 2; i >= 0; i--) {

            // Process every element in the current row
            for(int j = 0; j <= i; j++) {

                // Choose the cheaper path below
                dp[j] = triangle[i][j]
                      + min(dp[j + 1], dp[j]);
            }
        }

        // dp[0] contains the minimum path sum
        return dp[0];
    }
};

int main() {

    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    Solution obj;

    cout << "Minimum Path Sum: "
         << obj.minimumTotal(triangle)
         << endl;

    return 0;
}