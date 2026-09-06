/*
Problem: Bellman-Ford Algorithm

Source : 
https://takeuforward.org/plus/dsa/problems/bellman-ford-algorithm?source=strivers-a2z-dsa-track

Goal:
Find the shortest distance from the given source vertex
to every other vertex in a weighted directed graph.

If a negative weight cycle is reachable from the source,
return {-1}.

Approach:
Bellman-Ford repeatedly relaxes every edge.

For every edge:

    a ----w----> b

If:

    distance[a] + w < distance[b]

then we found a shorter path to b, so update:

    distance[b] = distance[a] + w

Algorithm:

1. Initialize all distances to INF.
2. Set distance[start] = 0.
3. Relax every edge N - 1 times.
4. Perform one additional pass over all edges.
5. If any distance can still be reduced, a reachable
   negative weight cycle exists.
6. Otherwise, return the shortest distances.

Why N - 1 iterations?

A shortest simple path can contain at most N - 1 edges
when there are N vertices.

After N - 1 complete relaxation rounds, all shortest
paths without cycles have been considered.

Key Insight:

Bellman-Ford works by gradually propagating shorter
distances through the graph.

The extra Nth pass is used only for detection:

    If an edge can still be relaxed,
    a negative cycle is reachable from the source.


PseudoCode : 

Set distance of every vertex to INF
Set distance of source to 0

Repeat N - 1 times:

    for every edge (a, b, weight):

        if a is reachable
        and distance[a] + weight < distance[b]:

            update distance[b]

Perform one more pass over all edges:

    if any edge can still be relaxed:

        return -1

Return all shortest distances


Complexity Analysis : 

Time Complexity: O(N * E)
Space Complexity: O(N)

where:
N = number of vertices
E = number of edges

LeetCode / Reference:
Bellman-Ford is a standard shortest-path algorithm and
is commonly used for graphs containing negative weights.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int n, int start, vector<vector<int>>& edges) {

        // Use a large value to represent infinity
        int inf = 1e7;

        // Initialize all distances as infinity
        vector<int> distance(n, inf);

        // Distance from source to itself is 0
        distance[start] = 0;

        // Relax every edge N - 1 times
        for(int i = 1; i <= n - 1; i++){

            // Traverse all edges
            for(auto edge : edges){

                int a = edge[0];
                int b = edge[1];
                int w = edge[2];

                // Relax the edge if a shorter path is found
                if(distance[a] != inf &&
                   distance[a] + w < distance[b]){

                    distance[b] = distance[a] + w;
                }
            }
        }

        // Check for a reachable negative weight cycle
        for(auto edge : edges){

            int a = edge[0];
            int b = edge[1];
            int w = edge[2];

            // If relaxation is still possible,
            // a negative cycle exists
            if(distance[a] != inf &&
               distance[a] + w < distance[b]){

                return {-1};
            }
        }

        // Return shortest distances
        return distance;
    }
};

int main() {

    int n = 5;
    int start = 0;

    vector<vector<int>> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 0, 2},
        {4, 3, 7}
    };

    Solution obj;

    vector<int> result = obj.bellmanFord(n, start, edges);

    // Print the result
    if(result.size() == 1 && result[0] == -1) {
        cout << "Negative weight cycle detected." << endl;
    }
    else {
        cout << "Shortest distances from source " << start << ": ";

        for(int distance : result) {
            cout << distance << " ";
        }

        cout << endl;
    }

    return 0;
}