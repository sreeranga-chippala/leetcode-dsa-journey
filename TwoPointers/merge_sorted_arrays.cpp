/*
Problem: Merge Sorted Array

LeetCode: https://leetcode.com/problems/merge-sorted-array/

Goal:
Merge two sorted arrays nums1 and nums2 into nums1 in-place.

Given:
- nums1 has size m + n, with first m elements valid
- nums2 has n elements

Approach:
Two Pointers (from End)

- Start from the end of both arrays
- Compare elements from nums1 and nums2
- Place the larger element at the end of nums1
- Move pointers accordingly
- If nums2 still has elements, copy them

Key Insight:
Filling from the back avoids overwriting elements in nums1.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;          // Pointer for nums1 (valid elements)
        int j = n - 1;          // Pointer for nums2
        int k = m + n - 1;      // Position to fill in nums1

        // Step 1: Compare from the back and place larger element
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }

        // Step 2: If nums2 still has elements, copy them
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }

        // No need to copy remaining nums1 elements
        // because they are already in correct position
    }
};

int main(){
    Solution obj;

    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;

    vector<int> nums2 = {2,5,6};
    int n = 3;

    obj.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for(int num : nums1){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}