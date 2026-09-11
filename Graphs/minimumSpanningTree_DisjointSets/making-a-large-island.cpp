/*
Problem: Making A Large Island

LeetCode:
https://leetcode.com/problems/making-a-large-island/

Goal:
Given an N × N binary grid, change at most one 0 into 1
and return the maximum possible island area.

An island consists of cells connected horizontally or
vertically.

Approach:
Disjoint Set Union (DSU)

Step 1: Build the existing islands.

For every land cell:

    1. Convert its 2D position into a DSU node:

           node = row * N + column

    2. Union it with its right and lower land neighbors.

After this step, every connected island becomes one
DSU component.

The DSU parent array stores the component size:

    parent[root] = -size

Step 2: Try flipping every water cell.

For each 0 cell:

    1. Start with count = 1 because the 0 becomes land.
    2. Check its four neighboring cells.
    3. Find the DSU root of every neighboring island.
    4. Store roots in an unordered_set so the same island
       is not counted multiple times.
    5. Add the sizes of all distinct neighboring islands.
    6. Update the maximum area.

Step 3:
If the grid contains no 0, the entire grid is already
one island, so the answer is N × N.

Key Insight:

When flipping a 0:

    New island area
    =
    1
    +
    size of every DISTINCT neighboring island

The word DISTINCT is critical.

If two neighboring cells belong to the same island,
that island's size must be added only once.

PseudoCode : 

Create DSU for all N² cells

For every land cell:

    Union it with its lower land neighbor
    Union it with its right land neighbor

For every water cell:

    Create an empty set of island roots
    Set area = 1

    Check all four neighbors:

        If neighbor is land:

            Find its island root
            Add the root to the set

    For every distinct root:

        Add its island size to area

    Update maximum area

If no water cell exists:

    return N²

Return maximum area


Complexity Analysis : 

Time Complexity: O(N² * α(N²))
Space Complexity: O(N²)

where:
N = number of rows/columns in the square grid
α(N²) = inverse Ackermann function, practically constant.

The grid contains N² cells, and each cell is processed
a constant number of times.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        // Negative value means root + component size
        parent.resize(n, -1);
    }

    // Find root with path compression
    int find(int node) {

        if(parent[node] < 0) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    // Merge two components using union by size
    void unionSet(int a, int b) {

        int parent_a = find(a);
        int parent_b = find(b);

        // Merge only different components
        if(parent_a != parent_b) {

            // Attach smaller component to larger component
            if(parent[parent_a] < parent[parent_b]) {

                int temp = parent[parent_b];

                parent[parent_b] = parent_a;
                parent[parent_a] += temp;
            }
            else {

                int temp = parent[parent_a];

                parent[parent_a] = parent_b;
                parent[parent_b] += temp;
            }
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int ans = 0;

        // Create one DSU node for every grid cell
        DisjointSet dis_set(n * n);

        // Build DSU components for existing islands
        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 1) {

                    int node = n * r + c;

                    // Connect with lower land neighbor
                    if(r < n - 1 && grid[r + 1][c] == 1) {

                        int adj_node = n * (r + 1) + c;

                        dis_set.unionSet(node, adj_node);
                    }

                    // Connect with right land neighbor
                    if(c < n - 1 && grid[r][c + 1] == 1) {

                        int adj_node = n * r + (c + 1);

                        dis_set.unionSet(node, adj_node);
                    }
                }
            }
        }

        // Try converting every water cell into land
        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 0) {

                    int node = n * r + c;

                    // Store distinct neighboring island roots
                    unordered_set<int> set;

                    // Check upper neighbor
                    if(r > 0 && grid[r - 1][c] == 1) {

                        int adj_node = n * (r - 1) + c;

                        int overallParent =
                            dis_set.find(adj_node);

                        set.insert(overallParent);
                    }

                    // Check lower neighbor
                    if(r < n - 1 && grid[r + 1][c] == 1) {

                        int adj_node = n * (r + 1) + c;

                        int overallParent =
                            dis_set.find(adj_node);

                        set.insert(overallParent);
                    }

                    // Check left neighbor
                    if(c > 0 && grid[r][c - 1] == 1) {

                        int adj_node = n * r + (c - 1);

                        int overallParent =
                            dis_set.find(adj_node);

                        set.insert(overallParent);
                    }

                    // Check right neighbor
                    if(c < n - 1 && grid[r][c + 1] == 1) {

                        int adj_node = n * r + (c + 1);

                        int overallParent =
                            dis_set.find(adj_node);

                        set.insert(overallParent);
                    }

                    // Flipped cell itself contributes 1
                    int count = 1;

                    // Add sizes of distinct neighboring islands
                    for(auto x : set) {
                        count += (-dis_set.parent[x]);
                    }

                    // Update maximum island area
                    ans = max(ans, count);
                }
            }
        }

        // No zero exists, so the entire grid is already an island
        if(ans == 0) {
            return n * n;
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> grid = {
        {1, 0},
        {0, 1}
    };

    Solution obj;

    cout << "Largest Island: "
         << obj.largestIsland(grid)
         << endl;

    return 0;
}