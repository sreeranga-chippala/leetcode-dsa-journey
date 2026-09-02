/*
Problem: Network Delay Time

Source : 
https://leetcode.com/problems/network-delay-time/

Goal:
There are n nodes and directed edges.
times[i] = {u, v, w} means:

    u → v with travel time w

A signal starts from node k.

Find the minimum time required for the signal
to reach every node.

If some node cannot be reached, return -1.


Approach:
Dijkstra's Algorithm

Why Dijkstra?

The graph is:

    Directed
    Weighted
    Edge weights are non-negative

We need the shortest distance from one source
node k to every other node.

Steps:

1. Build a weighted adjacency list.

2. Set distance[k] = 0.

3. Put {0, k} into a min-heap.

4. Always process the node with the smallest
   known distance.

5. Relax every outgoing edge:

       newDistance =
           distance[node] + edgeWeight

   If newDistance is smaller:

       update distance
       push the new pair into the heap

6. After Dijkstra finishes:

       If any node has INT_MAX:
           return -1

       Otherwise:
           answer = maximum shortest distance


Important:
The final answer is the maximum shortest distance
because the signal must reach EVERY node.


Time Complexity: O((V + E) log V)
Space Complexity: O(V + E)
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

    int networkDelayTime(
        vector<vector<int>>& times,
        int n,
        int k
    ) {

        /*
            Min-heap:

            {distance, node}

            The node with the smallest distance
            is always processed first.
        */
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;


        /*
            Weighted adjacency list.

            adj[u] contains:

                {v, weight}

            meaning:

                u → v
                with weight = weight
        */
        vector<vector<pair<int, int>>> adj(
            n + 1
        );


        // --------------------------------------------------
        // Build the weighted directed graph.
        // --------------------------------------------------

        for (auto edge : times) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({
                v,
                wt
            });
        }


        // --------------------------------------------------
        // Initially, every node is unreachable.
        // --------------------------------------------------

        vector<int> distance(
            n + 1,
            INT_MAX
        );


        // Source node has distance 0.
        distance[k] = 0;


        // Start Dijkstra from source k.
        pq.push({
            distance[k],
            k
        });


        // --------------------------------------------------
        // Dijkstra's Algorithm
        // --------------------------------------------------

        while (!pq.empty()) {

            // Get the node with minimum distance.
            int node = pq.top().second;

            int dist = pq.top().first;

            pq.pop();


            /*
                A node can appear multiple times in the
                priority queue.

                Example:

                    node 3 initially gets distance 10
                    later gets distance 5

                The old {10, 3} entry may still exist.

                Ignore it because it is no longer
                the shortest known distance.
            */
            if (dist > distance[node]) {

                continue;
            }


            // --------------------------------------------------
            // Relax all outgoing edges.
            // --------------------------------------------------

            for (auto edge : adj[node]) {

                int neighbour = edge.first;

                int weight = edge.second;


                /*
                    Check whether going through 'node'
                    gives a shorter path to neighbour.
                */
                if (distance[node] + weight <
                    distance[neighbour]) {

                    // Update shortest distance.
                    distance[neighbour] =
                        distance[node] + weight;


                    // Add updated distance to min-heap.
                    pq.push({
                        distance[neighbour],
                        neighbour
                    });
                }
            }
        }


        // --------------------------------------------------
        // Find the maximum shortest distance.
        //
        // The signal must reach every node, so the
        // slowest node determines the total delay.
        // --------------------------------------------------

        int ans = 0;


        for (int i = 1; i <= n; i++) {

            // Node cannot be reached.
            if (distance[i] == INT_MAX) {

                return -1;
            }


            ans = max(
                ans,
                distance[i]
            );
        }


        return ans;
    }
};


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
        Input:

        n = 4
        k = 2

        Edges:

        2 → 1 with weight 1
        2 → 3 with weight 1
        3 → 4 with weight 1

        Graph:

              1
              ↑
              |
              2 → 3 → 4
                  1    1

        Shortest distances from 2:

        Node 2 → 0
        Node 1 → 1
        Node 3 → 1
        Node 4 → 2

        Maximum distance = 2

        Therefore:

        Network Delay Time = 2
    */

    vector<vector<int>> times = {

        {2, 1, 1},

        {2, 3, 1},

        {3, 4, 1}
    };


    int n = 4;

    int k = 2;


    Solution obj;


    // Calculate network delay time.
    int result =
        obj.networkDelayTime(
            times,
            n,
            k
        );


    // Print result.
    cout << "Network Delay Time: "
         << result
         << endl;


    return 0;
}