/*

Problem: Number of Islands

LeetCode:
https://leetcode.com/problems/number-of-islands/

Goal:
Given a 2D grid containing '1' (land) and '0' (water),
find the total number of islands.

An island is formed by connecting adjacent land cells
horizontally or vertically.

Diagonal cells are NOT considered connected.

Approach:
DFS + Visited Matrix

For every cell:

    If the cell is land ('1')
    and it has not been visited:

        1. Start DFS from that cell.
        2. Visit every connected land cell.
        3. This represents one complete island.
        4. Increment the island count.

DFS explores in four directions:

    Up
    Down
    Left
    Right

PseudoCode : 

create visited matrix filled with 0

count = 0


for every cell (i, j):

    if grid[i][j] is land
       and cell is not visited:

        DFS(i, j)

        count++


DFS(i, j):

    mark current cell as visited

    if upper cell is valid
       and contains land
       and is not visited:

        DFS(upper cell)


    if lower cell is valid
       and contains land
       and is not visited:

        DFS(lower cell)


    if left cell is valid
       and contains land
       and is not visited:

        DFS(left cell)


    if right cell is valid
       and contains land
       and is not visited:

        DFS(right cell)


return count


Complexity Analysis : 

Time Complexity: O(r * c)

Every cell is visited at most once.

Space Complexity: O(r * c)

Visited matrix requires O(r * c) space.
The DFS recursion stack can also take O(r * c)
in the worst case.
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

    // --------------------------------------------------
    // DFS function
    //
    // Visits all connected land cells belonging
    // to the same island.
    // --------------------------------------------------

    void dfs(
        int i,
        int j,
        vector<vector<char>>& grid,
        vector<vector<int>>& visited
    ) {

        int r = grid.size();
        int c = grid[0].size();


        // Mark the current land cell as visited.
        visited[i][j] = 1;


        // --------------------------------------------------
        // Move UP
        // --------------------------------------------------

        if (i > 0 &&
            grid[i - 1][j] == '1' &&
            !visited[i - 1][j]) {

            dfs(i - 1, j, grid, visited);
        }


        // --------------------------------------------------
        // Move DOWN
        // --------------------------------------------------

        if (i < r - 1 &&
            grid[i + 1][j] == '1' &&
            !visited[i + 1][j]) {

            dfs(i + 1, j, grid, visited);
        }


        // --------------------------------------------------
        // Move LEFT
        // --------------------------------------------------

        if (j > 0 &&
            grid[i][j - 1] == '1' &&
            !visited[i][j - 1]) {

            dfs(i, j - 1, grid, visited);
        }


        // --------------------------------------------------
        // Move RIGHT
        // --------------------------------------------------

        if (j < c - 1 &&
            grid[i][j + 1] == '1' &&
            !visited[i][j + 1]) {

            dfs(i, j + 1, grid, visited);
        }
    }


    // --------------------------------------------------
    // Count the number of islands
    // --------------------------------------------------

    int numIslands(vector<vector<char>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        // Stores the total number of islands.
        int count = 0;


        // Initially, no cell has been visited.
        vector<vector<int>> visited(
            r,
            vector<int>(c, 0)
        );


        // Visit every cell in the grid.
        for (int i = 0; i < r; i++) {

            for (int j = 0; j < c; j++) {

                // If we find unvisited land,
                // it represents a new island.
                if (grid[i][j] == '1' &&
                    !visited[i][j]) {

                    // Visit the complete island.
                    dfs(i, j, grid, visited);

                    // One complete island has been found.
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
        Example grid:

        1 1 1 1 0
        1 1 0 1 0
        1 1 0 0 0
        0 0 0 0 0

        All connected land cells form one island.
    */

    vector<vector<char>> grid = {

        {'1', '1', '1', '1', '0'},

        {'1', '1', '0', '1', '0'},

        {'1', '1', '0', '0', '0'},

        {'0', '0', '0', '0', '0'}
    };


    // Create Solution object.
    Solution obj;


    // Find the number of islands.
    int result = obj.numIslands(grid);


    // Print the result.
    cout << "Number of Islands: "
         << result
         << endl;


    return 0;
}