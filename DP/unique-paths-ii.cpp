/*
Problem: Unique Paths II

LeetCode:
https://leetcode.com/problems/unique-paths-ii/

Goal:
Given an m × n grid containing obstacles, find the number
of unique paths from the top-left cell to the bottom-right
cell.

You can move only:

    Right
    Down

A cell containing 1 is an obstacle and cannot be visited.

Approach:
Recursion + Memoization

Let:

    dp[i][j] = number of valid paths from (0,0)
               to (i,j)

For cell (i,j), the last move can come from:

    1. Left  → (i, j-1)
    2. Above → (i-1, j)

Therefore:

    dp[i][j] =
        dp[i][j-1] + dp[i-1][j]

Base Cases:

1. If i < 0 or j < 0:
       return 0

   The position is outside the grid.

2. If obstacleGrid[i][j] == 1:
       return 0

   An obstacle cannot be used.

3. If (i,j) == (0,0):
       return 1

   There is exactly one way to be at the starting cell
   when it is not an obstacle.

4. If dp[i][j] has already been calculated:
       return dp[i][j]

Key Insight:

The normal Unique Paths recurrence remains the same:

    left + above

but obstacles contribute:

    0 paths

Memoization prevents recalculating the same cells.

PseudoCode : 

Create DP table initialized to -1

Start from bottom-right cell

If cell is outside the grid:
    return 0

If cell is an obstacle:
    return 0

If cell is the starting cell:
    return 1

If result for current cell is already known:
    return stored result

paths_from_left = solve(i, j-1)
paths_from_above = solve(i-1, j)

Store and return:

    paths_from_left + paths_from_above

    
Complexity Analysis : 

Time Complexity: O(M * N)
Space Complexity: O(M * N)

where:
M = number of rows
N = number of columns.

The O(M*N) space includes the DP table and the recursion
stack in the worst case.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int helper(
        int i,
        int j,
        vector<vector<int>>& obstacleGrid,
        vector<vector<int>>& dp
    ) {

        // Outside the grid
        if(i < 0 || j < 0) {
            return 0;
        }

        // Obstacle cannot be visited
        if(obstacleGrid[i][j] == 1) {
            return 0;
        }

        // Starting cell
        if(i == 0 && j == 0) {
            return 1;
        }

        // Return already calculated result
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Move from left
        int right = helper(
            i,
            j - 1,
            obstacleGrid,
            dp
        );

        // Move from above
        int bottom = helper(
            i - 1,
            j,
            obstacleGrid,
            dp
        );

        // Store number of paths
        return dp[i][j] = right + bottom;
    }

    int uniquePathsWithObstacles(
        vector<vector<int>>& obstacleGrid
    ) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // DP table for memoization
        vector<vector<int>> dp(
            m,
            vector<int>(n, -1)
        );

        return helper(
            m - 1,
            n - 1,
            obstacleGrid,
            dp
        );
    }
};

int main() {

    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Solution obj;

    cout << "Unique Paths with Obstacles: "
         << obj.uniquePathsWithObstacles(obstacleGrid)
         << endl;

    return 0;
}