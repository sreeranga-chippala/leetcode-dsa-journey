/*
Problem: Search in Rotated Sorted Array II

LeetCode: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Goal:
Determine if target exists in a rotated sorted array
that may contain duplicates.

Approach:
Binary Search with Duplicate Handling

- Find mid element
- If target found → return true

- Normally:
    → One half is always sorted
    → Decide which side to search

- Problem with duplicates:
    nums[low] == nums[mid] == nums[high]
    → cannot determine sorted half
    → shrink both sides

Key Insight:
Duplicates can destroy the ability to identify
which half is sorted.

PseudoCode : 

initialize low = 0
initialize high = n - 1

while low <= high:

    mid = low + (high - low) / 2

    if nums[mid] == target:
        return true

    if nums[low] == nums[mid] == nums[high]:
        low++
        high--

    else if left half is sorted:

        if target lies in left half:
            move left
        else:
            move right

    else:

        if target lies in right half:
            move right
        else:
            move left

return false

Complexity Analysis : 

Time Complexity:
- Average: O(log n)
- Worst Case: O(n) (due to duplicates)

Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // Target found
            if(nums[mid] == target){
                return true;
            }

            // Cannot determine sorted half due to duplicates
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
            }

            // Left half is sorted
            else if(nums[low] <= nums[mid]){

                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            // Right half is sorted
            else{

                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;

    cout << (obj.search(nums, target) ? "true" : "false") << endl;

    return 0;
}