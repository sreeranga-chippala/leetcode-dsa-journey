/*
Problem: Job Sequencing Problem

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

Goal:
Each job has:
- Job ID
- Deadline
- Profit

Only one job can be completed in one unit of time.

Schedule the jobs to maximize the total profit.

Return:
1. Number of jobs performed.
2. Maximum profit earned.

Approach:
Greedy

- Sort all jobs in decreasing order of profit.
- Find the maximum deadline.
- Create a schedule array where each index
  represents one time slot.
- For every job:
    - Try to place it in the latest available
      slot before its deadline.
- If a slot is available:
    - Schedule the job.
    - Increase job count.
    - Add its profit.

Key Insight:
Scheduling a profitable job as late as possible
keeps earlier slots free for other jobs.

PseudoCode : 

sort jobs by profit in descending order

find maximum deadline

create empty time slots

for every job:

    try to place it in the latest free slot
    before its deadline

    if slot is free:

        schedule job

        increase job count

        add profit

return

job count

maximum profit


Complexity Analysis : 

Time Complexity: O(n log n + n × maxDeadline)
Space Complexity: O(maxDeadline)
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool compare(const vector<int>& a,
             const vector<int>& b){

    return a[2] > b[2];
}

class Solution {
public:

    vector<int> JobScheduling(vector<vector<int>>& Jobs) {

        int n = Jobs.size();

        sort(Jobs.begin(),
             Jobs.end(),
             compare);

        int maxDeadline = 0;

        for(int i = 0; i < n; i++){
            maxDeadline =
                max(maxDeadline, Jobs[i][1]);
        }

        vector<int> slot(maxDeadline + 1, -1);

        int jobCount = 0;
        int totalProfit = 0;

        for(int i = 0; i < n; i++){

            // Try the latest possible slot
            int time = Jobs[i][1];

            while(time > 0){

                if(slot[time] == -1){

                    slot[time] = Jobs[i][0];

                    jobCount++;

                    totalProfit += Jobs[i][2];

                    break;
                }

                time--;
            }

            // All slots are filled
            if(jobCount == maxDeadline){
                break;
            }
        }

        return {jobCount, totalProfit};
    }
};