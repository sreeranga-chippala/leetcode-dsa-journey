/*
Problem: Maximum Subarray
LeetCode: https://leetcode.com/problems/maximum-subarray/

Goal:
Find the contiguous subarray with the largest sum.

Approach:
Kadane’s Algorithm

- Keep a running sum
- If sum becomes negative → reset to 0
- Track maximum sum seen so far

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if(nums.empty()) return 0;

        int maximum = nums[0];
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){

            sum += nums[i];

            if(sum > maximum){
                maximum = sum;
            }

            if(sum < 0){
                sum = 0;
            }
        }

        return maximum;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << "Maximum Subarray Sum: "
         << obj.maxSubArray(nums) << endl;

    return 0;
}