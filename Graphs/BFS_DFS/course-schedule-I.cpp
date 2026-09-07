/*
Problem: Course Schedule

LeetCode:
https://leetcode.com/problems/course-schedule/

Goal:
Given the number of courses and prerequisite relationships,
determine whether it is possible to finish all courses.

Prerequisite:

    [course, prerequisite]

means:

    prerequisite → course

Example:

    [1, 0]

means:

    To take course 1,
    we must first complete course 0.

Therefore:

    0 → 1


Approach:
Kahn's Algorithm

Kahn's Algorithm is a BFS-based Topological Sort algorithm.

Steps:

1. Build the directed graph.

2. Calculate indegree of every node.

    indegree[node] =
    number of prerequisites / incoming edges.

3. Put all nodes with indegree 0 into the queue.

4. Remove a node from the queue.

5. Add it to the topological ordering.

6. Remove its outgoing edges by decreasing the
   indegree of its neighbors.

7. If a neighbor's indegree becomes 0,
   add it to the queue.

8. If we process all nodes:

       No cycle exists.

   Otherwise:

       A cycle exists.


Why does a cycle prevent completion?

Example:

    0 → 1
    ↑   ↓
    └───2

Every node has an incoming edge.

Therefore, no node has indegree 0,
so BFS cannot start processing the cycle.


PseudoCode : 

create adjacency list


for every prerequisite [course, prerequisite]:

    add course to adjacency list
    of prerequisite


create indegree array


for every node:

    for every neighbor:

        increase indegree[neighbor]


create queue


for every node:

    if indegree[node] == 0:

        push node into queue


count = 0


while queue is not empty:

    node = remove front

    count++


    for every neighbor of node:

        decrease indegree[neighbor]

        if indegree[neighbor] == 0:

            push neighbor


if count == number of courses:

    return true

else:

    return false

    
Complexity Analysis : 

Time Complexity: O(V + E)
Space Complexity: O(V + E)

V = number of courses
E = number of prerequisites
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {

public:

    // --------------------------------------------------
    // Kahn's Algorithm
    //
    // Returns true if the graph has no cycle.
    // --------------------------------------------------

    bool noCycle(
        vector<vector<int>>& adj
    ) {

        int n = adj.size();


        // Queue stores nodes whose indegree is 0.
        queue<int> q;


        // incoming[i] = number of incoming edges
        // to node i.
        vector<int> incoming(
            n,
            0
        );


        // Stores the topological ordering.
        vector<int> ans;


        // --------------------------------------------------
        // Calculate indegree of every node.
        // --------------------------------------------------

        for (int i = 0; i < n; i++) {

            for (int neighbour : adj[i]) {

                incoming[neighbour]++;
            }
        }


        // --------------------------------------------------
        // Add all nodes with indegree 0.
        //
        // These courses have no prerequisites.
        // --------------------------------------------------

        for (int i = 0; i < n; i++) {

            if (incoming[i] == 0) {

                q.push(i);
            }
        }


        // --------------------------------------------------
        // BFS / Kahn's Algorithm
        // --------------------------------------------------

        while (!q.empty()) {

            // Take a course that currently has
            // no remaining prerequisites.
            int node = q.front();

            q.pop();


            // Add it to the topological ordering.
            ans.push_back(node);


            // --------------------------------------------------
            // Remove the outgoing edges from this node.
            // --------------------------------------------------

            for (int neighbour : adj[node]) {

                incoming[neighbour]--;


                // All prerequisites of this neighbor
                // have now been completed.
                if (incoming[neighbour] == 0) {

                    q.push(neighbour);
                }
            }
        }


        // If all courses were processed,
        // there is no cycle.
        return ans.size() == n;
    }


    // --------------------------------------------------
    // Course Schedule
    // --------------------------------------------------

    bool canFinish(
        int numCourses,
        vector<vector<int>>& prerequisites
    ) {

        // Create adjacency list.
        vector<vector<int>> adj(
            numCourses
        );


        // Build the directed graph.
        //
        // [f, s] means:
        //
        // s → f
        //
        // s must be completed before f.
        for (const auto& course : prerequisites) {

            int s = course[1];
            int f = course[0];


            adj[s].push_back(f);
        }


        // If the graph has no cycle,
        // all courses can be completed.
        if (noCycle(adj)) {

            return true;
        }


        return false;
    }
};


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
        Example:

        numCourses = 4

        prerequisites:

        [1,0]
        [2,0]
        [3,1]
        [3,2]

        Graph:

             0
            / \
           ↓   ↓
           1   2
            \ /
             ↓
             3

        One valid order:

        0 → 1 → 2 → 3

        Therefore, all courses can be completed.
    */

    int numCourses = 4;


    vector<vector<int>> prerequisites = {

        {1, 0},

        {2, 0},

        {3, 1},

        {3, 2}
    };


    Solution obj;


    // Check whether all courses can be completed.
    bool result = obj.canFinish(
        numCourses,
        prerequisites
    );


    // Print the result.
    if (result) {

        cout << "Can Finish All Courses: Yes"
             << endl;
    }

    else {

        cout << "Can Finish All Courses: No"
             << endl;
    }


    return 0;
}