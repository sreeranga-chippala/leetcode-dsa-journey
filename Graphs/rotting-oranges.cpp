/*
Problem: Rotting Oranges

LeetCode:
https://leetcode.com/problems/rotting-oranges/

Goal:
Find the minimum number of minutes required
for all fresh oranges to become rotten.

Grid values:

    0 → Empty cell
    1 → Fresh orange
    2 → Rotten orange

A rotten orange can rot a fresh orange
in the four directions:

    Up
    Down
    Left
    Right


Approach:
Multi-Source BFS + Time Tracking

Important:

All initially rotten oranges spread rot
at the same time.

Therefore, we put ALL rotten oranges
into the queue before starting BFS.

For every queue element, we store:

    row
    column
    time

When a fresh orange is reached:

    new time = current time + 1

We also use a visited matrix so that
each orange is processed only once.

After BFS:

    If any fresh orange is still unvisited:

        return -1

    Otherwise:

        return the maximum time.


Time Complexity:
O(m * n)

Every cell is processed at most once.

Space Complexity:
O(m * n)

For the visited matrix and BFS queue.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// --------------------------------------------------
// Rotting Oranges
// --------------------------------------------------

class Solution {

public:

    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();


        // Stores the maximum time taken
        // for an orange to become rotten.
        int ans = 0;


        // Keeps track of cells that have already
        // been added to the BFS process.
        vector<vector<int>> visited(
            m,
            vector<int>(n, 0)
        );


        /*
            Queue stores:

                {{row, column}, time}

            Time represents the number of minutes
            taken to reach that cell.
        */
        queue<pair<pair<int, int>, int>> q;


        // --------------------------------------------------
        // Add all initially rotten oranges to the queue.
        //
        // This is Multi-Source BFS.
        //
        // All of them start spreading rot at time 0.
        // --------------------------------------------------

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {

                    visited[i][j] = 1;

                    q.push({
                        {i, j},
                        0
                    });
                }
            }
        }


        // --------------------------------------------------
        // BFS
        // --------------------------------------------------

        while (!q.empty()) {

            // Get the front cell.
            int r = q.front().first.first;
            int c = q.front().first.second;

            // Get the time at which this orange
            // became rotten.
            int t = q.front().second;

            q.pop();


            // Keep track of the maximum time.
            ans = max(ans, t);


            // --------------------------------------------------
            // Move UP
            // --------------------------------------------------

            if (r > 0 &&
                !visited[r - 1][c] &&
                grid[r - 1][c] == 1) {

                // Fresh orange becomes rotten
                // one minute later.
                q.push({
                    {r - 1, c},
                    t + 1
                });

                // Mark it immediately so that
                // it is not added again.
                visited[r - 1][c] = 1;
            }


            // --------------------------------------------------
            // Move DOWN
            // --------------------------------------------------

            if (r < m - 1 &&
                !visited[r + 1][c] &&
                grid[r + 1][c] == 1) {

                q.push({
                    {r + 1, c},
                    t + 1
                });

                visited[r + 1][c] = 1;
            }


            // --------------------------------------------------
            // Move LEFT
            // --------------------------------------------------

            if (c > 0 &&
                !visited[r][c - 1] &&
                grid[r][c - 1] == 1) {

                q.push({
                    {r, c - 1},
                    t + 1
                });

                visited[r][c - 1] = 1;
            }


            // --------------------------------------------------
            // Move RIGHT
            // --------------------------------------------------

            if (c < n - 1 &&
                !visited[r][c + 1] &&
                grid[r][c + 1] == 1) {

                q.push({
                    {r, c + 1},
                    t + 1
                });

                visited[r][c + 1] = 1;
            }
        }


        // --------------------------------------------------
        // Check whether any fresh orange is still
        // unvisited.
        //
        // If yes, it was impossible to rot it.
        // --------------------------------------------------

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (!visited[i][j] &&
                    grid[i][j] == 1) {

                    return -1;
                }
            }
        }


        // All fresh oranges became rotten.
        return ans;
    }
};


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
        Initial grid:

        2 1 1
        1 1 0
        0 1 1

        2 = Rotten orange
        1 = Fresh orange
        0 = Empty cell

        The rot spreads simultaneously
        from all rotten oranges.

        Answer = 4 minutes
    */

    vector<vector<int>> grid = {

        {2, 1, 1},

        {1, 1, 0},

        {0, 1, 1}
    };


    Solution obj;


    // Find the minimum time required.
    int result = obj.orangesRotting(grid);


    // Print the result.
    cout << "Minimum Minutes: "
         << result
         << endl;


    return 0;
}