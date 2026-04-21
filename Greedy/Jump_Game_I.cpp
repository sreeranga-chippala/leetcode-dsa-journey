/*
Problem: Jump Game

LeetCode: https://leetcode.com/problems/jump-game/

Goal:
Determine if you can reach the last index.

Approach:
Greedy (Track Maximum Reach)

- Maintain the farthest index we can reach (maxReach)
- Traverse the array:
    → If current index > maxReach → cannot proceed → return false
    → Otherwise update maxReach = max(maxReach, i + nums[i])
- If maxReach reaches or exceeds last index → return true

Key Insight:
We don’t simulate jumps — we track the maximum reachable boundary.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxReach = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){

            // If current index is not reachable
            if(i > maxReach){
                return false;
            }

            // Update maximum reachable index
            maxReach = max(maxReach, i + nums[i]);

            // Early exit if we can reach the end
            if(maxReach >= n - 1){
                return true;
            }
        }

        return true;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {2,3,1,1,4};

    cout << (obj.canJump(nums) ? "true" : "false") << endl;

    return 0;
}