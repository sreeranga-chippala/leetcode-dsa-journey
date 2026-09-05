/*
Problem: Path With Minimum Effort

LeetCode:
https://leetcode.com/problems/path-with-minimum-effort/

Goal:
Find a path from the top-left cell to the
bottom-right cell such that the maximum absolute
difference in heights between consecutive cells
is minimized.

Approach:
Dijkstra's Algorithm

The grid can be treated as a graph.

Each cell is a node, and its neighboring cells
are connected by edges.

For two adjacent cells:

    (r, c)
       |
    (r2, c2)

the effort required to move between them is:

    abs(heights[r][c] - heights[r2][c2])

Unlike normal shortest path problems, the total
effort of a path is NOT the sum of all edge costs.

For a path:

    A → B → C → D

if the edge efforts are:

    2, 5, 3

then the effort of the entire path is:

    max(2, 5, 3) = 5

Therefore, when moving from the current cell
to a neighboring cell:

    delta = absolute height difference

the effort of reaching the neighbor becomes:

    max(current path effort, delta)

We maintain:

    effort_matrix[r][c]

which stores the minimum possible effort needed
to reach cell (r, c).

A min-heap priority queue is used so that the
cell with the smallest current effort is processed
first.

Initially:

    effort_matrix[0][0] = 0

and:

    {0, {0, 0}}

is pushed into the priority queue.

For every cell, check its four possible directions:

    Up
    Down
    Left
    Right

If the newly calculated effort is smaller than
the currently known effort for that neighbor,
update it and push the neighbor into the queue.

Key Insight:

Normal Dijkstra uses:

    new distance =
    current distance + edge weight

Here, the path cost is the maximum edge effort:

    new effort =
    max(current effort, edge effort)

So this is Dijkstra with a different
path-cost calculation.

Time Complexity: O(M * N * log(M * N))

Space Complexity: O(M * N)

where:

M = number of rows
N = number of columns
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
#include <cstdlib>

using namespace std;

class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        // Store minimum effort required to reach each cell
        vector<vector<int>> effort_matrix(
            m,
            vector<int>(n, INT_MAX)
        );

        // Starting cell requires zero effort
        effort_matrix[0][0] = 0;

        // Min-heap:
        // {effort, {row, column}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        // Start from top-left cell
        pq.push({0, {0, 0}});

        // Process cells using Dijkstra's algorithm
        while(!pq.empty()) {

            // Get cell with minimum current effort
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;

            pq.pop();

            // Move Up
            if(r > 0) {

                int delta = abs(
                    heights[r][c] - heights[r - 1][c]
                );

                // Path effort is the maximum effort so far
                int effort = max(
                    delta,
                    effort_matrix[r][c]
                );

                // Update if this path is better
                if(effort < effort_matrix[r - 1][c]) {

                    effort_matrix[r - 1][c] = effort;

                    pq.push({
                        effort,
                        {r - 1, c}
                    });
                }
            }

            // Move Down
            if(r < m - 1) {

                int delta = abs(
                    heights[r][c] - heights[r + 1][c]
                );

                int effort = max(
                    delta,
                    effort_matrix[r][c]
                );

                // Update if this path is better
                if(effort < effort_matrix[r + 1][c]) {

                    effort_matrix[r + 1][c] = effort;

                    pq.push({
                        effort,
                        {r + 1, c}
                    });
                }
            }

            // Move Left
            if(c > 0) {

                int delta = abs(
                    heights[r][c] - heights[r][c - 1]
                );

                int effort = max(
                    delta,
                    effort_matrix[r][c]
                );

                // Update if this path is better
                if(effort < effort_matrix[r][c - 1]) {

                    effort_matrix[r][c - 1] = effort;

                    pq.push({
                        effort,
                        {r, c - 1}
                    });
                }
            }

            // Move Right
            if(c < n - 1) {

                int delta = abs(
                    heights[r][c] - heights[r][c + 1]
                );

                int effort = max(
                    delta,
                    effort_matrix[r][c]
                );

                // Update if this path is better
                if(effort < effort_matrix[r][c + 1]) {

                    effort_matrix[r][c + 1] = effort;

                    pq.push({
                        effort,
                        {r, c + 1}
                    });
                }
            }
        }

        // Return minimum effort to reach bottom-right
        return effort_matrix[m - 1][n - 1];
    }
};

int main() {

    // Height of each cell
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    // Create Solution object
    Solution solution;

    // Find minimum effort path
    int result = solution.minimumEffortPath(heights);

    // Print result
    cout << "Minimum Effort: " << result << endl;

    return 0;
}