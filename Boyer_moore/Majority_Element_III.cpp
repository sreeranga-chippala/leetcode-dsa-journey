/*
Problem: Majority Element II

LeetCode: https://leetcode.com/problems/majority-element-ii/

Goal:
Find all elements appearing more than ⌊n/3⌋ times.

Key Insight:
- At most 2 elements can appear more than n/3 times.

Approach:

Boyer-Moore Voting Algorithm (Extended)

Phase 1:

Find potential candidates

Phase 2:

Verify actual counts

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;

        // Phase 1: Find candidates
        
        for(int num : nums){

            if(num == candidate1){
                count1++;
            }
            else if(num == candidate2){
                count2++;
            }
            else if(count1 == 0){
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 == 0){
                candidate2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }

        // Phase 2: Verify candidates

        vector<int> result;
        count1 = count2 = 0;

        for(int num : nums){
            if(num == candidate1) count1++;
            else if(num == candidate2) count2++;
        }

        if(count1 > nums.size() / 3)
            result.push_back(candidate1);

        if(count2 > nums.size() / 3)
            result.push_back(candidate2);

        return result;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {3,2,3};

    vector<int> result = obj.majorityElement(nums);

    cout << "Majority Elements: ";

    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}