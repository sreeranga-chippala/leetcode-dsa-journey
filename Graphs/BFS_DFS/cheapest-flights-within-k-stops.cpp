/*
Problem: Cheapest Flights Within K Stops

LeetCode:
https://leetcode.com/problems/cheapest-flights-within-k-stops/

Goal:
Find the cheapest price from src to dst using
at most k stops.

Approach:
BFS with Cost and Flight-Level Tracking

The flights form a directed weighted graph.

For every flight:

    [from, to, price]

create an adjacency list:

    from -> {to, price}

We maintain a distance array:

    distance[i]

which stores the cheapest known cost to reach
city i.

The queue stores:

    {length, {cost, city}}

where:

    length = number of flights taken
    cost   = current total cost
    city   = current city

Initially:

    distance[src] = 0

and push:

    {1, {0, src}}

into the queue.

For every neighboring city, calculate:

    newCost = current cost + flight price

If the new cost is cheaper than the previously
known cost and the allowed flight limit has not
been exceeded, update the distance and push the
new state into the queue.

Important:

If k stops are allowed, then at most:

    k + 1 flights

can be taken.

Since length starts from 1 in this implementation,
the condition becomes:

    (length + 1) <= k + 2

Key Insight:

The problem has two requirements:

    1. Minimize the total cost.
    2. Do not exceed k stops.

Therefore, while traversing the graph, we need
to track both the cost and the number of flights.

PseudoCode : 

Create adjacency list from all flights

Set source distance to 0

Push source into queue with:
    flights taken = 1
    cost = 0

while queue is not empty:

    get current city, cost and flights taken

    for each neighboring city:

        calculate new cost

        if new cost is cheaper
        AND allowed flight limit is not exceeded:

            update cheapest cost

            push neighboring city into queue
            with updated cost and flight count

if destination is unreachable:

    return -1

return cheapest cost


Complexity Analysis : 

Time Complexity: O(K * E)
Space Complexity: O(N + K * E)

where:

N = number of cities
E = number of flights (edges)
K = maximum number of stops
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>

using namespace std;

class Solution {
public:

    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for(auto flight : flights){

            // Store destination and price
            // for each source city
            adj[flight[0]].push_back({
                flight[1],
                flight[2]
            });
        }

        // Store cheapest known cost for each city
        vector<int> distance(n, INT_MAX);

        // Source has zero cost
        distance[src] = 0;

        // Queue stores:
        // {number of flights, {cost, city}}
        queue<pair<int, pair<int, int>>> q;

        // Start BFS from source
        q.push({1, {0, src}});

        // Process all possible states
        while(!q.empty()){

            // Get current state
            int length = q.front().first;
            int d = q.front().second.first;
            int node = q.front().second.second;

            q.pop();

            // Explore all flights from current city
            for(auto v : adj[node]){

                int neighbour = v.first;
                int weight = v.second;

                // Check cheaper cost and valid flight limit
                if((d + weight < distance[neighbour]) &&
                   ((length + 1) <= k + 2)){

                    // Update cheapest cost
                    distance[neighbour] = d + weight;

                    // Add new state to queue
                    q.push({
                        length + 1,
                        {distance[neighbour], neighbour}
                    });
                }
            }
        }

        // Destination cannot be reached
        if(distance[dst] == INT_MAX){
            return -1;
        }

        // Return cheapest valid price
        return distance[dst];
    }
};

int main(){

    // Number of cities
    int n = 4;

    // {source, destination, price}
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    // Source city
    int src = 0;

    // Destination city
    int dst = 3;

    // Maximum number of stops
    int k = 1;

    // Create Solution object
    Solution solution;

    // Find cheapest valid price
    int result = solution.findCheapestPrice(
        n,
        flights,
        src,
        dst,
        k
    );

    // Print result
    cout << "Cheapest Price: " << result << endl;

    return 0;
}