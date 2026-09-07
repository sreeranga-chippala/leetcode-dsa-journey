/*
Problem: 01 Matrix

LeetCode:
https://leetcode.com/problems/01-matrix/

Goal:
For every cell containing 1, find the distance to
the nearest cell containing 0.

Distance is measured using four directions:

    Up
    Down
    Left
    Right


Approach:
Multi-Source BFS

Instead of starting BFS separately from every 1,
we start BFS from ALL 0s simultaneously.

Why?

Every 0 has distance 0.

Then:

    Neighbors of 0 → distance 1
    Neighbors of those cells → distance 2
    Neighbors of those cells → distance 3
    ...

Because BFS explores level by level, the first
distance assigned to a cell is its shortest distance
to any 0.

We use a visited matrix so every cell is processed once.

Queue stores:

    { {row, column}, distance }


PseudoCode : 

create visited matrix
create queue


for every cell:

    if cell == 0:

        mark visited

        push cell with distance 0


while queue is not empty:

    remove front cell

    get row, column and distance

    set matrix[row][column] = distance


    for each of four directions:

        if neighbor is inside grid
           and neighbor is not visited
           and neighbor contains 1:

            mark neighbor visited

            push neighbor
            with distance + 1


return matrix


Complexity Analysis : 

Time Complexity: O(m * n)
Every cell is processed at most once.

Space Complexity: O(m * n)
For visited matrix and queue.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {

public:

    // --------------------------------------------------
    // Find distance from every cell to nearest 0
    // --------------------------------------------------

    vector<vector<int>> updateMatrix(
        vector<vector<int>>& mat
    ) {

        int m = mat.size();
        int n = mat[0].size();


        // visited[i][j] = 1 means this cell
        // has already been added to the BFS queue.
        vector<vector<int>> visited(
            m,
            vector<int>(n, 0)
        );


        /*
            Queue stores:

                {{row, column}, distance}

            Distance represents the shortest distance
            from the current cell to a zero.
        */
        queue<pair<pair<int, int>, int>> q;


        // --------------------------------------------------
        // Add ALL zero cells to the queue.
        //
        // Every zero starts with distance 0.
        // --------------------------------------------------

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (!visited[i][j] &&
                    mat[i][j] == 0) {

                    q.push({
                        {i, j},
                        0
                    });

                    visited[i][j] = 1;
                }
            }
        }


        // --------------------------------------------------
        // Multi-Source BFS
        // --------------------------------------------------

        while (!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;

            q.pop();


            // Store the shortest distance for this cell.
            mat[r][c] = d;


            // --------------------------------------------------
            // Move UP
            // --------------------------------------------------

            if (r > 0 &&
                !visited[r - 1][c] &&
                mat[r - 1][c] == 1) {

                q.push({
                    {r - 1, c},
                    d + 1
                });

                visited[r - 1][c] = 1;
            }


            // --------------------------------------------------
            // Move DOWN
            // --------------------------------------------------

            if (r < m - 1 &&
                !visited[r + 1][c] &&
                mat[r + 1][c] == 1) {

                q.push({
                    {r + 1, c},
                    d + 1
                });

                visited[r + 1][c] = 1;
            }


            // --------------------------------------------------
            // Move LEFT
            // --------------------------------------------------

            if (c > 0 &&
                !visited[r][c - 1] &&
                mat[r][c - 1] == 1) {

                q.push({
                    {r, c - 1},
                    d + 1
                });

                visited[r][c - 1] = 1;
            }


            // --------------------------------------------------
            // Move RIGHT
            // --------------------------------------------------

            if (c < n - 1 &&
                !visited[r][c + 1] &&
                mat[r][c + 1] == 1) {

                q.push({
                    {r, c + 1},
                    d + 1
                });

                visited[r][c + 1] = 1;
            }
        }


        return mat;
    }
};


// --------------------------------------------------
// Helper function to print a matrix
// --------------------------------------------------

void printMatrix(
    vector<vector<int>>& matrix
) {

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[0].size(); j++) {

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
        Input:

        0 0 0
        0 1 0
        1 1 1

        Output:

        0 0 0
        0 1 0
        1 2 1
    */

    vector<vector<int>> mat = {

        {0, 0, 0},

        {0, 1, 0},

        {1, 1, 1}
    };


    Solution obj;


    // Calculate distances.
    vector<vector<int>> result =
        obj.updateMatrix(mat);


    // Print result.
    cout << "Updated Matrix:" << endl;

    printMatrix(result);


    return 0;
}