/*

Problem: Count Number of Nice Subarrays

LeetCode: https://leetcode.com/problems/count-number-of-nice-subarrays/

Goal:
Count the number of subarrays with exactly k odd numbers.

Approach:
Sliding Window (Optimized Exact Count)

- Maintain a window with at most k odd numbers
- When odd count reaches k:
    → Start shrinking from left
    → Count valid subarrays ending at current right
- Use currentValidSubArrays to track how many valid windows exist

Key Insight:
Each time we fix a window with k odds,
we can extend it leftwards to form multiple valid subarrays.

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int left = 0;                      // Left pointer of window
        int oddCount = 0;                  // Count of odd numbers in window
        int currentValidSubArrays = 0;     // Count of valid subarrays ending at right
        int totalSubarrays = 0;            // Final result

        for(int right = 0; right < nums.size(); right++){

            // If current element is odd, increment odd count
            if(nums[right] % 2 != 0){
                oddCount++;
                currentValidSubArrays = 0; // Reset since new odd affects window
            }

            // Shrink window while we have exactly k odd numbers
            while(oddCount == k){

                // If removing left reduces odd count
                if(nums[left] % 2 != 0){
                    oddCount--;
                }

                left++;                    // Move left pointer
                currentValidSubArrays++;  // Count valid subarrays
            }

            // Add all valid subarrays ending at current right
            totalSubarrays += currentValidSubArrays;
        }

        return totalSubarrays;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,1,2,1,1};
    int k = 3;

    cout << "Number of Nice Subarrays: "
         << obj.numberOfSubarrays(nums, k) << endl;

    return 0;
}