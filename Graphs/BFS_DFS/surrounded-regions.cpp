/*
Problem: Surrounded Regions

LeetCode:
https://leetcode.com/problems/surrounded-regions/

Goal:
Capture all regions of 'O' that are completely
surrounded by 'X'.

Rules:

    'O' connected to the boundary:
        Cannot be captured.

    'O' completely surrounded by 'X':
        Convert it to 'X'.


Approach:
Boundary DFS

Instead of finding surrounded regions directly,
we find the opposite:

    O's that CANNOT be surrounded.

These are the O's connected to the boundary.

Steps:

1. Start DFS from every boundary O.

2. Mark every O connected to the boundary
   as visited.

3. Traverse the entire board.

4. Any O that is not visited is surrounded.

5. Convert those O's to X.


Why does this work?

If an O is connected to the boundary,
there is a path from that O to the outside.

Therefore, it cannot be surrounded.

Only unvisited O's are completely enclosed.


PseudoCode : 

create visited matrix


for every cell on LEFT and RIGHT boundary:

    if cell is O and not visited:

        DFS(cell)


for every cell on TOP and BOTTOM boundary:

    if cell is O and not visited:

        DFS(cell)


DFS(r, c):

    mark current cell as visited

    explore:
        UP
        DOWN
        LEFT
        RIGHT

    only continue through O cells


for every interior cell:

    if cell is O
       and not visited:

        change O to X


return board


Complexity Analysis : 

Time Complexity: O(m * n)
Space Complexity: O(m * n)

For the visited matrix and recursion stack.
*/

#include <iostream>
#include <vector>

using namespace std;


// --------------------------------------------------
// Surrounded Regions Solution
// --------------------------------------------------

class Solution {

public:

    // --------------------------------------------------
    // DFS
    //
    // Marks all boundary-connected O's as visited.
    // --------------------------------------------------

    void dfs(
        int r,
        int c,
        vector<vector<char>>& board,
        vector<vector<char>>& visited
    ) {

        int m = board.size();
        int n = board[0].size();


        // Mark current O as visited.
        visited[r][c] = 1;


        // --------------------------------------------------
        // Move UP
        // --------------------------------------------------

        if (r > 0 &&
            board[r - 1][c] == 'O' &&
            !visited[r - 1][c]) {

            dfs(
                r - 1,
                c,
                board,
                visited
            );
        }


        // --------------------------------------------------
        // Move DOWN
        // --------------------------------------------------

        if (r < m - 1 &&
            board[r + 1][c] == 'O' &&
            !visited[r + 1][c]) {

            dfs(
                r + 1,
                c,
                board,
                visited
            );
        }


        // --------------------------------------------------
        // Move LEFT
        // --------------------------------------------------

        if (c > 0 &&
            board[r][c - 1] == 'O' &&
            !visited[r][c - 1]) {

            dfs(
                r,
                c - 1,
                board,
                visited
            );
        }


        // --------------------------------------------------
        // Move RIGHT
        // --------------------------------------------------

        if (c < n - 1 &&
            board[r][c + 1] == 'O' &&
            !visited[r][c + 1]) {

            dfs(
                r,
                c + 1,
                board,
                visited
            );
        }
    }


    // --------------------------------------------------
    // Solve the board
    // --------------------------------------------------

    void solve(
        vector<vector<char>>& board
    ) {

        int m = board.size();
        int n = board[0].size();


        // visited[i][j] = 1 means the O is connected
        // to the boundary and therefore cannot be captured.
        vector<vector<char>> visited(
            m,
            vector<char>(n, 0)
        );


        // --------------------------------------------------
        // Process first and last columns.
        // --------------------------------------------------

        for (int i = 0; i < m; i++) {

            // Left boundary.
            if (board[i][0] == 'O' &&
                !visited[i][0]) {

                dfs(
                    i,
                    0,
                    board,
                    visited
                );
            }


            // Right boundary.
            if (board[i][n - 1] == 'O' &&
                !visited[i][n - 1]) {

                dfs(
                    i,
                    n - 1,
                    board,
                    visited
                );
            }
        }


        // --------------------------------------------------
        // Process first and last rows.
        // --------------------------------------------------

        for (int j = 0; j < n; j++) {

            // Top boundary.
            if (board[0][j] == 'O' &&
                !visited[0][j]) {

                dfs(
                    0,
                    j,
                    board,
                    visited
                );
            }


            // Bottom boundary.
            if (board[m - 1][j] == 'O' &&
                !visited[m - 1][j]) {

                dfs(
                    m - 1,
                    j,
                    board,
                    visited
                );
            }
        }


        // --------------------------------------------------
        // Convert surrounded O's to X.
        //
        // We only need to check interior cells because
        // boundary O's can never be surrounded.
        // --------------------------------------------------

        for (int i = 1; i < m - 1; i++) {

            for (int j = 1; j < n - 1; j++) {

                // This O is not connected to the boundary.
                if (board[i][j] == 'O' &&
                    !visited[i][j]) {

                    board[i][j] = 'X';

                    visited[i][j] = 1;
                }
            }
        }
    }
};


// --------------------------------------------------
// Helper function to print the board
// --------------------------------------------------

void printBoard(
    vector<vector<char>>& board
) {

    for (int i = 0; i < board.size(); i++) {

        for (int j = 0; j < board[0].size(); j++) {

            cout << board[i][j] << " ";
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

        X X X X
        X O O X
        X X O X
        X O X X

        The O at the bottom is connected
        to the boundary, so it must remain O.

        The other O's are surrounded,
        so they become X.

        Output:

        X X X X
        X X X X
        X X X X
        X O X X
    */


    vector<vector<char>> board = {

        {'X', 'X', 'X', 'X'},

        {'X', 'O', 'O', 'X'},

        {'X', 'X', 'O', 'X'},

        {'X', 'O', 'X', 'X'}
    };


    Solution obj;


    // Capture surrounded regions.
    obj.solve(board);


    // Print the resulting board.
    cout << "Board after capturing surrounded regions:"
         << endl;

    printBoard(board);


    return 0;
}