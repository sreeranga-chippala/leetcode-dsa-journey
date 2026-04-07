/*

Problem: Two Sum (Brute Force)
LeetCode: https://leetcode.com/problems/two-sum/

Approach:
Check every pair of elements using two loops.
If nums[i] + nums[j] == target, return their indices.

Time Complexity: O(n^2)
Space Complexity: O(1)

Day 5 - LeetCode Journey

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){

                if(nums[i] + nums[j] == target){
                    return {j, i};
                }
            }
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