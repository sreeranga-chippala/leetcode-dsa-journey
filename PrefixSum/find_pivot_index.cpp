/*

Problem: Find Pivot Index
LeetCode: https://leetcode.com/problems/find-pivot-index/

Goal:
Find the index where the sum of elements on the left
is equal to the sum of elements on the right.

Example:
nums = [1,7,3,6,5,6]

Index 3 is pivot:
Left sum  = 1+7+3 = 11
Right sum = 5+6   = 11

Approach:
1. Compute the total sum of the array.
2. Traverse the array while maintaining leftSum.
3. Right sum = totalSum - leftSum - nums[i]
4. If leftSum == rightSum → pivot found.

Time Complexity: O(n)
Space Complexity: O(1)

Day 9 - LeetCode Journey

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int pivotIndex(vector<int>& nums) {

        int totalSum = 0;
        int leftSum = 0;

        // Calculate total sum
        for (int x : nums) {
            totalSum += x;
        }

        // Traverse array
        for (int i = 0; i < nums.size(); i++) {

            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum)
                return i;

            leftSum += nums[i];
        }

        return -1;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1,7,3,6,5,6};

    cout << "Pivot Index: "
         << obj.pivotIndex(nums) << endl;

    return 0;
}