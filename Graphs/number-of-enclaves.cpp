/*
Problem: Number of Enclaves

LeetCode:
https://leetcode.com/problems/number-of-enclaves/

Goal:
Find the number of land cells that cannot walk off
the boundary of the grid.

Grid:

    0 -> Water
    1 -> Land

A land cell is an enclave if it is not connected
to any boundary land cell.

Movement is allowed in four directions:

    Up
    Down
    Left
    Right


Approach:
Boundary DFS + Visited Matrix

Key Idea:

Instead of directly finding enclaves:

    Find all land cells connected to the boundary.

These cells can escape the grid, so they are NOT enclaves.

Steps:

1. Start DFS from every land cell on the boundary.

2. Mark every boundary-connected land cell as visited.

3. Traverse the interior of the grid.

4. Every land cell that is still unvisited is
   an enclave.

5. Count those cells.


PseudoCode : 

create visited matrix


for every row:

    if left boundary is land
       and not visited:

        DFS(left boundary)


    if right boundary is land
       and not visited:

        DFS(right boundary)


for every column:

    if top boundary is land
       and not visited:

        DFS(top boundary)


    if bottom boundary is land
       and not visited:

        DFS(bottom boundary)


DFS(r, c):

    mark current cell as visited

    explore:
        UP
        DOWN
        LEFT
        RIGHT

    only move to unvisited land cells


count = 0


for every interior cell:

    if cell is land
       and not visited:

        count++


return count


Complexity Analysis : 

Time Complexity: O(m * n)
Every cell is visited at most once.

Space Complexity: O(m * n)
For the visited matrix and DFS recursion stack.
*/

#include <iostream>
#include <vector>

using namespace std;


// --------------------------------------------------
// Solution Class
// --------------------------------------------------

class Solution {

public:

    // --------------------------------------------------
    // DFS
    //
    // Visits all land cells connected to the
    // current boundary land cell.
    // --------------------------------------------------

    void dfs(
        int r,
        int c,
        vector<vector<int>>& grid,
        vector<vector<int>>& visited
    ) {

        int m = grid.size();
        int n = grid[0].size();


        // Mark the current land cell as visited.
        visited[r][c] = 1;


        // --------------------------------------------------
        // Move UP
        // --------------------------------------------------

        if (r > 0 &&
            !visited[r - 1][c] &&
            grid[r - 1][c]) {

            dfs(
                r - 1,
                c,
                grid,
                visited
            );
        }


        // --------------------------------------------------
        // Move DOWN
        // --------------------------------------------------

        if (r < m - 1 &&
            !visited[r + 1][c] &&
            grid[r + 1][c]) {

            dfs(
                r + 1,
                c,
                grid,
                visited
            );
        }


        // --------------------------------------------------
        // Move LEFT
        // --------------------------------------------------

        if (c > 0 &&
            !visited[r][c - 1] &&
            grid[r][c - 1]) {

            dfs(
                r,
                c - 1,
                grid,
                visited
            );
        }


        // --------------------------------------------------
        // Move RIGHT
        // --------------------------------------------------

        if (c < n - 1 &&
            !visited[r][c + 1] &&
            grid[r][c + 1]) {

            dfs(
                r,
                c + 1,
                grid,
                visited
            );
        }
    }


    // --------------------------------------------------
    // Count Enclaves
    // --------------------------------------------------

    int numEnclaves(
        vector<vector<int>>& grid
    ) {

        int m = grid.size();
        int n = grid[0].size();


        // Keeps track of land cells that can
        // reach the boundary.
        vector<vector<int>> visited(
            m,
            vector<int>(n, 0)
        );


        // --------------------------------------------------
        // Start DFS from the LEFT and RIGHT boundaries.
        // --------------------------------------------------

        for (int i = 0; i < m; i++) {

            // Left boundary.
            if (grid[i][0] &&
                !visited[i][0]) {

                dfs(
                    i,
                    0,
                    grid,
                    visited
                );
            }


            // Right boundary.
            if (grid[i][n - 1] &&
                !visited[i][n - 1]) {

                dfs(
                    i,
                    n - 1,
                    grid,
                    visited
                );
            }
        }


        // --------------------------------------------------
        // Start DFS from the TOP and BOTTOM boundaries.
        // --------------------------------------------------

        for (int j = 0; j < n; j++) {

            // Top boundary.
            if (grid[0][j] &&
                !visited[0][j]) {

                dfs(
                    0,
                    j,
                    grid,
                    visited
                );
            }


            // Bottom boundary.
            if (grid[m - 1][j] &&
                !visited[m - 1][j]) {

                dfs(
                    m - 1,
                    j,
                    grid,
                    visited
                );
            }
        }


        // --------------------------------------------------
        // Count remaining unvisited land cells.
        //
        // These cells cannot reach the boundary,
        // so they are enclaves.
        // --------------------------------------------------

        int count = 0;


        // Only interior cells need to be checked.
        for (int i = 1; i < m - 1; i++) {

            for (int j = 1; j < n - 1; j++) {

                if (grid[i][j] &&
                    !visited[i][j]) {

                    count++;
                }
            }
        }


        return count;
    }
};


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
        Input:

        0 0 0 0
        1 0 1 0
        0 1 1 0
        0 0 0 0

        The land cells:

            (1,0)

        are connected to the boundary.

        The land cells:

            (1,2)
            (2,1)
            (2,2)

        form an enclosed region.

        Therefore:

            Number of enclave cells = 3
    */

    vector<vector<int>> grid = {

        {0, 0, 0, 0},

        {1, 0, 1, 0},

        {0, 1, 1, 0},

        {0, 0, 0, 0}
    };


    // Create Solution object.
    Solution obj;


    // Count enclave cells.
    int result = obj.numEnclaves(grid);


    // Print the result.
    cout << "Number of Enclave Cells: "
         << result
         << endl;


    return 0;
}