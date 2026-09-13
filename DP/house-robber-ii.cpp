/*
Problem: House Robber II

LeetCode:
https://leetcode.com/problems/house-robber-ii/

Goal:
Find the maximum amount of money that can be robbed
from houses arranged in a circle.

Adjacent houses cannot both be robbed.

The circular arrangement creates one additional
restriction:

    First house and last house are also adjacent.

Approach:
Dynamic Programming + Two Linear Cases

We cannot directly apply the linear House Robber
solution to the entire array because the first and
last houses are adjacent.

So divide the problem into two mutually exclusive cases:

Case 1:
Exclude the last house.

    Consider houses from index 0 to N - 2.

Case 2:
Exclude the first house.

    Consider houses from index 1 to N - 1.

Solve both cases using the same space-optimized
House Robber DP.

Final answer:

    max(case 1, case 2)

Why does this work?

Any valid solution must exclude at least one of the
first or last houses because they are adjacent.

Therefore every valid solution belongs to one of
these two cases.

Key Insight:

Circular DP can often be converted into linear DP by
breaking the circle into separate cases.

    Circular houses
          ↓
    Exclude first OR exclude last
          ↓
    Two linear House Robber problems

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

    // Solve the linear House Robber problem
    // for the range [start, end]
    int helper(vector<int>& nums, int start, int end) {

        int prior2 = 0;
        int prior1 = 0;
        int current = 0;

        // Process houses in the selected range
        for(int i = start; i <= end; i++) {

            // Rob current house
            int pick = nums[i] + prior2;

            // Skip current house
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

        // Case 1: Exclude the last house
        int helper1 = helper(nums, 0, n - 2);

        // Case 2: Exclude the first house
        int helper2 = helper(nums, 1, n - 1);

        // Take the better of the two cases
        return max(helper1, helper2);
    }
};

int main() {

    vector<int> nums = {2, 3, 2};

    Solution obj;

    cout << "Maximum money robbed: "
         << obj.rob(nums)
         << endl;

    return 0;
}