/*
Problem: Single Element in a Sorted Array

LeetCode: https://leetcode.com/problems/single-element-in-a-sorted-array/

Goal:
Find the single element in a sorted array where every other element appears twice.

Approach:
Binary Search + Index Parity

- Pairs appear at (even, odd) indices before the single element
- After the single element, pattern breaks

Steps:
- Make mid even (force it to be start of a pair)
- Compare nums[mid] with nums[mid + 1]
    → If equal → single element is on right side
    → Else → single element is on left side (including mid)

Key Insight:
Pair alignment changes after the single element.

PseudoCode : 

initialize low = 0
initialize high = n - 1

while low < high:

    mid = low + (high - low) / 2

    if mid is odd:
        mid = mid - 1   // make it even

    if nums[mid] == nums[mid + 1]:
        low = mid + 2
    else:
        high = mid

return nums[low]

Complexity Analysis :

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(low < high){

            int mid = low + (high - low) / 2;

            // Ensure mid is even (start of pair)
            if(mid % 2 == 1){
                mid--;
            }

            // If pair is valid, move right
            if(nums[mid] == nums[mid + 1]){
                low = mid + 2;
            }
            else{
                // Pair broken → answer is on left
                high = mid;
            }
        }

        return nums[low];
    }
};

int main(){
    Solution obj;

    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    cout << "Single Element: "
         << obj.singleNonDuplicate(nums) << endl;

    return 0;
}