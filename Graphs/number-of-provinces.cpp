/*

Problem: Number of Provinces

LeetCode:
https://leetcode.com/problems/number-of-provinces/

Goal:
Given an adjacency matrix representing connections
between cities, find the number of provinces.

A province is a group of directly or indirectly
connected cities.

Approach:
BFS + Connected Components

- Treat each city as a node
- Use BFS to visit all cities connected to a starting city
- Every time we start BFS from an unvisited city,
  we discover a new province

Key Insight:
Number of connected components in the graph
= Number of provinces.

Pseudocode : 

BFS Function:
    mark start city visited

    insert start city into queue

    while queue not empty:

        remove front city

        for every city:

            if connected and not visited:

                mark visited

                insert into queue
Main Function :
    components = 0

    mark all cities unvisited

    for each city:

        if city not visited:

            components++

            perform BFS from this city

    return components
    
Complexity Analysis : 

Time Complexity: O(n²)
    n = number of cities

Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void bfs(int start,
             vector<vector<int>>& isConnected,
             vector<int>& visited){

        int n = isConnected.size();

        // Manual queue implementation
        vector<int> queue(n);

        int front = 0;
        int rear = 0;

        queue[rear++] = start;
        visited[start] = 1;

        while(front < rear){

            int u = queue[front++];

            // Check all neighbors
            for(int v = 0; v < n; v++){

                if(isConnected[u][v] && !visited[v]){

                    visited[v] = 1;
                    queue[rear++] = v;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        int components = 0;

        vector<int> visited(n, 0);

        for(int i = 0; i < n; i++){

            // New connected component found
            if(!visited[i]){

                components++;

                bfs(i, isConnected, visited);
            }
        }

        return components;
    }
};

int main(){

    Solution obj;

    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    cout << "Number of Provinces: "
         << obj.findCircleNum(isConnected)
         << endl;

    return 0;
}