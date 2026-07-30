/*
Problem: Shortest Job First (SJF)

Goal:
Given the execution (or delivery) times of jobs,
schedule them so that the average waiting time
is minimized.

Return the average waiting time.

Approach:
Greedy (Shortest Job First)

- Sort all jobs in increasing order of execution time.
- Execute the shortest job first.
- Keep track of:
    - Current elapsed time.
    - Total waiting time.

Waiting Time:
A job waits for the total execution time of all
previous jobs.

Average Waiting Time:

Total Waiting Time / Number of Jobs

Key Insight:
Executing shorter jobs first minimizes the waiting
time of longer jobs, producing the minimum average
waiting time.

Time Complexity: O(n log n)

Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int shortestJobFirst(vector<int> &deliveryTimes) {

        int n = deliveryTimes.size();

        sort(deliveryTimes.begin(), deliveryTimes.end());

        long long currentTime = 0;
        long long totalWaitingTime = 0;

        for(int i = 0; i < n; i++){

            // Waiting time of current job
            totalWaitingTime += currentTime;

            // Execute current job
            currentTime += deliveryTimes[i];
        }

        return totalWaitingTime / n;
    }
};

int main(){

    Solution obj;

    vector<int> jobs = {4, 3, 7, 1, 2};

    cout << "Average Waiting Time: "
         << obj.shortestJobFirst(jobs);

    return 0;
}