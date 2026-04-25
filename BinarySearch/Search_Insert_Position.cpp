/*
Problem: Search Insert Position

LeetCode: https://leetcode.com/problems/search-insert-position/

Goal:
Find the index where the target should be inserted in sorted array.
If target exists → return its index.
Else → return the position where it should be inserted.

Approach:
Binary Search (Lower Bound)

- Search for the first position where nums[i] >= target
- If found → return index
- Else → return insertion position (low)

Key Insight:
After binary search ends, 'low' always points to the correct insert position.

PseudoCode : 

initialize low = 0
initialize high = n - 1

while low <= high:

    mid = low + (high - low) / 2

    if nums[mid] < target:
        low = mid + 1
    else:
        high = mid - 1

return low


Complexity Analysis : 

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        // low is the insertion position
        return low;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {1,3,5,6};
    int target = 5;

    cout << "Insert Position: "
         << obj.searchInsert(nums, target) << endl;

    return 0;
}