/*
Problem: Jump Game II

LeetCode:
https://leetcode.com/problems/jump-game-ii/

Goal:
Given an array where each element represents the
maximum jump length from that position, find the
minimum number of jumps required to reach the
last index.

Approach:
Greedy

- current_end:
    Represents the farthest index that can be
    reached using the current number of jumps.

- farthest:
    Represents the farthest index that can be
    reached while exploring the current range.

- Traverse the array from left to right.
- Continuously update the farthest reachable index.
- Whenever the current index reaches current_end,
  we have explored all positions for the current
  jump, so:
    - Increase the jump count.
    - Update current_end to farthest.

Key Insight:
Think of each jump as exploring one "level" of
reachable indices, similar to BFS. Once a level
is fully explored, make one jump to the farthest
reachable position.

Time Complexity: O(n)

Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int jump(vector<int>& nums) {

        int current_end = 0;
        int farthest = 0;
        int jumps = 0;

        /*
        Traverse only till n-2 because when we reach
        the last index, no additional jump is needed.
        */
        for(int i = 0; i < nums.size() - 1; i++){

            // Update the farthest reachable index
            farthest = max(farthest, i + nums[i]);

            // End of current jump range
            if(i == current_end){

                jumps++;

                // Next jump covers this range
                current_end = farthest;
            }
        }

        return jumps;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {2,3,1,1,4};

    cout << "Minimum Jumps: "
         << obj.jump(nums);

    return 0;
}