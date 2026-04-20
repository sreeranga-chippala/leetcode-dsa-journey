/*
Problem: Subarrays with K Different Integers

LeetCode: https://leetcode.com/problems/subarrays-with-k-different-integers/

Goal:
Count subarrays with exactly k distinct integers.

Approach:
Sliding Window + Prefix Counting

- Maintain window with at most k distinct elements
- Use prefix to count extra valid starting points
- When distinct_count == k:
    → add (prefix + 1) to result

Key Insight:
prefix counts how many redundant elements we can drop
from the left while keeping exactly k distinct.

PseudoCode : 

initialize start = 0
initialize prefix = 0
initialize total = 0
initialize distinct_count = 0
initialize map counts

for each end in array:

    if counts[current] == 0:
        distinct_count++

    counts[current]++

    if distinct_count > k:
        decrease counts at start
        move start forward
        reset prefix = 0
        if count becomes 0:
            distinct_count--

    while counts[start element] > 1:
        decrease its count
        move start forward
        prefix++

    if distinct_count == k:
        total += (prefix + 1)

return total

Complexity Analysis : 

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int start = 0;
        int prefix = 0;
        int total_subarrays = 0;
        int distinct_count = 0;

        unordered_map<int, int> counts;

        for(int end = 0; end < nums.size(); end++){

            // Add current element
            if(counts[nums[end]] == 0){
                distinct_count++;
            }
            counts[nums[end]]++;

            // If more than k distinct → shrink window
            if(distinct_count > k){
                counts[nums[start]]--;
                prefix = 0;
                if(counts[nums[start]] == 0){
                    distinct_count--;
                }
                start++;
            }

            // Remove extra duplicates from left
            while(counts[nums[start]] > 1){
                counts[nums[start]]--;
                prefix++;
                start++;
            }

            // If exactly k distinct → count subarrays
            if(distinct_count == k){
                total_subarrays += (prefix + 1);
            }
        }

        return total_subarrays;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {1,2,1,2,3};
    int k = 2;

    cout << "Subarrays with K distinct: "
         << obj.subarraysWithKDistinct(nums, k) << endl;

    return 0;
}