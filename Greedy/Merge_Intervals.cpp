/*
Problem: Merge Intervals

LeetCode: https://leetcode.com/problems/merge-intervals/

Goal:
Merge all overlapping intervals and return the result.

Approach:
Greedy + Sorting

- Sort intervals by start time
- Initialize result with first interval
- For each next interval:
    → If it overlaps with last interval in result:
        merge them (update end)
    → Else:
        add as a new interval

Key Insight:
Once sorted, overlapping intervals will be adjacent.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator: sort by start time
bool compare(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(), compare);

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){

            // If overlap exists
            if(result.back()[1] >= intervals[i][0]){
                // Merge intervals
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else{
                // No overlap → add new interval
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

int main(){
    Solution obj;

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ans = obj.merge(intervals);

    cout << "Merged Intervals: ";
    for(auto &v : ans){
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;

    return 0;
}