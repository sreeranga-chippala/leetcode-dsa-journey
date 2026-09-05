/*
Problem: Number of Ways to Arrive at Destination

LeetCode:
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

Goal:
Find the number of different ways to reach the
destination city using the shortest possible
travel time.

Approach:
Dijkstra + Path Counting

The roads form an undirected weighted graph.

For every road:

    [u, v, time]

there are two connections:

    u → v
    v → u

We maintain two arrays.

1. distance[i]

   Stores the shortest time required to reach
   city i.

2. paths[i]

   Stores the number of shortest paths that
   reach city i.

Initially:

    distance[0] = 0
    paths[0] = 1

There is exactly one way to be at the source:
we are already there.

For every neighboring city, calculate:

    newDistance = currentDistance + weight

There are two cases.

Case 1:
The new distance is smaller.

    newDistance < distance[neighbour]

Then we have found a new shortest path.

So:

    distance[neighbour] = newDistance
    paths[neighbour] = paths[current]

The number of ways to reach the neighbor becomes
the number of shortest ways to reach the current
city.

Case 2:
The new distance is equal.

    newDistance == distance[neighbour]

Then we have discovered another shortest path.

So:

    paths[neighbour] += paths[current]

The result is taken modulo:

    1,000,000,007

Key Insight:

Dijkstra finds the shortest distance.

Whenever a shorter path is found:

    replace the number of ways.

Whenever an equally short path is found:

    add the number of ways.

Therefore:

    Shorter path  → replace paths
    Equal path    → add paths

Time Complexity: O((N + E) * log N)

Space Complexity: O(N + E)

where:

N = number of cities
E = number of roads (edges)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>

using namespace std;

class Solution {
public:

    int countPaths(int n, vector<vector<int>>& roads) {

        // Build undirected adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for(auto road : roads) {

            int u = road[0];
            int v = road[1];
            int w = road[2];

            // Roads work in both directions
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Number of shortest paths to each city
        vector<long long> paths(n, 0);

        // One way to start at city 0
        paths[0] = 1;

        // Shortest distance to each city
        vector<long long> distance(n, LLONG_MAX);

        // Source distance is 0
        distance[0] = 0;

        // Min-heap:
        // {distance, city}
        priority_queue<
            pair<long long, long long>,
            vector<pair<long long, long long>>,
            greater<pair<long long, long long>>
        > pq;

        // Start Dijkstra from city 0
        pq.push({0, 0});

        // Process cities by minimum distance
        while(!pq.empty()) {

            // Get current shortest state
            long long d = pq.top().first;
            long long current = pq.top().second;

            pq.pop();

            // Explore neighboring cities
            for(auto k : adj[current]) {

                int neighbour = k.first;
                int w = k.second;

                // Calculate new distance
                long long newDistance = d + w;

                // Found a shorter path
                if(newDistance < distance[neighbour]) {

                    // Update shortest distance
                    distance[neighbour] = newDistance;

                    // All shortest paths come through current
                    paths[neighbour] = paths[current];

                    // Add updated state to priority queue
                    pq.push({
                        distance[neighbour],
                        neighbour
                    });
                }

                // Found another shortest path
                else if(newDistance == distance[neighbour]) {

                    // Add number of shortest paths
                    paths[neighbour] =
                        (paths[neighbour] + paths[current])
                        % ((int)1e9 + 7);
                }
            }
        }

        // Return number of shortest paths
        return paths[n - 1] % ((int)1e9 + 7);
    }
};

int main() {

    // Number of cities
    int n = 7;

    // {source, destination, travel time}
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };

    // Create Solution object
    Solution solution;

    // Count shortest paths
    int result = solution.countPaths(n, roads);

    // Print result
    cout << "Number of Shortest Paths: "
         << result << endl;

    return 0;
}