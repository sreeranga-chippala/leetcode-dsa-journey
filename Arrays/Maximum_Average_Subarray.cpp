/*
Problem: Maximum Average Subarray I
LeetCode: https://leetcode.com/problems/maximum-average-subarray-i/

Goal:
Find the maximum average of any subarray of size k.

Approach:
Fixed Sliding Window

- Calculate sum of first k elements
- Slide window forward:
  add new element, remove old element
- Track maximum sum

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int sum = 0;

        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        int maxsum = sum;

        for(int i = k; i < nums.size(); i++){
            sum += nums[i] - nums[i-k];
            maxsum = max(maxsum, sum);
        }

        return (double)maxsum / k;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    cout << "Maximum Average: "
         << obj.findMaxAverage(nums, k) << endl;

    return 0;
}