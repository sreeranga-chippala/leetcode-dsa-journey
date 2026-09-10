/*
Problem: Number of Islands II

Reference:
https://www.geeksforgeeks.org/problems/number-of-islands/1

Goal:
Given an initially empty N × M grid, land cells are added
one by one.

After every addition, return the current number of islands.

Two land cells belong to the same island if they are
connected vertically or horizontally.

Approach:
Disjoint Set Union (DSU) + Dynamic Grid

Initially, every cell is water.

For every new land cell:

1. If the cell is already land, do nothing.
2. Otherwise, mark it as land.
3. Increase the island count by 1.
4. Convert the cell's 2D position into a DSU node:

       node = row * M + column

5. Check its four possible neighbors.
6. If a neighboring cell is already land and belongs to
   a different DSU component, merge the two components.
7. Every successful merge combines two islands, so decrease
   the island count by 1.
8. Store the current island count in the answer.

Key Insight:

When a new land cell is added:

    New land → +1 island

For every different neighboring island that gets merged:

    Successful union → -1 island

Therefore, we maintain the island count dynamically
instead of running DFS/BFS after every operation.

Time Complexity: O(K * α(N*M))

Space Complexity: O(N*M + K)

where:
N = number of rows
M = number of columns
K = number of land additions
α(N*M) = inverse Ackermann function, practically constant.
*/

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        // Negative value represents a root
        // and stores the component size
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& A) {

        // One DSU node for every grid cell
        DisjointSet dis_set(n * m);

        // 0 = water, 1 = land
        vector<vector<int>> grid(n, vector<int>(m, 0));

        vector<int> ans;

        int count = 0;

        // Process every land addition
        for(auto a : A) {

            int r = a[0];
            int c = a[1];

            // Ignore duplicate land additions
            if(grid[r][c] == 0) {

                grid[r][c] = 1;

                // New land initially forms a new island
                count++;

                // Convert 2D cell into DSU node
                int node = m * r + c;

                // Check upper neighbor
                if(r > 0 && grid[r - 1][c] == 1) {

                    int adj_node = m * (r - 1) + c;

                    if(dis_set.find(node) != dis_set.find(adj_node)) {

                        count--;

                        dis_set.unionSet(node, adj_node);
                    }
                }

                // Check lower neighbor
                if(r < n - 1 && grid[r + 1][c] == 1) {

                    int adj_node = m * (r + 1) + c;

                    if(dis_set.find(node) != dis_set.find(adj_node)) {

                        count--;

                        dis_set.unionSet(node, adj_node);
                    }
                }

                // Check left neighbor
                if(c > 0 && grid[r][c - 1] == 1) {

                    int adj_node = m * r + c - 1;

                    if(dis_set.find(node) != dis_set.find(adj_node)) {

                        count--;

                        dis_set.unionSet(node, adj_node);
                    }
                }

                // Check right neighbor
                if(c < m - 1 && grid[r][c + 1] == 1) {

                    int adj_node = m * r + c + 1;

                    if(dis_set.find(node) != dis_set.find(adj_node)) {

                        count--;

                        dis_set.unionSet(node, adj_node);
                    }
                }
            }

            // Store islands after this operation
            ans.push_back(count);
        }

        return ans;
    }
};

int main() {

    int n = 4;
    int m = 5;

    vector<vector<int>> A = {
        {1, 1},
        {0, 1},
        {3, 3},
        {3, 4}
    };

    Solution obj;

    vector<int> result = obj.numOfIslands(n, m, A);

    cout << "Number of islands after each operation: ";

    for(int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}