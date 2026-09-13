/*
Problem: House Robber

LeetCode:
https://leetcode.com/problems/house-robber/

Goal:
Given an array where nums[i] represents the money
in the i-th house, find the maximum amount of money
that can be robbed without robbing two adjacent houses.

Approach:
Dynamic Programming with O(1) Space

For every house, there are two choices:

    1. Pick the current house
    2. Do not pick the current house

If we pick house i:

    nums[i] + maximum money up to house i - 2

If we do not pick house i:

    maximum money up to house i - 1

Therefore:

    dp[i] = max(
        nums[i] + dp[i - 2],
        dp[i - 1]
    )

Base cases:

    dp[0] = nums[0]

    dp[1] = max(nums[0], nums[1])

Only the previous two DP states are required,
so the complete DP array is not stored.

Key Insight:

At every house, the decision is:

    PICK
      ↓
    Current money + two houses back

    NOT PICK
      ↓
    Previous best

Take the maximum of the two.

Time Complexity: O(N)

Space Complexity: O(1)

where:
N = number of houses.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int helper(int i, vector<int>& nums) {

        // Base cases
        if(i == 0) {
            return nums[0];
        }

        if(i == 1) {
            return max(nums[0], nums[1]);
        }

        // DP states for first two houses
        int prior2 = nums[0];
        int prior1 = max(nums[0], nums[1]);

        int current = prior1;

        // Process remaining houses
        for(int i = 2; i < nums.size(); i++) {

            // Pick current house
            int pick = nums[i] + prior2;

            // Do not pick current house
            int not_pick = prior1;

            // Choose the better option
            current = max(pick, not_pick);

            // Move DP states forward
            prior2 = prior1;
            prior1 = current;
        }

        return current;
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        return helper(n, nums);
    }
};

int main() {

    vector<int> nums = {2, 7, 9, 3, 1};

    Solution obj;

    cout << "Maximum money robbed: "
         << obj.rob(nums)
         << endl;

    return 0;
}