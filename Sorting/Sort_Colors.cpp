/*
Problem: Sort Colors
LeetCode: https://leetcode.com/problems/sort-colors/

Goal:
Sort the array containing only 0,1,2.

My Approach:
Bubble Sort.

Idea:
Repeatedly swap adjacent elements
if they are in the wrong order.

Time Complexity: O(n²)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        // bubble sort
        for(int i = n-1; i >= 1; i--){

            bool is_sorted = true;

            for(int j = 0; j <= i-1; j++){

                if(nums[j] > nums[j+1]){

                    // swap elements
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;

                    is_sorted = false;
                }
            }

            // if already sorted stop early
            if(is_sorted) break;
        }
    }
};