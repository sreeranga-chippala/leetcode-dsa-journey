/*
Problem: Max Consecutive Ones III

LeetCode: https://leetcode.com/problems/max-consecutive-ones-iii/

Goal:
Find the maximum number of consecutive 1s in the array 
if you can flip at most k zeros.

Approach:
Sliding Window (Variable Size)

- Expand window using j
- If we encounter 0 → use one flip (k--)
- If flips exceed limit (k < 0):
    → Shrink window from left (i)
    → Restore flip if we remove a zero

Key Insight:
Maintain a valid window where at most k zeros are flipped.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int i = 0;  // Left pointer
        int j;

        for(j = 0; j < nums.size(); j++){

            // If we encounter 0, we use one flip
            if(nums[j] == 0){
                k--;
            }

            // If flips exceeded, shrink window
            if(k < 0){
                // If left element was 0, we regain a flip
                if(nums[i] == 0){
                    k++;
                }
                i++;  // Move left pointer
            }
        }

        // Window size is the answer
        return j - i;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << "Longest Ones: "
         << obj.longestOnes(nums, k) << endl;

    return 0;
}