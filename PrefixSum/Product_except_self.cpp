/*
Problem: Product of Array Except Self
LeetCode: https://leetcode.com/problems/product-of-array-except-self/

Goal:
For each index i, return the product of all elements in the array except nums[i].

Example:
nums = [1,2,3,4]

Output:
[24,12,8,6]

Approach:
Use prefix and suffix products.

Prefix pass:
answer[i] = product of all elements before i.

Suffix pass:
Multiply answer[i] with product of all elements after i.

Time Complexity: O(n)
Space Complexity: O(1) extra (output array not counted)

Day 10 - LeetCode Journey
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // result array
        vector<int> answer(nums.size(), 0);

        int prefix = 1;
        int suffix = 1;

        // prefix traversal
        for(int i = 0; i < nums.size(); i++){

            // store prefix product
            answer[i] = prefix;

            // update prefix
            prefix = prefix * nums[i];
        }

        // suffix traversal
        for(int i = nums.size() - 1; i >= 0; i--){

            // multiply existing prefix with suffix
            answer[i] = answer[i] * suffix;

            // update suffix
            suffix = suffix * nums[i];
        }

        return answer;
    }
};