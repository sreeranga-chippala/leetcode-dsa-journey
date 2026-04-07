/*
Problem: Binary Subarrays With Sum

LeetCode: https://leetcode.com/problems/binary-subarrays-with-sum/

Goal:
Count the number of subarrays with sum exactly equal to goal.

Approach:
Prefix Sum + HashMap

- Maintain running sum (prefix sum)
- If (current_sum - goal) exists in map:
    → Add its frequency to result
- Store frequency of prefix sums

Key Insight:
If current_sum - goal was seen before,
then subarray between those indices has sum = goal.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int current_sum = 0;                      // Running prefix sum
        int total_subArrays = 0;                  // Final result

        unordered_map<int, int> count;
        count[0] = 1;                            // Base case

        for(int num : nums){

            // Update prefix sum
            current_sum += num;

            // Check if (current_sum - goal) exists
            if(count.find(current_sum - goal) != count.end()){
                total_subArrays += count[current_sum - goal];
            }

            // Store current prefix sum frequency
            count[current_sum]++;
        }

        return total_subArrays;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;

    cout << "Number of Subarrays with Sum = " << goal << ": "
         << obj.numSubarraysWithSum(nums, goal) << endl;

    return 0;
}