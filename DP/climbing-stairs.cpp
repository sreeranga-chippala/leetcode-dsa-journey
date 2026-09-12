/*
Problem: Climbing Stairs

LeetCode:
https://leetcode.com/problems/climbing-stairs/

Goal:
You are climbing a staircase with N steps.

At each step, you can climb either:

    1 step
    OR
    2 steps

Find the total number of distinct ways to reach
the top of the staircase.

Approach:
Dynamic Programming with O(1) Space

Let:

    dp[i] = number of ways to reach stair i

To reach stair i, the final move can be:

    1. A 1-step move from stair i - 1
    2. A 2-step move from stair i - 2

Therefore:

    dp[i] = dp[i - 1] + dp[i - 2]

Base cases:

    dp[0] = 1
    dp[1] = 1

Instead of storing the complete DP array, we only keep
the previous two values:

    prev2 = dp[i - 2]
    prev1 = dp[i - 1]

Then calculate:

    current = prev1 + prev2

and move the variables forward.

Key Insight:

The problem follows the Fibonacci-style recurrence:

    Current ways
    =
    Ways to reach previous stair
    +
    Ways to reach two stairs before

Only the previous two DP states are required, so the
full DP array can be eliminated.

Time Complexity: O(N)

Space Complexity: O(1)

where:
N = number of stairs.
*/

#include <iostream>
using namespace std;

class Solution {
public:

    int climbStairs(int n) {

        // Base cases
        if(n == 0 || n == 1) {
            return 1;
        }

        // Ways to reach stair 0 and stair 1
        int prev2 = 1;
        int prev1 = 1;

        int current = 0;

        // Build the answer from stair 2 to N
        for(int i = 2; i <= n; i++) {

            // Current ways depend on previous two states
            current = prev1 + prev2;

            // Move the DP states forward
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};

int main() {

    int n = 5;

    Solution obj;

    cout << "Number of ways to climb "
         << n << " stairs: "
         << obj.climbStairs(n)
         << endl;

    return 0;
}