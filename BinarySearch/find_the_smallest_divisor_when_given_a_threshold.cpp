/*
Problem: Find the Smallest Divisor Given a Threshold

LeetCode: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

Goal:
Find the smallest positive divisor such that:

sum(ceil(nums[i] / divisor)) <= threshold

Approach:
Binary Search on Answer

- Minimum divisor = 1
- Maximum divisor = maximum element in array

For each divisor:
    - Compute:
        sum(ceil(nums[i] / divisor))

- If sum <= threshold:
    → divisor works
    → try smaller divisor

- Else:
    → divisor too small
    → try larger divisor

Key Insight:
As divisor increases,
the total sum decreases.

This creates a monotonic pattern suitable
for binary search.

Pseudocode : 

low = 1
high = maximum element

while low <= high:

    mid = low + (high - low) / 2

    calculate:
        sum of ceil(num / mid)

    if sum <= threshold:
        divisor works
        try smaller divisor
        high = mid - 1

    else:
        divisor too small
        try larger divisor
        low = mid + 1

return low


Complexity Analysis : 

Time Complexity: O(n log M)
    n = number of elements
    M = maximum element

Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){

            int mid = low + (high - low) / 2;

            long long current_sum = 0;

            // Calculate sum using current divisor
            for(int num : nums){
                current_sum += (num + mid - 1) / mid;
            }

            // Divisor works
            if(current_sum <= threshold){
                high = mid - 1;
            }
            // Divisor too small
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {1,2,5,9};
    int threshold = 6;

    cout << "Smallest Divisor: "
         << obj.smallestDivisor(nums, threshold) << endl;

    return 0;
}