/*
Problem: Number of Operations to Make Network Connected

LeetCode:
https://leetcode.com/problems/number-of-operations-to-make-network-connected/

Goal:
Connect all N computers using the minimum number of
operations.

If the network contains C connected components,
we need:

    C - 1

operations to connect them.

Approach:
Disjoint Set Union (DSU)

The DSU maintains which computers belong to the same
connected component.

Each component has a representative called its parent.

Initially:

    parent[i] = -1

This means:
- i is its own parent
- i is the root of its component
- the component contains 1 node

The parent array also stores component size using
negative values.

For example:

    parent[root] = -5

means that root represents a component containing
5 computers.

Union by Size:
When merging two components, attach the smaller
component under the larger component.

Because sizes are stored negatively:

    -5 < -2

means the first component is larger.

Path Compression:
During find(), make every visited node point directly
to the root.

This makes future find operations very fast.

Algorithm:

1. If the number of connections is less than N - 1,
   return -1 because there are not enough cables.

2. Create a DSU containing N computers.

3. For every connection:
       union the two computers.

4. Count the number of roots in the parent array.
   Each root represents one connected component.

5. Return:

       components - 1

Key Insight:

The problem does not require us to actually perform
the cable rearrangements.

We only need to know how many disconnected components
exist.

If there are:

    C components

then exactly:

    C - 1

connections are required to join them.

PseudoCode : 

If number of connections < N - 1:
    return -1

Create a DSU for all computers

For every connection (a, b):

    Find the roots of a and b

    If they belong to different components:
        merge the smaller component into the larger one

Count the number of component roots

Return components - 1


Complexity Analysis : 

Time Complexity: O(E * α(N))
Space Complexity: O(N)

where:
N = number of computers
E = number of connections
α(N) = inverse Ackermann function, which grows
       extremely slowly and is practically constant.
*/

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        // -1 means the node is a root
        // and initially has size 1
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
    void union_size(int a, int b) {

        int parent_a = find(a);
        int parent_b = find(b);

        // Already part of the same component
        if(parent_a != parent_b) {

            // Attach the smaller component
            // under the larger component
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
    int makeConnected(int n, vector<vector<int>>& connections) {

        // At least N - 1 connections are required
        if(connections.size() < n - 1) {
            return -1;
        }

        // Create DSU for all computers
        DisjointSet dsu(n);

        // Merge computers connected by each cable
        for(auto connection : connections) {

            int a = connection[0];
            int b = connection[1];

            dsu.union_size(a, b);
        }

        int count = 0;

        // Every root represents one component
        for(int i = 0; i < n; i++) {

            if(dsu.parent[i] < 0) {
                count++;
            }
        }

        // C components require C - 1 operations
        return count - 1;
    }
};

int main() {

    int n = 4;

    vector<vector<int>> connections = {
        {0, 1},
        {0, 2},
        {1, 2}
    };

    Solution obj;

    cout << "Minimum operations: "
         << obj.makeConnected(n, connections)
         << endl;

    return 0;
}