/*
Problem: Single Number
LeetCode: https://leetcode.com/problems/single-number/

Goal:
Find the element that appears only once.

Approach:
HashMap Frequency Counting

- Count occurrences of each number
- Return the one with frequency = 1

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        for(auto i : mp){
            if(i.second == 1){
                return i.first;
            }
        }

        return 0;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {4,1,2,1,2};

    cout << "Single Number: "
         << obj.singleNumber(nums) << endl;

    return 0;
}