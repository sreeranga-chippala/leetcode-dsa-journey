/*
Problem: Minimum Spanning Tree

source : 
https://takeuforward.org/plus/dsa/problems/find-the-mst-weight?source=strivers-a2z-dsa-track

Goal:
Find the minimum possible total weight required to
connect all vertices of a weighted undirected graph
without creating cycles.

Approach:
Prim's Algorithm + Min Heap

Start from vertex 0.

1. Push the starting vertex into a min heap with
   edge weight 0.

2. Always select the minimum-weight edge that leads
   to an unvisited vertex.

3. Mark that vertex as visited.

4. Add the selected edge weight to the MST total.

5. Push its unvisited neighboring vertices into
   the priority queue.

6. Continue until the priority queue becomes empty.

Key Insight:

Prim's algorithm grows the MST one vertex at a time.

At every step:

    Choose the cheapest edge
    connecting the current MST
    to an unvisited vertex.

The visited array prevents adding a vertex more than once,
which also prevents cycles in the resulting spanning tree.

PseudoCode : 

Mark every vertex as unvisited

Create a min heap of:
    edge weight, vertex, parent

Start from vertex 0 with weight 0

While heap is not empty:

    Select the minimum-weight edge

    If the vertex is already visited:
        skip it

    Otherwise:

        mark the vertex as visited
        add edge weight to MST total

        for every unvisited neighbor:

            add its edge to the min heap

Return total MST weight


Complexity Analysis : 

Time Complexity: O(E log E)
Space Complexity: O(V + E)

where:
V = number of vertices
E = number of edges

The adjacency list requires O(V + E) space.
The priority queue can contain O(E) edge candidates.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:

    int spanningTree(int V, vector<vector<int>> adj[]) {

        int n = V;
        int ans = 0;

        // Track vertices already included in MST
        vector<int> visited(n, 0);

        // Min heap:
        // {weight, {current vertex, parent}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        // Start from vertex 0
        pq.push({0, {0, -1}});

        while(!pq.empty()) {

            int weight = pq.top().first;
            int current = pq.top().second.first;
            int parent = pq.top().second.second;

            pq.pop();

            // Only add an unvisited vertex to MST
            if(!visited[current]) {

                visited[current] = 1;

                // Add selected edge weight
                ans += weight;

                // Explore neighboring vertices
                for(auto k : adj[current]) {

                    int neighbour = k[0];
                    int d = k[1];

                    // Add candidate edge to min heap
                    if(!visited[neighbour]) {
                        pq.push({d, {neighbour, current}});
                    }
                }
            }
        }

        return ans;
    }
};

int main() {

    int V = 5;

    vector<vector<int>> adj[V];

    // {neighbor, weight}
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    adj[3].push_back({4, 9});
    adj[4].push_back({3, 9});

    Solution obj;

    cout << "Minimum Spanning Tree Weight: "
         << obj.spanningTree(V, adj)
         << endl;

    return 0;
}