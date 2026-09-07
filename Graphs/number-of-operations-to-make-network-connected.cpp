/*
Problem: Number of Operations to Make Network Connected

LeetCode:
https://leetcode.com/problems/number-of-operations-to-make-network-connected/

Goal:
Connect all N computers using the minimum number of
network cable operations.

A connection between two computers can be rearranged.
If there are enough cables, the answer is:

    number of connected components - 1

Approach:
DFS + Connected Components

First, check whether there are at least N - 1 connections.

Why?

To connect N computers, at least N - 1 cables are required.

Then:

1. Build an undirected adjacency list.
2. Maintain a visited array.
3. Run DFS from every unvisited computer.
4. Each DFS traversal represents one connected component.
5. To connect C components, we need C - 1 operations.

Key Insight:

If the network has:

    C connected components

then we need:

    C - 1

connections to join all of them.

The initial check:

    if(connections.size() < n - 1)

immediately tells us that there are not enough cables
to connect the entire network.

Time Complexity: O(N + E)

Space Complexity: O(N + E)

where:
N = number of computers
E = number of connections
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Traverse one complete connected component
    void dfs(int current, vector<vector<int>>& adj,
             vector<int>& visited) {

        visited[current] = 1;

        // Visit all connected computers
        for(auto neighbour : adj[current]) {

            if(!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        // At least N - 1 cables are required
        if(connections.size() < n - 1) {
            return -1;
        }

        // Build adjacency list
        vector<vector<int>> adj(n);

        vector<int> visited(n, 0);

        for(auto connection : connections) {

            int u = connection[0];
            int v = connection[1];

            // Network connections are undirected
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int components = 0;

        // Find all connected components
        for(int i = 0; i < n; i++) {

            if(!visited[i]) {

                components++;

                // Explore the complete component
                dfs(i, adj, visited);
            }
        }

        // C components require C - 1 operations
        return components - 1;
    }
};

int main() {

    int n = 4;

    vector<vector<int>> connections = {
        {0, 1},
        {0, 2},
        {1, 2}
    };

    Solution obj;

    cout << "Minimum operations: "
         << obj.makeConnected(n, connections)
         << endl;

    return 0;
}