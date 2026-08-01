/*
Problem: Non-overlapping Intervals

LeetCode: https://leetcode.com/problems/non-overlapping-intervals/

Goal:
Find the minimum number of intervals to remove 
so that the rest are non-overlapping.

Approach:
Greedy (Sort by End Time)

- Sort intervals by their end time
- Always pick the interval with earliest end
- If next interval overlaps:
    → remove it (increment count)
- Else:
    → accept it and update end_current

Key Insight:
Choosing intervals with smallest end time leaves 
maximum room for future intervals.

PseudoCode :
if intervals empty:
    return 0

sort intervals by end time

set end_current = end of first interval
set overlapping = 0

for each interval from second onward:

    if current start < end_current:
        overlapping++
    else:
        update end_current = current end

return overlapping

Complexity Analysis :

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator: sort by end time
bool compare(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), compare);

        int overlapping = 0;
        int end_current = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){

            int start_next = intervals[i][0];
            int end_next = intervals[i][1];

            // Overlap case
            if(start_next < end_current){
                overlapping++;  // remove this interval
            }
            else{
                // No overlap → accept interval
                end_current = end_next;
            }
        }

        return overlapping;
    }
};

int main(){
    Solution obj;

    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};

    cout << "Minimum removals: "
         << obj.eraseOverlapIntervals(intervals) << endl;

    return 0;
}