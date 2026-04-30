/*

Problem: Subarray Sum Equals K
LeetCode: https://leetcode.com/problems/subarray-sum-equals-k/

Goal:
Find the number of subarrays whose sum equals k.

Approach:
Use Prefix Sum + HashMap.

Idea:
If prefix_sum - k already exists,
a subarray with sum k is found.

Time Complexity: O(n)
Space Complexity: O(n)

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int sum = 0;
        int count = 0;

        unordered_map<int,int> um;

        // important base case
        um[0] = 1;

        for(int i = 0; i < nums.size(); i++){

            sum += nums[i];

            // check if prefix sum difference exists
            if(um.find(sum - k) != um.end()){
                count += um[sum - k];
            }

            // store prefix sum
            um[sum]++;
        }

        return count;
    }
};