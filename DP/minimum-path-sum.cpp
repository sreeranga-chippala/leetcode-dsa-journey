/*
Problem: Minimum Path Sum

LeetCode:
https://leetcode.com/problems/minimum-path-sum/

Goal:
Given an m × n grid containing non-negative numbers,
find a path from the top-left cell to the bottom-right
cell such that the sum of all values along the path
is minimized.

You can move only:

    Right
    Down

Approach:
Recursion + Memoization

Let:

    dp[i][j] = minimum path sum required to reach
               cell (i,j) from the starting cell.

To reach (i,j), the previous cell must be:

    1. Left  → (i, j-1)
    2. Above → (i-1, j)

Therefore:

    dp[i][j] =
        grid[i][j] + min(
            dp[i][j-1],
            dp[i-1][j]
        )

Base Cases:

1. If i < 0 or j < 0:
       return INT_MAX

   The position is outside the grid and cannot be used
   as a valid path.

2. If (i,j) == (0,0):
       return grid[0][0]

   The starting cell contributes its own value.

3. If dp[i][j] is already calculated:
       return dp[i][j]

Key Insight:

Unlike Unique Paths, where we ADD the number of ways,
here we take the MINIMUM of the possible previous paths.

    Unique Paths:
        left + above

    Minimum Path Sum:
        current value + min(left, above)

Memoization ensures every cell is solved only once.

PseudoCode : 

Create DP table initialized to -1

Start from bottom-right cell

If cell is outside the grid:
    return infinity

If cell is the starting cell:
    return its value

If result for current cell is already known:
    return stored result

left = solve(i, j-1)
above = solve(i-1, j)

Choose the smaller previous path

current answer =
    current cell value + minimum(left, above)

Store and return the result


Complexity Analysis : 

Time Complexity: O(M * N)
Space Complexity: O(M * N)

where:
M = number of rows
N = number of columns.

The space includes the M × N DP table and recursion
stack in the worst case.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:

    int helper(
        int i,
        int j,
        vector<vector<int>>& grid,
        vector<vector<int>>& dp
    ) {

        // Outside the grid
        if(i < 0 || j < 0) {
            return INT_MAX;
        }

        // Starting cell
        if(i == 0 && j == 0) {
            return grid[0][0];
        }

        // Return already calculated result
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Minimum path coming from the left
        int right = helper(
            i,
            j - 1,
            grid,
            dp
        );

        // Minimum path coming from above
        int bottom = helper(
            i - 1,
            j,
            grid,
            dp
        );

        // Add current cell to the cheaper path
        return dp[i][j] =
            grid[i][j] + min(right, bottom);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // DP table for memoization
        vector<vector<int>> dp(
            m,
            vector<int>(n, -1)
        );

        return helper(
            m - 1,
            n - 1,
            grid,
            dp
        );
    }
};

int main() {

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    Solution obj;

    cout << "Minimum Path Sum: "
         << obj.minPathSum(grid)
         << endl;

    return 0;
}