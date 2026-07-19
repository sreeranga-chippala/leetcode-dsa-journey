/*
Problem: Sum of Subarray Minimums

LeetCode:
https://leetcode.com/problems/sum-of-subarray-minimums/

Goal:
Find the sum of the minimum element of every
possible subarray.

Approach:
Monotonic Increasing Stack

For every element, calculate:

1. Previous Smaller Element (PSE)
2. Next Smaller Element (NSE)

Then determine how many subarrays have this
element as their minimum.

Contribution of arr[i]:

arr[i] × (distance to previous smaller)
       × (distance to next smaller)

To correctly handle duplicate values:
- NSE uses >=
- PSE uses >

Key Insight:
Instead of generating all O(n²) subarrays,
compute how many subarrays each element
contributes to as the minimum.

Time Complexity: O(n)

Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> nse(n);
        vector<int> pse(n);

        stack<int> stk;

        // Find Next Smaller Element
        for(int i = n - 1; i >= 0; i--){

            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                stk.pop();
            }

            if(stk.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = stk.top();
            }

            stk.push(i);
        }

        // Clear stack
        while(!stk.empty()){
            stk.pop();
        }

        // Find Previous Smaller Element
        for(int i = 0; i < n; i++){

            while(!stk.empty() && arr[stk.top()] > arr[i]){
                stk.pop();
            }

            if(stk.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = stk.top();
            }

            stk.push(i);
        }

        long long sum = 0;

        // Calculate contribution of every element
        for(int i = 0; i < n; i++){

            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long contribution =
                (left * right) % MOD;

            contribution =
                (contribution * arr[i]) % MOD;

            sum = (sum + contribution) % MOD;
        }

        return sum;
    }
};

int main(){

    Solution obj;

    vector<int> arr = {3,1,2,4};

    cout << obj.sumSubarrayMins(arr);

    return 0;
}