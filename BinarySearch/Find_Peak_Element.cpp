/*

Problem: Find Peak Element

LeetCode: https://leetcode.com/problems/find-peak-element/

Goal:
Find a peak element and return its index.

A peak element is greater than its neighbors.

Approach:
Binary Search on Slope Direction

- Compare nums[mid] with nums[mid + 1]
- If nums[mid] < nums[mid + 1]:
    → increasing slope
    → peak exists on right side
- Else:
    → decreasing slope
    → peak exists on left side (including mid)

Key Insight:
A peak always exists in the direction of the increasing slope.

PseudoCode : 

initialize low = 0
initialize high = n - 1

while low < high:

    mid = low + (high - low) / 2

    if nums[mid] < nums[mid + 1]:
        move to right half
        low = mid + 1

    else:
        move to left half (including mid)
        high = mid

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
    int findPeakElement(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(low < high){

            // Find middle index
            int mid = low + (high - low) / 2;

            // Increasing slope → peak on right side
            if(nums[mid] < nums[mid + 1]){
                low = mid + 1;
            }
            // Decreasing slope → peak on left side (including mid)
            else{
                high = mid;
            }
        }

        // low == high → peak index
        return low;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {1,2,3,1};

    cout << "Peak Index: "
         << obj.findPeakElement(nums) << endl;

    return 0;
}