/*
Problem: Course Schedule II

LeetCode:
https://leetcode.com/problems/course-schedule-ii/

Goal:
Return an ordering of courses such that every
course appears after all of its prerequisites.

If no valid ordering exists because the graph
contains a cycle, return an empty vector.

Approach:
Kahn's Algorithm / Topological Sort

Steps:

1. Build the directed graph.

2. Calculate indegree of every course.

3. Add every course with indegree 0
   to the queue.

4. Process the queue using BFS.

5. Add every processed course to the answer.

6. Decrease the indegree of its neighbors.

7. When a neighbor's indegree becomes 0,
   add it to the queue.

8. At the end:

       If answer contains all courses:
           return answer

       Otherwise:
           return empty vector


Time Complexity:
O(V + E)

Space Complexity:
O(V + E)

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
    // Generates a topological ordering.
    // --------------------------------------------------

    void kahnAlgorithm(
        int n,
        vector<vector<int>>& adj,
        vector<int>& ans
    ) {

        // Queue stores nodes with indegree 0.
        queue<int> q;


        // Stores the indegree of every node.
        vector<int> incoming(
            n,
            0
        );


        // --------------------------------------------------
        // Calculate indegree.
        // --------------------------------------------------

        for (int i = 0; i < n; i++) {

            for (int neighbour : adj[i]) {

                incoming[neighbour]++;
            }
        }


        // --------------------------------------------------
        // Add all nodes with indegree 0.
        // --------------------------------------------------

        for (int i = 0; i < n; i++) {

            if (incoming[i] == 0) {

                q.push(i);
            }
        }


        // --------------------------------------------------
        // Perform Kahn's Algorithm.
        // --------------------------------------------------

        while (!q.empty()) {

            // Get a course with no remaining prerequisites.
            int node = q.front();

            q.pop();


            // Add it to the course ordering.
            ans.push_back(node);


            // Remove this course's outgoing edges.
            for (int neighbour : adj[node]) {

                incoming[neighbour]--;


                // All prerequisites are now satisfied.
                if (incoming[neighbour] == 0) {

                    q.push(neighbour);
                }
            }
        }
    }


    // --------------------------------------------------
    // Find a valid course ordering.
    // --------------------------------------------------

    vector<int> findOrder(
        int numCourses,
        vector<vector<int>>& prerequisites
    ) {

        // Create adjacency list.
        vector<vector<int>> adj(
            numCourses
        );


        // Stores the topological ordering.
        vector<int> ans;


        // Build graph.
        //
        // [f, s] means:
        //
        // s → f
        //
        // s must come before f.
        for (auto course : prerequisites) {

            int s = course[1];
            int f = course[0];


            adj[s].push_back(f);
        }


        // Perform topological sorting.
        kahnAlgorithm(
            numCourses,
            adj,
            ans
        );


        // --------------------------------------------------
        // Check whether every course was processed.
        // --------------------------------------------------

        if (ans.size() == numCourses) {

            return ans;
        }

        else {

            // A cycle exists.
            // No valid ordering is possible.
            return {};
        }
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

        One valid ordering:

            0 1 2 3
    */

    int numCourses = 4;


    vector<vector<int>> prerequisites = {

        {1, 0},

        {2, 0},

        {3, 1},

        {3, 2}
    };


    Solution obj;


    // Find a valid course order.
    vector<int> result =
        obj.findOrder(
            numCourses,
            prerequisites
        );


    // Print the result.
    if (result.empty()) {

        cout << "No Valid Course Order Exists"
             << endl;
    }

    else {

        cout << "Course Order: ";

        for (int course : result) {

            cout << course << " ";
        }

        cout << endl;
    }


    return 0;
}