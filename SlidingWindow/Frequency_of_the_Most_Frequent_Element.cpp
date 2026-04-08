/*
Problem: Frequency of the Most Frequent Element
LeetCode: https://leetcode.com/problems/frequency-of-the-most-frequent-element/

Goal:
Maximize frequency by increasing elements with at most k operations.

Approach:
Sorting + Sliding Window

- Sort array
- Expand window to include elements
- Check cost:
  nums[right] * window_size - sum <= k
- If cost exceeds → shrink window

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        long long sum = 0;
        int left = 0, result = 0;

        for(int right = 0; right < nums.size(); right++){

            sum += nums[right];

            while((long long)nums[right] * (right - left + 1) - sum > k){
                sum -= nums[left];
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,4};
    int k = 5;

    cout << "Max Frequency: "
         << obj.maxFrequency(nums, k) << endl;

    return 0;
}