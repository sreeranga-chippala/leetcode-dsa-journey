/*
Problem: DFS Traversal of a Graph

source : 
https://takeuforward.org/plus/dsa/problems/traversal-techniques?source=strivers-a2z-dsa-track

Goal:
Perform Depth First Search (DFS) traversal
of a graph starting from node 0.

Graph Representation:
Adjacency List

adj[i] contains all the nodes directly connected
to node i.

Approach:
Recursive DFS

Steps:

1. Start from node 0.

2. Mark the current node as visited.

3. Add the current node to the answer.

4. Visit every unvisited neighbor recursively.

5. Continue until all reachable nodes are visited.

PseudoCode : 

create visited array
create answer array


DFS(current):

    add current to answer

    mark current as visited

    for every neighbor of current:

        if neighbor is not visited:

            DFS(neighbor)


start DFS from node 0

return answer


Complexity Analysis : 

Time Complexity: O(V + E)

where:
V = number of vertices
E = number of edges

Space Complexity: O(V)

for the visited array and recursion stack.
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

    // --------------------------------------------------
    // Recursive DFS
    // --------------------------------------------------

    vector<int> dfs_rec(
        int current,
        vector<vector<int>>& adj,
        vector<int>& visited,
        vector<int>& ans
    ) {

        // Add current node to DFS traversal.
        ans.push_back(current);


        // Mark current node as visited.
        visited[current] = 1;


        // Visit every neighbor of current node.
        for (auto k : adj[current]) {

            // If the neighbor has not been visited,
            // recursively perform DFS from that node.
            if (!visited[k]) {

                dfs_rec(
                    k,
                    adj,
                    visited,
                    ans
                );
            }
        }


        return ans;
    }


    // --------------------------------------------------
    // DFS Traversal
    // --------------------------------------------------

    vector<int> dfs(
        int n,
        vector<vector<int>> adj
    ) {

        // Initially, no node has been visited.
        vector<int> visited(n, 0);


        // Stores the DFS traversal order.
        vector<int> ans;


        // Start DFS from node 0.
        dfs_rec(
            0,
            adj,
            visited,
            ans
        );


        return ans;
    }
};


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
        Graph:

            0
           / \
          1   2
          |   |
          3---4

        Adjacency List:

        0 -> 1, 2
        1 -> 0, 3
        2 -> 0, 4
        3 -> 1, 4
        4 -> 2, 3
    */

    int n = 5;


    vector<vector<int>> adj = {

        {1, 2},    // Node 0

        {0, 3},    // Node 1

        {0, 4},    // Node 2

        {1, 4},    // Node 3

        {2, 3}     // Node 4
    };


    Solution obj;


    // Perform DFS starting from node 0.
    vector<int> result = obj.dfs(n, adj);


    // Print DFS traversal.
    cout << "DFS Traversal: ";

    for (int node : result) {

        cout << node << " ";
    }

    cout << endl;


    return 0;
}