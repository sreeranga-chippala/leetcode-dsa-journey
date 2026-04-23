/*
Problem: Binary Search

LeetCode: https://leetcode.com/problems/binary-search/

Goal:
Search for a target value in a sorted array and return its index.
Return -1 if not found.

Approach:
Binary Search (Iterative)

- Maintain two pointers: low and high
- Find middle index
- Compare target with middle element:
    → If equal → return index
    → If target is larger → search right half
    → If target is smaller → search left half

Key Insight:
Divide search space in half each step.

PseudoCode : 

initialize low = 0
initialize high = n - 1

while low <= high:

    mid = low + (high - low) / 2

    if nums[mid] == target:
        return mid

    else if nums[mid] < target:
        low = mid + 1

    else:
        high = mid - 1

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

            // Avoid overflow
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;

    cout << "Index: "
         << obj.search(nums, target) << endl;

    return 0;
}