/*
Problem: Is Graph Bipartite?

LeetCode:
https://leetcode.com/problems/is-graph-bipartite/

Goal:
Determine whether a given graph is bipartite.

A graph is bipartite if we can divide all its
vertices into two groups such that no two vertices
in the same group are directly connected.

Approach:
DFS + Two-Coloring

We maintain a color array:

    -1 -> Node has not been colored
     0 -> Node belongs to color 0
     1 -> Node belongs to color 1

For every uncolored node:

    Start DFS with color 0.

During DFS:

    Color the current node.

    For every neighbor:

        If neighbor is uncolored:
            Give it the opposite color.

        If neighbor already has the same color:
            Graph is not bipartite.

Why use:
    1 - currentColor

Because:

    1 - 0 = 1
    1 - 1 = 0

Therefore, every adjacent node gets
the opposite color.

Important:
The graph may be disconnected.

Therefore, we start DFS from every node
that is still uncolored.

Time Complexity:
O(V + E)

Space Complexity:
O(V)

V = number of vertices
E = number of edges
*/

#include <iostream>
#include <vector>

using namespace std;


// --------------------------------------------------
// Check whether a graph is bipartite using DFS
// --------------------------------------------------

class Solution {

public:

    // --------------------------------------------------
    // DFS function
    //
    // currentColor represents the color assigned
    // to the current node.
    // --------------------------------------------------

    bool dfs(
        int current,
        int currentColor,
        vector<vector<int>>& graph,
        vector<int>& color
    ) {

        // Assign the current node its color.
        color[current] = currentColor;


        // Visit every neighbor of the current node.
        for (int k : graph[current]) {

            // --------------------------------------------------
            // Neighbor has not been colored yet.
            // --------------------------------------------------

            if (color[k] == -1) {

                // Assign the opposite color to the neighbor.
                //
                // If currentColor = 0:
                //     1 - 0 = 1
                //
                // If currentColor = 1:
                //     1 - 1 = 0
                //
                // If the recursive DFS finds a conflict,
                // the graph is not bipartite.
                if (!dfs(
                        k,
                        1 - currentColor,
                        graph,
                        color
                    )) {

                    return false;
                }
            }


            // --------------------------------------------------
            // Neighbor is already colored.
            //
            // If both current node and neighbor have
            // the same color, the graph is not bipartite.
            // --------------------------------------------------

            else if (color[k] == color[current]) {

                return false;
            }
        }


        // No conflict was found in this DFS component.
        return true;
    }


    // --------------------------------------------------
    // Check whether the complete graph is bipartite.
    // --------------------------------------------------

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();


        // Initially, no node has a color.
        //
        // -1 means uncolored.
        vector<int> color(n, -1);


        // The graph may contain multiple disconnected
        // components, so check every node.
        for (int i = 0; i < n; i++) {

            // Start DFS only if the node is uncolored.
            if (color[i] == -1) {

                // Start this connected component
                // with color 0.
                if (!dfs(
                        i,
                        0,
                        graph,
                        color
                    )) {

                    return false;
                }
            }
        }


        // No coloring conflict was found.
        return true;
    }
};


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
        Example Graph:

            0 ----- 1
            |       |
            |       |
            3 ----- 2

        Edges:

            0 -- 1
            1 -- 2
            2 -- 3
            3 -- 0

        This graph can be colored as:

            Color 0: 0, 2
            Color 1: 1, 3

        Therefore, it is bipartite.
    */

    vector<vector<int>> graph = {

        {1, 3},    // Node 0

        {0, 2},    // Node 1

        {1, 3},    // Node 2

        {0, 2}     // Node 3
    };


    // Create Solution object.
    Solution obj;


    // Check whether the graph is bipartite.
    bool result = obj.isBipartite(graph);


    // Print the result.
    if (result) {

        cout << "Graph is Bipartite" << endl;
    }

    else {

        cout << "Graph is Not Bipartite" << endl;
    }


    return 0;
}