/*
Problem: Two Sum (Optimal)
LeetCode: https://leetcode.com/problems/two-sum/

Approach:
Use a hash map to store numbers and their indices.
For each number:
    complement = target - nums[i]
If complement exists in map → solution found.

Time Complexity: O(n)
Space Complexity: O(n)

Day 5 - LeetCode Journey
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++){

            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()){
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

int main(){

    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution obj;

    vector<int> result = obj.twoSum(nums, target);

    cout << "Indices: " << result[0] << " " << result[1] << endl;

    return 0;
}