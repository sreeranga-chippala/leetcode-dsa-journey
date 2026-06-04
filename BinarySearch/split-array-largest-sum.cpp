/*
Problem: Split Array Largest Sum

LeetCode:
https://leetcode.com/problems/split-array-largest-sum/

Goal:
Split the array into exactly k subarrays such that
the largest subarray sum is minimized.

Return that minimum possible largest subarray sum.

Approach:
Binary Search on Answer

- Minimum possible answer:
    max(nums)
    (every subarray must contain at least one element)

- Maximum possible answer:
    sum(nums)
    (entire array as one subarray)

For a given maximum allowed sum:
    - Greedily create subarrays
    - Count how many subarrays are needed

If we can split into <= k subarrays:
    → answer is valid
    → try smaller maximum sum

Else:
    → answer too small
    → try larger maximum sum

Key Insight:
As allowed maximum sum increases,
required number of subarrays decreases.

This monotonic behavior allows binary search.

Time Complexity: O(n log S)
    n = array size
    S = sum of array

Space Complexity: O(1)
*/

#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    // Helper function to check if we can split the array into <= k subarrays
    // such that no subarray sum exceeds 'maxSumLimit'
    bool isPossible(const std::vector<int>& nums, int k, int maxSumLimit) {
        int subarrayCount = 1;
        int currentSum = 0;
        
        for (int num : nums) {
            if (currentSum + num > maxSumLimit) {
                // Start a new subarray
                subarrayCount++;
                currentSum = num;
                
                // If we need more than k subarrays, this maxSumLimit is invalid
                if (subarrayCount > k) {
                    return false;
                }
            } else {
                currentSum += num;
            }
        }
        return true;
    }

public:
    int splitArray(std::vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        
        // Find the range for binary search
        for (int num : nums) {
            low = std::max(low, num); // 'low' is the maximum single element
            high += num;              // 'high' is the sum of all elements
        }
        
        int ans = high;
        
        // Binary search on the "answer space"
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(nums, k, mid)) {
                ans = mid;         // Record the valid minimized largest sum
                high = mid - 1;    // Try to find a smaller valid maximum sum
            } else {
                low = mid + 1;     // 'mid' is too small, increase the limit
            }
        }
        
        return ans;
    }
};