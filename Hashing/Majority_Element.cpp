/*
Problem: Majority Element
LeetCode: https://leetcode.com/problems/majority-element/

Goal:

Find the element that appears more than n/2 times.
Approach:

Use a hash map to count frequency of elements.
If any element appears more than n/2 times,
return that element.

Time Complexity: O(n)
Space Complexity: O(n)

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int,int> um;

        for(int i = 0; i < nums.size(); i++){

            // increase frequency count
            um[nums[i]]++;

            // check majority condition
            if(um[nums[i]] > nums.size()/2){
                return nums[i];
            }
        }

        return -1;
    }
};