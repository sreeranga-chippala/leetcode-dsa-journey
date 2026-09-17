/*
Problem: Unique Paths 

LeetCode:
https://leetcode.com/problems/unique-paths/

Goal:
Given an m × n grid, start at the top-left cell and reach
the bottom-right cell.

At every cell, you can move only:

    Right
    Down

Return the total number of unique paths.

Approach:
2D Dynamic Programming

Let:

    dp[i][j] = number of unique paths to reach cell (i, j)

To reach cell (i, j), the last move can only come from:

    1. The cell above:
           (i - 1, j)

    2. The cell on the left:
           (i, j - 1)

Therefore:

    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

Base Cases:

Every cell in the first row can only be reached by
moving right.

Therefore:

    dp[0][j] = 1

Every cell in the first column can only be reached by
moving down.

Therefore:

    dp[i][0] = 1

Algorithm:

1. Create an m × n DP table.
2. Fill the first column with 1.
3. Fill the first row with 1.
4. For every remaining cell:
       add the paths from above and from the left.
5. Return dp[m-1][n-1].

Key Insight:

Every path reaching a cell must come from either:

        Above
          ↓
    [previous cell]
          ↓
       [current]

or:

    [previous] → [current]

So:

    Current paths = Above paths + Left paths


PseudoCode : 

Create an M × N DP table

Set every cell in the first row to 1
Set every cell in the first column to 1

For every remaining cell:

    paths from above = dp[i-1][j]
    paths from left  = dp[i][j-1]

    dp[i][j] = paths from above + paths from left

Return dp[M-1][N-1]


Complexity Analysis : 

Time Complexity: O(M * N)
Space Complexity: O(M * N)

where:
M = number of rows
N = number of columns.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int uniquePaths(int m, int n) {

        // Create the DP table
        vector<vector<int>> dp(
            m, vector<int>(n, -1)
        );

        // First column can only be reached by moving down
        for(int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        // First row can only be reached by moving right
        for(int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        // Fill the remaining cells
        for(int i = 1; i < m; i++) {

            for(int j = 1; j < n; j++) {

                // Paths coming from above
                int right = dp[i - 1][j];

                // Paths coming from the left
                int down = dp[i][j - 1];

                // Total paths to current cell
                dp[i][j] = right + down;
            }
        }

        // Return paths to bottom-right cell
        return dp[m - 1][n - 1];
    }
};

int main() {

    int m = 3;
    int n = 7;

    Solution obj;

    cout << "Number of Unique Paths: "
         << obj.uniquePaths(m, n)
         << endl;

    return 0;
}