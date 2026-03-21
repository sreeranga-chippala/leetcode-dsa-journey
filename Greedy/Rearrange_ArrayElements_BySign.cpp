/*
Problem: Rearrange Array Elements by Sign
LeetCode: https://leetcode.com/problems/rearrange-array-elements-by-sign/

Goal:
Rearrange array so that positive and negative numbers alternate.

Example:
[3,1,-2,-5,2,-4] → [3,-2,1,-5,2,-4]

Approach:
- Use two pointers:
    positive → even indices (0,2,4...)
    negative → odd indices (1,3,5...)
- Place numbers accordingly

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> result(nums.size(), 0);

        int positive = 0; // even index
        int negative = 1; // odd index

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] > 0){
                result[positive] = nums[i];
                positive += 2;
            }
            else{
                result[negative] = nums[i];
                negative += 2;
            }
        }

        return result;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {3,1,-2,-5,2,-4};

    vector<int> result = obj.rearrangeArray(nums);

    cout << "Rearranged Array: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}