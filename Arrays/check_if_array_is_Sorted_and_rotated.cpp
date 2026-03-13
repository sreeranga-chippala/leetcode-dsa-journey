/*
Problem: Check if Array Is Sorted and Rotated
LeetCode: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

Goal:
Check if the array was originally sorted in non-decreasing order
and then rotated.

Example:
nums = [3,4,5,1,2]

Original sorted array:
[1,2,3,4,5]

After rotation:
[3,4,5,1,2]

Approach:
1. Count how many times nums[i] > nums[i+1].
2. Use modulo to compare the last and first elements.
3. If this happens more than once → not sorted & rotated.

Time Complexity: O(n)
Space Complexity: O(1)

Day 9 - LeetCode Journey
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool check(vector<int>& nums) {

        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){

            if(nums[i] > nums[(i + 1) % n]){
                count++;
            }
        }

        return count <= 1;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {3,4,5,1,2};

    if(obj.check(nums))
        cout << "True (Sorted and Rotated)" << endl;
    else
        cout << "False" << endl;

    return 0;
}