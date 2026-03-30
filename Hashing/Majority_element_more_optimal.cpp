/*

Problem: Majority Element
LeetCode: https://leetcode.com/problems/majority-element/

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
s
Goal:

Find the element that appears more than n/2 times.
Boyer-Moore Voting Algorithm (Elite solution)
This is the important one.


Idea:

The majority element cancels out all other elements.

Example:

[2,2,1,1,1,2,2]

Think of it like voting.

candidate = 2
count = 1

Next element:

2 → count = 2

Next:

1 → count = 1

Next:

1 → count = 0

Reset candidate.

Continue until the end.

The remaining candidate is the majority element.

Time Complexity: O(n)
Space Complexity: O(1)

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for(int num : nums){
            if(count == 0){
                candidate = num;
            }
            if(num == candidate){
                count++;
            }
            else{
                count --;
            }
        }
        return candidate;
    }
};