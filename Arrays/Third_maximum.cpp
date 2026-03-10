/*
Problem: Third Maximum Number
LeetCode: https://leetcode.com/problems/third-maximum-number/

Goal:
Return the third distinct maximum number in the array.
If it does not exist, return the maximum number.

Example:
nums = [2,2,3,1]

Distinct numbers → [1,2,3]
Third maximum → 1

Approach:
Maintain three variables:
first  → largest
second → second largest
third  → third largest

Traverse the array and update these values.

Time Complexity: O(n)
Space Complexity: O(1)

Day 7 - LeetCode Journey
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:

    int thirdMax(vector<int>& nums) {

        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;

        for(auto num : nums){

            // Skip duplicates
            if(num == first || num == second || num == third)
                continue;

            if(num > first){
                third = second;
                second = first;
                first = num;
            }
            else if(num > second){
                third = second;
                second = num;
            }
            else if(num > third){
                third = num;
            }
        }

        // If third max doesn't exist return first
        return third == LONG_MIN ? first : third;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {2,2,3,1};

    cout << "Third Maximum: "
         << obj.thirdMax(nums) << endl;

    return 0;
}