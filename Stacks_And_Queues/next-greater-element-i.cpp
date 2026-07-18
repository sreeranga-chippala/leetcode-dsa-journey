/*
Problem: Next Greater Element I

LeetCode:
https://leetcode.com/problems/next-greater-element-i/

Goal:
For each element in nums1, find its next greater
element in nums2.

If no greater element exists, return -1.

Approach:
Monotonic Decreasing Stack + Hash Map

1. Traverse nums2 from left to right.
2. Maintain a decreasing stack.
3. Whenever the current element is greater than
   the top of the stack:
      - The current element is the next greater
        element for the stack top.
      - Store this mapping in a hash map.
4. Push the current element onto the stack.
5. Finally, look up each element of nums1 in the
   hash map.

Key Insight:
Instead of searching for the next greater element
for every query independently, preprocess nums2
once using a monotonic stack.

Time Complexity:
O(n + m)

n = nums2.size()
m = nums1.size()

Space Complexity:
O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        vector<int> ans(nums1.size(), -1);

        stack<int> stk;
        unordered_map<int, int> mp;

        // Build next greater mapping for nums2
        for(int i = 0; i < nums2.size(); i++){

            while(!stk.empty() && nums2[i] > stk.top()){

                mp[stk.top()] = nums2[i];
                stk.pop();
            }

            stk.push(nums2[i]);
        }

        // Answer queries for nums1
        for(int i = 0; i < nums1.size(); i++){

            if(mp.find(nums1[i]) != mp.end()){

                ans[i] = mp[nums1[i]];
            }
        }

        return ans;
    }
};

int main(){

    Solution obj;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = obj.nextGreaterElement(nums1, nums2);

    cout << "Answer: ";

    for(int x : ans){
        cout << x << " ";
    }

    cout << endl;

    return 0;
}