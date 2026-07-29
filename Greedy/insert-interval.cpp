/*
Problem: Insert Interval

LeetCode:
https://leetcode.com/problems/insert-interval/

Goal:
Given a list of non-overlapping intervals sorted
by their starting times, insert a new interval
and merge all overlapping intervals.

Approach:
Greedy Interval Merging

Divide the problem into three parts:

1. Add all intervals that end before the new interval.
2. Merge all overlapping intervals.
3. Add the remaining intervals.

Key Insight:
Since the intervals are already sorted, we only
need one linear scan through the array.

Time Complexity: O(n)

Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;

        int n = intervals.size();
        int i = 0;

        // -------------------------
        // Part 1:
        // Add all non-overlapping intervals
        // before the new interval.
        // -------------------------
        while(i < n && intervals[i][1] < newInterval[0]){

            ans.push_back(intervals[i]);
            i++;
        }

        // -------------------------
        // Part 2:
        // Merge all overlapping intervals.
        // -------------------------

        int start = INT_MAX;
        int end = INT_MIN;

        while(i < n && intervals[i][0] <= newInterval[1]){

            if(start == INT_MAX){
                start = intervals[i][0];
            }

            end = intervals[i][1];

            i++;
        }

        // Include the new interval itself
        start = min(start, newInterval[0]);
        end = max(end, newInterval[1]);

        ans.push_back({start, end});

        // -------------------------
        // Part 3:
        // Add the remaining intervals.
        // -------------------------
        while(i < n){

            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};

int main(){

    Solution obj;

    vector<vector<int>> intervals = {
        {1,3},
        {6,9}
    };

    vector<int> newInterval = {2,5};

    vector<vector<int>> ans =
        obj.insert(intervals, newInterval);

    cout << "Merged Intervals:\n";

    for(auto interval : ans){

        cout << "[" << interval[0]
             << ", "
             << interval[1]
             << "] ";

    }

    return 0;
}