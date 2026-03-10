/*
Problem: Rotate Array
LeetCode: https://leetcode.com/problems/rotate-array/

Goal:
Rotate the array to the right by k steps.

Example:
nums = [1,2,3,4,5,6,7]
k = 3

Output:
[5,6,7,1,2,3,4]

Approach:
Use the Reverse Algorithm.

Steps:
1. Reverse the entire array
2. Reverse the first k elements
3. Reverse the remaining elements

optimal : 
Time Complexity: O(n)
Space Complexity: O(1)

Day 7 - LeetCode Journey
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // Function to reverse a portion of the array
    void reverse(vector<int>& nums, int start, int end){

        while(start < end){

            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;

            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k){

        int n = nums.size();

        // Handle k greater than array size
        k = k % n;

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};

int main(){

    Solution obj;

    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    obj.rotate(nums, k);

    cout << "Rotated Array: ";

    for(int num : nums)
        cout << num << " ";

    cout << endl;

    return 0;
}