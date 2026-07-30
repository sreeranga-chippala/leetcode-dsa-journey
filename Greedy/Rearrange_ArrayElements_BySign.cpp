/*
Problem: Rearrange Array Elements by Sign

LeetCode:
https://leetcode.com/problems/rearrange-array-elements-by-sign/

Goal:
Given an array containing an equal number of
positive and negative integers, rearrange the
array so that positive and negative numbers
appear alternately, starting with a positive
number.

Approach:
Two Pointer Index Placement

- Create a result array of the same size.
- Maintain two indices:
    - positiveIndex = 0 (even positions)
    - negativeIndex = 1 (odd positions)
- Traverse the input array once.
- Place every positive number at the next even
  position.
- Place every negative number at the next odd
  position.

Key Insight:
The problem guarantees an equal number of positive
and negative numbers, so we can directly place
each element into its correct position without
additional checks.

PseudoCode : 

create result array

positiveIndex = 0

negativeIndex = 1

for every element:

    if positive:

        place at positiveIndex

        positiveIndex += 2

    else:

        place at negativeIndex

        negativeIndex += 2

return result

Complexity Analysis : 

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> result(n);

        int positiveIndex = 0;
        int negativeIndex = 1;

        for(int i = 0; i < n; i++){

            if(nums[i] > 0){

                result[positiveIndex] = nums[i];
                positiveIndex += 2;
            }
            else{

                result[negativeIndex] = nums[i];
                negativeIndex += 2;
            }
        }

        return result;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {3,1,-2,-5,2,-4};

    vector<int> ans = obj.rearrangeArray(nums);

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}