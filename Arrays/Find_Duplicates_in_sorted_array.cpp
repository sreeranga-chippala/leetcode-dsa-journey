/*
Problem: Remove Duplicates from Sorted Array
LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Goal:
Remove duplicates in-place from a sorted array and return
the number of unique elements.

Example:
nums = [1,1,2]

After removal:
[1,2,_]

Return = 2

Approach (Two Pointer Technique):
i → position of last unique element
j → scans the array

Steps:
1. Start i at index 0
2. Traverse with j
3. If nums[j] != nums[i]
      move i forward
      copy nums[j] to nums[i]

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int removeDuplicates(vector<int>& nums) {

        int i = 0;

        for(int j = 1; j < nums.size(); j++){

            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {1,1,2};

    int k = obj.removeDuplicates(nums);

    cout << "Unique Count: " << k << endl;

    cout << "Array after removing duplicates: ";
    for(int i = 0; i < k; i++)
        cout << nums[i] << " ";

    cout << endl;

    return 0;
}