/*
Problem: Sum of Subarray Ranges

LeetCode:
https://leetcode.com/problems/sum-of-subarray-ranges/

Goal:
For every subarray, calculate:

    (Maximum Element - Minimum Element)

Return the sum of these values over all subarrays.

Approach:
Contribution Technique + Monotonic Stack

Each element contributes in two ways:

1. As the maximum element
2. As the minimum element

Contribution as Maximum:

value × (# subarrays where it is maximum)

Contribution as Minimum:

value × (# subarrays where it is minimum)

Answer:

Total Maximum Contribution
-
Total Minimum Contribution

To find these efficiently, compute:

Maximum:
- Previous Greater Element (PGE)
- Next Greater Element (NGE)

Minimum:
- Previous Smaller Element (PSE)
- Next Smaller Element (NSE)

Key Insight:
Instead of iterating over every subarray,
count how many subarrays use each element
as their maximum and minimum.

PseudoCode :

find Previous Greater Element

find Next Greater Element

find Previous Smaller Element

find Next Smaller Element

answer = 0

for every element:

    maximum contribution =
        leftGreater × rightGreater × value

    minimum contribution =
        leftSmaller × rightSmaller × value

    answer +=
        maximum contribution
        -
        minimum contribution

return answer

Complexity Analysis : 

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> nge(n), pge(n);
        vector<int> nse(n), pse(n);

        stack<int> stk;

        // Next Greater Element
        for(int i = n - 1; i >= 0; i--){

            while(!stk.empty() &&
                  nums[i] >= nums[stk.top()]){
                stk.pop();
            }

            if(stk.empty()){
                nge[i] = n;
            }
            else{
                nge[i] = stk.top();
            }

            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        // Previous Greater Element
        for(int i = 0; i < n; i++){

            while(!stk.empty() &&
                  nums[i] > nums[stk.top()]){
                stk.pop();
            }

            if(stk.empty()){
                pge[i] = -1;
            }
            else{
                pge[i] = stk.top();
            }

            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        // Next Smaller Element
        for(int i = n - 1; i >= 0; i--){

            while(!stk.empty() &&
                  nums[i] <= nums[stk.top()]){
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

        while(!stk.empty()) stk.pop();

        // Previous Smaller Element
        for(int i = 0; i < n; i++){

            while(!stk.empty() &&
                  nums[i] < nums[stk.top()]){
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

        for(int i = 0; i < n; i++){

            long long maxContribution =
                1LL * (nge[i] - i) *
                (i - pge[i]) *
                nums[i];

            long long minContribution =
                1LL * (nse[i] - i) *
                (i - pse[i]) *
                nums[i];

            sum += (maxContribution - minContribution);
        }

        return sum;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {1,2,3};

    cout << obj.subArrayRanges(nums);

    return 0;
}