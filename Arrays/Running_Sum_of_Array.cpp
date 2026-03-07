/*
Problem: Running Sum of 1D Array
LeetCode: https://leetcode.com/problems/running-sum-of-1d-array/

Approach:
The running sum of an array means each element at index i
contains the sum of all elements from index 0 to i.

Example:
nums = [1,2,3,4]

Running sum calculation:
1
1 + 2 = 3
3 + 3 = 6
6 + 4 = 10

Output = [1,3,6,10]

Steps:
1. Create a result vector with the same size as the input array.
2. Maintain a variable `sum` to store cumulative sum.
3. Traverse the array.
4. Add current element to `sum`.
5. Store the updated sum in the result vector.

Time Complexity: O(n)
Space Complexity: O(n)

Date: Day 3 of LeetCode Journey
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<int> runningSum(vector<int>& nums) {

        // Create result array with same size as input
        vector<int> result(nums.size(), 0);

        // Variable to store cumulative sum
        int sum = 0;

        // Traverse the input array
        for(int i = 0; i < nums.size(); i++){

            // Add current element to cumulative sum
            sum += nums[i];

            // Store running sum at index i
            result[i] = sum;
        }

        // Return the running sum array
        return result;
    }
};

int main() {
    vector<int> gain = {12, 345, 2, 6, 7896};
    Solution obj;
    
    // Capture the returned vector
    vector<int> result = obj.runningSum(gain);
    
    // Loop through the result to print it
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}