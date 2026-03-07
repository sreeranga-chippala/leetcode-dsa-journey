/*
Problem: Move Zeroes
LeetCode: https://leetcode.com/problems/move-zeroes/

Goal:
Move all zeros in the array to the end while maintaining
the relative order of non-zero elements.

Example:
nums = [0,1,0,3,12]

Step 1 → Move non-zero elements forward
[1,3,12,?,?]

Step 2 → Fill remaining positions with zeros
[1,3,12,0,0]

Approach:
1. Maintain a pointer `k` that represents the position
   where the next non-zero element should go.
2. Traverse the array.
3. If the current element is non-zero, place it at index k.
4. Increment k.
5. After the traversal, fill the rest of the array with zeros.

Time Complexity: O(n)
Space Complexity: O(1)  (in-place modification)

Date: Day 4 of LeetCode Journey
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;   // Index to place the next non-zero element

        // Step 1: Move all non-zero elements to the front
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                nums[k] = nums[i];
                k++;
            }
        }

        // Step 2: Fill the remaining positions with zeros
        while(k < n) {
            nums[k] = 0;
            k++;
        }
    }
};

int main() {
    // Note: I used your example [1, 3, 0, 4, 0] for clarity
    vector<int> nums = {1, 3, 0, 4, 0};
    Solution obj;
    
    // Call the function. It modifies 'nums' directly (no return value).
    obj.moveZeroes(nums);
    
    // Print the modified original vector
    cout << "Result: ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}