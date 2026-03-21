/*
Problem: Missing Number
LeetCode: https://leetcode.com/problems/missing-number/

Goal:
Find the missing number from the range [0, n].

Example:
nums = [3,0,1]

Numbers should be → [0,1,2,3]
Missing → 2

Approach:
Use the formula for sum of first n numbers.

Expected sum:
n * (n + 1) / 2

Actual sum:
sum of elements in array

Missing number = expected_sum - actual_sum

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int missingNumber(vector<int>& nums) {

        long long sum1 = 0;
        long long sum2 = 0;

        // Sum of elements in array
        for(int i = 0; i < nums.size(); i++){
            sum1 += nums[i];
        }

        // Expected sum from 0 to n
        sum2 = nums.size() * (nums.size() + 1) / 2;

        return sum2 - sum1;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {3,0,1};

    cout << "Missing Number: "
         << obj.missingNumber(nums) << endl;

    return 0;
}