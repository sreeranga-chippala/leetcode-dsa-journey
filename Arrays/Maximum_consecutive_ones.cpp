/*
Problem: Max Consecutive Ones
LeetCode: https://leetcode.com/problems/max-consecutive-ones/

Goal:
Find the maximum number of consecutive 1's in a binary array.

Example:
nums = [1,1,0,1,1,1]

Output = 3

Approach:
1. Maintain two variables:
   current → current streak of 1's
   maximum → maximum streak found
2. Traverse the array
3. If element is 1 → increase current
4. If element is 0 → reset current

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int findMaxConsecutiveOnes(vector<int>& nums) {

        int current = 0;
        int maximum = 0;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == 1){
                current++;

                if(current > maximum)
                    maximum = current;
            }
            else{
                current = 0;
            }
        }

        return maximum;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {1,1,0,1,1,1};

    cout << "Max Consecutive Ones: "
         << obj.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}