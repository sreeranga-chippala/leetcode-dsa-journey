/*
Problem: Most Stones Removed with Same Row or Column

LeetCode:
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

Goal:
Remove the maximum number of stones such that every removed
stone shares either its row or column with another stone
that is still connected to it.

Approach:
Disjoint Set Union (DSU)

Treat every stone as a node.

Two stones belong to the same connected component if:

    stones[i] and stones[j] have the same row
    OR
    stones[i] and stones[j] have the same column

For every pair of stones:

    If they share a row or column:
        union them

After processing all pairs:

    Count the number of connected components.

For every connected component containing C stones,
we can remove:

    C - 1

stones.

Therefore:

    Total removable stones
    = N - number of components

Key Insight:

We must leave at least one stone in every connected
component.

So if there are N stones and C components:

    Maximum removable stones = N - C

Example:

    Stones = 5
    Components = 2

    Answer = 5 - 2 = 3

Path Compression:
The find() operation makes nodes point directly to
their component root.

Union by Size:
The smaller component is attached to the larger component.

Time Complexity: O(N^2 * α(N))

Space Complexity: O(N)

where:
N = number of stones
α(N) = inverse Ackermann function, which grows extremely
       slowly and is practically constant.

The O(N^2) comes from checking every pair of stones.
*/

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        // Negative value means the node is a root
        // and stores the negative component size
        parent.resize(n, -1);
    }

    // Find the root with path compression
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

        // Merge only if they belong to different components
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
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        // Create DSU for all stones
        DisjointSet dis_set(n);

        // Check every pair of stones
        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                // Stones sharing a row or column
                // belong to the same component
                if(stones[i][0] == stones[j][0] ||
                   stones[i][1] == stones[j][1]) {

                    dis_set.unionSet(i, j);
                }
            }
        }

        int components = 0;

        // Count connected components
        for(int i = 0; i < n; i++) {

            if(dis_set.parent[i] < 0) {
                components++;
            }
        }

        // One stone must remain in every component
        return n - components;
    }
};

int main() {

    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2}
    };

    Solution obj;

    cout << "Maximum stones removed: "
         << obj.removeStones(stones)
         << endl;

    return 0;
}