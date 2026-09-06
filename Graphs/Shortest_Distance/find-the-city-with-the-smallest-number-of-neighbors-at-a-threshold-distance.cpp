/*
Problem: Find the City With the Smallest Number of Neighbors
         at a Threshold Distance

LeetCode:
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

Goal:
Find the city that has the smallest number of cities
reachable within distanceThreshold.

If multiple cities have the same minimum number of
reachable cities, return the city with the greatest
index.

Approach:
Floyd-Warshall Algorithm

Since we need the shortest distance between every
pair of cities, Floyd-Warshall is a suitable approach.

We maintain a distance matrix:

    distance[i][j]

which represents the shortest known distance from
city i to city j.

Initially:

    distance[i][i] = 0

For every edge:

    [a, b, w]

we set:

    distance[a][b] = w
    distance[b][a] = w

because the graph is undirected.

Then use Floyd-Warshall.

For every intermediate city k:

    for every source city i:
        for every destination city j:

            distance[i][j] =
                min(
                    distance[i][j],
                    distance[i][k] + distance[k][j]
                )

This checks whether going from i to j through
city k gives a shorter path.

After calculating all-pairs shortest distances,
count how many cities are within distanceThreshold
for every city.

The city with the smallest count is selected.

To handle the tie condition, iterate from:

    n - 1 → 0

and update the answer only when:

    count < min_cities

Therefore, when two cities have the same count,
the larger-indexed city remains the answer.

Key Insight:

Floyd-Warshall gives the shortest distance between
every pair of cities.

Then for each city:

    count cities whose shortest distance
    <= distanceThreshold

Finally:

    minimum reachable cities
            ↓
    greatest index in case of tie

Time Complexity: O(N^3)

Space Complexity: O(N^2)

where:

N = number of cities
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:

    int findTheCity(int n,
                    vector<vector<int>>& edges,
                    int distanceThreshold) {

        // Initialize distance matrix
        vector<vector<long long>> distance(
            n,
            vector<long long>(n, INT_MAX)
        );

        // Add all edges to the distance matrix
        for(auto edge : edges){

            int a = edge[0];
            int b = edge[1];
            int w = edge[2];

            // Graph is undirected
            distance[a][b] = w;
            distance[b][a] = w;
        }

        // Distance from a city to itself is zero
        for(int i = 0; i < n; i++){
            distance[i][i] = 0;
        }

        // Floyd-Warshall:
        // Use every city as an intermediate city
        for(int k = 0; k < n; k++){

            for(int i = 0; i < n; i++){

                for(int j = 0; j < n; j++){

                    // Check whether going through k
                    // gives a shorter path from i to j
                    distance[i][j] = min(
                        distance[i][j],
                        distance[i][k] + distance[k][j]
                    );
                }
            }
        }

        // Store the minimum number of reachable cities
        int min_cities = INT_MAX;

        // Start with the largest city index
        int ans = n - 1;

        // Iterate from largest index to smallest
        // to handle the tie condition
        for(int i = n - 1; i >= 0; i--){

            int count = 0;

            // Count cities within threshold distance
            for(int j = 0; j < n; j++){

                if(distance[i][j] <= distanceThreshold){
                    count++;
                }
            }

            // Update only when a strictly smaller
            // count is found
            if(count < min_cities){

                min_cities = count;
                ans = i;
            }
        }

        // Return city with minimum reachable cities
        // and greatest index in case of a tie
        return ans;
    }
};

int main(){

    // Number of cities
    int n = 4;

    // {city1, city2, distance}
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };

    // Maximum allowed distance
    int distanceThreshold = 4;

    // Create Solution object
    Solution solution;

    // Find required city
    int result = solution.findTheCity(
        n,
        edges,
        distanceThreshold
    );

    // Print result
    cout << "City: " << result << endl;

    return 0;
}