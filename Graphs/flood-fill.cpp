/*
Problem: Flood Fill

LeetCode:
https://leetcode.com/problems/flood-fill/

Goal:
Given an image represented as a 2D matrix,
change the color of the starting pixel and all
connected pixels having the same original color.

A pixel is connected through:

    Up
    Down
    Left
    Right

Diagonal pixels are not considered connected.

Approach:
DFS

Steps:

1. Store the original color of the starting pixel.

2. If the original color is already equal to
   the new color, return the image immediately.

3. Start DFS from (sr, sc).

4. Change the current pixel to the new color.

5. Recursively visit its four neighboring pixels
   if they have the original color.

6. Return the modified image.

Important:
We do not need a separate visited matrix.

Once a pixel is changed to the new color,
it is no longer equal to originalColor.

Therefore, it cannot be visited again.

PsuedoCode : 

originalColor = image[sr][sc]

if originalColor == new color:

    return image


DFS(sr, sc)


DFS(i, j):

    change image[i][j] to new color


    if upper cell is inside grid
       and has original color:

        DFS(upper cell)


    if lower cell is inside grid
       and has original color:

        DFS(lower cell)


    if left cell is inside grid
       and has original color:

        DFS(left cell)


    if right cell is inside grid
       and has original color:

        DFS(right cell)


return image


Complexity Analysis : 

Time Complexity: O(rows * cols)

In the worst case, every pixel belongs to
the connected component.

Space Complexity: O(rows * cols)

Due to the recursive DFS call stack in the
worst case.
*/

#include <iostream>
#include <vector>

using namespace std;


// --------------------------------------------------
// Flood Fill Solution
// --------------------------------------------------

class Solution {

public:

    // --------------------------------------------------
    // DFS function
    //
    // Changes all connected pixels having
    // the original color.
    // --------------------------------------------------

    void dfs(
        int i,
        int j,
        vector<vector<int>>& image,
        int originalColor,
        int color
    ) {

        int rows = image.size();
        int cols = image[0].size();


        // Change the current pixel to the new color.
        //
        // This also acts as our "visited" marker.
        image[i][j] = color;


        // --------------------------------------------------
        // Move UP
        // --------------------------------------------------

        if (i > 0 &&
            image[i - 1][j] == originalColor) {

            dfs(
                i - 1,
                j,
                image,
                originalColor,
                color
            );
        }


        // --------------------------------------------------
        // Move DOWN
        // --------------------------------------------------

        if (i + 1 < rows &&
            image[i + 1][j] == originalColor) {

            dfs(
                i + 1,
                j,
                image,
                originalColor,
                color
            );
        }


        // --------------------------------------------------
        // Move LEFT
        // --------------------------------------------------

        if (j > 0 &&
            image[i][j - 1] == originalColor) {

            dfs(
                i,
                j - 1,
                image,
                originalColor,
                color
            );
        }


        // --------------------------------------------------
        // Move RIGHT
        // --------------------------------------------------

        if (j + 1 < cols &&
            image[i][j + 1] == originalColor) {

            dfs(
                i,
                j + 1,
                image,
                originalColor,
                color
            );
        }
    }


    // --------------------------------------------------
    // Flood Fill
    // --------------------------------------------------

    vector<vector<int>> floodFill(
        vector<vector<int>>& image,
        int sr,
        int sc,
        int color
    ) {

        // Store the original color of the starting pixel.
        int originalColor = image[sr][sc];


        // If the new color is already the same as
        // the original color, no work is required.
        //
        // This also prevents unnecessary recursion.
        if (originalColor == color) {

            return image;
        }


        // Start DFS from the source pixel.
        dfs(
            sr,
            sc,
            image,
            originalColor,
            color
        );


        return image;
    }
};


// --------------------------------------------------
// Helper function to print the image
// --------------------------------------------------

void printImage(vector<vector<int>>& image) {

    for (int i = 0; i < image.size(); i++) {

        for (int j = 0; j < image[0].size(); j++) {

            cout << image[i][j] << " ";
        }

        cout << endl;
    }
}


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
        Original image:

        1 1 1
        1 1 0
        1 0 1

        Starting pixel:
        sr = 1
        sc = 1

        Original color = 1
        New color = 2

        All connected 1's connected to (1,1)
        will become 2.
    */

    vector<vector<int>> image = {

        {1, 1, 1},

        {1, 1, 0},

        {1, 0, 1}
    };


    int sr = 1;
    int sc = 1;
    int color = 2;


    Solution obj;


    cout << "Image before flood fill:" << endl;

    printImage(image);


    // Perform flood fill.
    image = obj.floodFill(
        image,
        sr,
        sc,
        color
    );


    cout << endl;

    cout << "Image after flood fill:" << endl;

    printImage(image);


    return 0;
}