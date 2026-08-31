/*
Problem: Find Eventual Safe States

LeetCode:
https://leetcode.com/problems/find-eventual-safe-states/

Goal:
Return all eventual safe nodes in a directed graph
in increasing order.

Definitions:

Terminal Node:
A node having no outgoing edges.

Safe Node:
A node from which every possible path eventually
reaches a terminal node.

Unsafe Node:
A node that is part of a cycle or can eventually
reach a cycle.


Approach:
DFS + Cycle Detection

We maintain two arrays:

    visited[node]

        0 -> Node has not been visited
        1 -> Node has already been explored


    path[node]

        0 -> Node is not in the current DFS path
        1 -> Node is currently in the DFS path


During DFS:

1. Mark the current node as visited.

2. Mark it as part of the current DFS path.

3. Explore all outgoing neighbors.

4. If an unvisited neighbor leads to a cycle:
       return true

5. If an already visited neighbor is still
   present in the current DFS path:
       cycle exists
       return true

6. If no cycle is found:
       remove current node from current DFS path
       add current node to answer
       return false


Important:

A node is added to the answer only when DFS
completes without finding a cycle from that node.

Finally, sort the answer because the problem
requires nodes in increasing order.

PseudoCode : 

create visited array

create path array

create answer array


DFS(current):

    mark current as visited

    mark current as part of current DFS path


    for every neighbor of current:

        if neighbor is not visited:

            if DFS(neighbor) finds cycle:

                return true


        else if neighbor is in current DFS path:

            return true


    remove current from current DFS path

    add current to answer

    return false


for every node:

    if node is not visited:

        DFS(node)


sort answer

return answer


Complexity Analysis : 

Time Complexity: O(V + E + V log V)

    DFS: O(V + E)
    Sorting: O(V log V)

Space Complexity: O(V)

For visited array, path array, answer array,
and recursive DFS stack.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// --------------------------------------------------
// Solution Class
// --------------------------------------------------

class Solution {

public:

    // --------------------------------------------------
    // DFS
    //
    // Returns:
    //
    // true  -> cycle is found from this DFS path
    // false -> no cycle is found from this DFS path
    // --------------------------------------------------

    bool dfs(
        int current,
        vector<vector<int>>& graph,
        vector<int>& visited,
        vector<int>& path,
        vector<int>& ans
    ) {

        // Mark current node as visited.
        visited[current] = 1;


        // Mark current node as part of
        // the active DFS path.
        path[current] = 1;


        // --------------------------------------------------
        // Explore every outgoing neighbor.
        // --------------------------------------------------

        for (int neighbour : graph[current]) {

            // --------------------------------------------------
            // Case 1:
            // Neighbor has not been visited.
            // --------------------------------------------------

            if (!visited[neighbour]) {

                // If recursive DFS finds a cycle,
                // current node is also unsafe.
                if (dfs(
                        neighbour,
                        graph,
                        visited,
                        path,
                        ans
                    )) {

                    return true;
                }
            }


            // --------------------------------------------------
            // Case 2:
            // Neighbor was already visited AND is still
            // in the current DFS recursion path.
            //
            // This means we found a back edge.
            //
            // Therefore, a cycle exists.
            // --------------------------------------------------

            else if (path[neighbour]) {

                return true;
            }
        }


        // --------------------------------------------------
        // No cycle was found through this node.
        //
        // Remove the node from the current DFS path.
        // --------------------------------------------------

        path[current] = 0;


        // Since every path from this node avoids a cycle,
        // this node is eventually safe.
        ans.push_back(current);


        return false;
    }


    // --------------------------------------------------
    // Find all eventual safe nodes.
    // --------------------------------------------------

    vector<int> eventualSafeNodes(
        vector<vector<int>>& graph
    ) {

        int n = graph.size();


        // visited[i] tells whether node i
        // has already been explored.
        vector<int> visited(
            n,
            0
        );


        // path[i] tells whether node i is currently
        // part of the active DFS recursion path.
        vector<int> path(
            n,
            0
        );


        // Stores all eventual safe nodes.
        vector<int> ans;


        // --------------------------------------------------
        // Graph may be disconnected.
        //
        // Therefore, start DFS from every
        // unvisited node.
        // --------------------------------------------------

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                dfs(
                    i,
                    graph,
                    visited,
                    path,
                    ans
                );
            }
        }


        // Problem requires safe nodes
        // in increasing order.
        sort(
            ans.begin(),
            ans.end()
        );


        return ans;
    }
};


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
        Example:

        graph =

        0 -> 1, 2
        1 -> 2, 3
        2 -> 5
        3 -> 0
        4 -> 5
        5 -> {}
        6 -> {}


        Graph conceptually:

        0 ----> 1
        |       |
        |       ↓
        |       3
        |       |
        └------>2
                |
                ↓
                5


        There is a cycle:

            0 -> 1 -> 3 -> 0

        Therefore:

            0, 1, 3

        are unsafe.


        Node 2:

            2 -> 5

        reaches terminal node 5.


        Node 4:

            4 -> 5

        reaches terminal node 5.


        Node 5:

        has no outgoing edges,
        so it is terminal.


        Node 6:

        has no outgoing edges,
        so it is terminal.


        Safe Nodes:

            2, 4, 5, 6
    */


    vector<vector<int>> graph = {

        {1, 2},     // Node 0

        {2, 3},     // Node 1

        {5},        // Node 2

        {0},        // Node 3

        {5},        // Node 4

        {},         // Node 5

        {}          // Node 6
    };


    Solution obj;


    // Find eventual safe nodes.
    vector<int> result =
        obj.eventualSafeNodes(graph);


    // --------------------------------------------------
    // Print result.
    // --------------------------------------------------

    cout << "Eventual Safe Nodes: ";


    for (int node : result) {

        cout << node << " ";
    }


    cout << endl;


    return 0;
}