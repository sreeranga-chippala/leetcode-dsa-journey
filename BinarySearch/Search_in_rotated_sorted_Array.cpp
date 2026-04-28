/*
Problem: Search in Rotated Sorted Array

LeetCode: https://leetcode.com/problems/search-in-rotated-sorted-array/

Goal:
Search for a target in a rotated sorted array.
Return its index, or -1 if not found.

Approach:
Binary Search with Sorted Half Detection

- At every step, one half (left or right) is sorted
- Identify the sorted half
- Check if target lies inside that half
    → If yes, move into that half
    → Else, move into the other half

Key Insight:
Even after rotation, at least one side is always sorted.

PseudoCode : 

initialize low = 0
initialize high = n - 1

while low <= high:

    mid = low + (high - low) / 2

    if nums[mid] == target:
        return mid

    if left half is sorted (nums[low] <= nums[mid]):

        if target lies in left half:
            move high = mid - 1
        else:
            move low = mid + 1

    else (right half is sorted):

        if target lies in right half:
            move low = mid + 1
        else:
            move high = mid - 1

return -1

Complexity Analysis : 

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                return mid;
            }

            // Left half is sorted
            if(nums[low] <= nums[mid]){

                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else{

                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout << "Index: "
         << obj.search(nums, target) << endl;

    return 0;
}