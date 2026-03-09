/*
Problem: Contains Duplicate
LeetCode: https://leetcode.com/problems/contains-duplicate/

Goal:
Check if an array contains duplicate elements.

Example:
nums = [1,2,3,1]
Output: true

Approach:
Use an unordered_set to store elements.

Steps:
1. Traverse the array.
2. Check if element already exists in the set.
3. If yes → duplicate found.
4. Otherwise insert it.

Time Complexity: O(n)
Space Complexity: O(n)

Day 6 - LeetCode Journey
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:

    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> us;

        for(int i = 0; i < nums.size(); i++){

            // If element already exists → duplicate
            if(us.count(nums[i]))
                return true;

            us.insert(nums[i]);
        }

        return false;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {1,2,3,1};

    if(obj.containsDuplicate(nums))
        cout << "Duplicate Found" << endl;
    else
        cout << "No Duplicate" << endl;

    return 0;
}