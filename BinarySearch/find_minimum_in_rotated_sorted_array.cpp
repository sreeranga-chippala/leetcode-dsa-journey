/*
Problem: Find Minimum in Rotated Sorted Array

LeetCode: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Goal:
Find the minimum element in a rotated sorted array.

Approach:
Binary Search on Rotation Point

- Compare nums[mid] with nums[high]

Case 1:
nums[mid] > nums[high]
→ Minimum lies on right side
→ Move low = mid + 1

Case 2:
nums[mid] <= nums[high]
→ Minimum lies on left side (including mid)
→ Move high = mid

Key Insight:
The minimum element is the point where sorted order breaks.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(low < high){

            int mid = low + (high - low) / 2;

            // Minimum exists on right side
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            // Minimum exists on left side (including mid)
            else{
                high = mid;
            }
        }

        // low == high → minimum element
        return nums[low];
    }
};

int main(){
    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};

    cout << "Minimum Element: "
         << obj.findMin(nums) << endl;

    return 0;
}