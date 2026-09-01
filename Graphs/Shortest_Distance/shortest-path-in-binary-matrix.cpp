/*
Problem: Shortest Path in Binary Matrix

LeetCode:
https://leetcode.com/problems/shortest-path-in-binary-matrix/

Goal:
Find the length of the shortest clear path from
the top-left cell (0,0) to the bottom-right cell.

Grid:

    0 -> Open cell
    1 -> Blocked cell

Movement is allowed in 8 directions:

    ↑  ↖  ↗
    ←     →
    ↓  ↙  ↘

A valid path can only move through cells containing 0.

Approach:
BFS + Distance Matrix

Why BFS?

Every movement has the same cost:

    Moving to any neighboring cell = 1 step

Therefore, BFS finds the shortest path.

We maintain:

    distance[i][j]

which stores the shortest known distance from
(0,0) to cell (i,j).

Initially:

    distance[0][0] = 1

For every neighboring open cell:

    new distance = current distance + 1

If this new distance is smaller than the previously
known distance, update it and push the cell into
the queue.

Important:
There are 8 possible directions.

PseudoCode : 

if starting cell is blocked
   or ending cell is blocked:

    return -1


create distance matrix
initialize every distance to infinity


distance[0][0] = 1

create queue

push (0, 0, distance 1)


while queue is not empty:

    remove current cell

    for each of 8 directions:

        if neighbor is inside grid
           and neighbor is 0
           and new distance is smaller:

            update neighbor distance

            push neighbor into queue


if destination distance is infinity:

    return -1


return destination distance


Complexity Analysis : 

Time Complexity: O(m * n)
Every cell can be processed a bounded number of times.

Space Complexity: O(m * n)
For the distance matrix and BFS queue.
*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// --------------------------------------------------
// Solution Class
// --------------------------------------------------

class Solution {

public:

    int shortestPathBinaryMatrix(
        vector<vector<int>>& grid
    ) {

        int m = grid.size();
        int n = grid[0].size();


        // --------------------------------------------------
        // If the starting or ending cell is blocked,
        // no valid path exists.
        // --------------------------------------------------

        if (grid[0][0] == 1 ||
            grid[m - 1][n - 1] == 1) {

            return -1;
        }


        // --------------------------------------------------
        // distance[i][j] stores the shortest known
        // distance from (0,0) to (i,j).
        //
        // Initially, all distances are infinity.
        // --------------------------------------------------

        vector<vector<int>> distance(
            m,
            vector<int>(n, INT_MAX)
        );


        // Starting cell has path length 1.
        distance[0][0] = 1;


        /*
            Queue stores:

                {distance, {row, column}}

            The distance tells us how many cells
            are present in the path so far.
        */
        queue<pair<int, pair<int, int>>> q;


        // Start BFS from the top-left cell.
        q.push({
            distance[0][0],
            {0, 0}
        });


        // --------------------------------------------------
        // BFS
        // --------------------------------------------------

        while (!q.empty()) {

            // Get current distance.
            int d = q.front().first;

            // Get current position.
            int row = q.front().second.first;
            int col = q.front().second.second;

            q.pop();


            // --------------------------------------------------
            // UP
            // --------------------------------------------------

            if (row > 0 &&
                grid[row - 1][col] == 0 &&
                distance[row][col] + 1 <
                    distance[row - 1][col]) {

                distance[row - 1][col] =
                    distance[row][col] + 1;

                q.push({
                    distance[row - 1][col],
                    {row - 1, col}
                });
            }


            // --------------------------------------------------
            // DOWN
            // --------------------------------------------------

            if (row < m - 1 &&
                grid[row + 1][col] == 0 &&
                distance[row][col] + 1 <
                    distance[row + 1][col]) {

                distance[row + 1][col] =
                    distance[row][col] + 1;

                q.push({
                    distance[row + 1][col],
                    {row + 1, col}
                });
            }


            // --------------------------------------------------
            // LEFT
            // --------------------------------------------------

            if (col > 0 &&
                grid[row][col - 1] == 0 &&
                distance[row][col] + 1 <
                    distance[row][col - 1]) {

                distance[row][col - 1] =
                    distance[row][col] + 1;

                q.push({
                    distance[row][col - 1],
                    {row, col - 1}
                });
            }


            // --------------------------------------------------
            // RIGHT
            // --------------------------------------------------

            if (col < n - 1 &&
                grid[row][col + 1] == 0 &&
                distance[row][col] + 1 <
                    distance[row][col + 1]) {

                distance[row][col + 1] =
                    distance[row][col] + 1;

                q.push({
                    distance[row][col + 1],
                    {row, col + 1}
                });
            }


            // --------------------------------------------------
            // UP-LEFT
            // --------------------------------------------------

            if (row > 0 &&
                col > 0 &&
                grid[row - 1][col - 1] == 0 &&
                distance[row][col] + 1 <
                    distance[row - 1][col - 1]) {

                distance[row - 1][col - 1] =
                    distance[row][col] + 1;

                q.push({
                    distance[row - 1][col - 1],
                    {row - 1, col - 1}
                });
            }


            // --------------------------------------------------
            // UP-RIGHT
            // --------------------------------------------------

            if (row > 0 &&
                col < n - 1 &&
                grid[row - 1][col + 1] == 0 &&
                distance[row][col] + 1 <
                    distance[row - 1][col + 1]) {

                distance[row - 1][col + 1] =
                    distance[row][col] + 1;

                q.push({
                    distance[row - 1][col + 1],
                    {row - 1, col + 1}
                });
            }


            // --------------------------------------------------
            // DOWN-LEFT
            // --------------------------------------------------

            if (row < m - 1 &&
                col > 0 &&
                grid[row + 1][col - 1] == 0 &&
                distance[row][col] + 1 <
                    distance[row + 1][col - 1]) {

                distance[row + 1][col - 1] =
                    distance[row][col] + 1;

                q.push({
                    distance[row + 1][col - 1],
                    {row + 1, col - 1}
                });
            }


            // --------------------------------------------------
            // DOWN-RIGHT
            // --------------------------------------------------

            if (row < m - 1 &&
                col < n - 1 &&
                grid[row + 1][col + 1] == 0 &&
                distance[row][col] + 1 <
                    distance[row + 1][col + 1]) {

                distance[row + 1][col + 1] =
                    distance[row][col] + 1;

                q.push({
                    distance[row + 1][col + 1],
                    {row + 1, col + 1}
                });
            }
        }


        // --------------------------------------------------
        // If destination was never reached,
        // no valid path exists.
        // --------------------------------------------------

        if (distance[m - 1][n - 1] == INT_MAX) {

            return -1;
        }


        // Return shortest path length.
        return distance[m - 1][n - 1];
    }
};


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
        Input:

        0 0 0
        1 1 0
        1 1 0

        One shortest path is:

        (0,0)
           ↘
            (1,1)
               ↘
                (2,2)

        But (1,1) is blocked.

        Instead:

        (0,0)
          →
        (0,1)
          →
        (0,2)
          ↓
        (1,2)
          ↓
        (2,2)

        Path length = 5
    */

    vector<vector<int>> grid = {

        {0, 0, 0},

        {1, 1, 0},

        {1, 1, 0}
    };


    Solution obj;


    // Find shortest path length.
    int result =
        obj.shortestPathBinaryMatrix(grid);


    // Print result.
    cout << "Shortest Path Length: "
         << result
         << endl;


    return 0;
}