/*
Problem: Next Greater Element II

LeetCode:
https://leetcode.com/problems/next-greater-element-ii/

Goal:
For every element in a circular array,
find the first greater element to its right.

If no greater element exists,
return -1.

Approach:
Monotonic Decreasing Stack

- Traverse the array twice (2 * n iterations)
  to simulate circular traversal.
- Maintain a stack of possible next greater elements.
- Remove all elements smaller than or equal to
  the current element.
- The top of the stack (if it exists) is the
  next greater element.
- Push the current element into the stack.

Key Insight:
Traversing twice allows every element to
consider elements at the beginning of the array
after reaching the end.

PseudoCode : 

create answer array filled with -1

create empty stack

for i from (2*n - 1) down to 0:

    current = nums[i % n]

    while stack is not empty
    and current >= stack top:

        pop stack

    if i < n
    and stack is not empty:

        answer[i] = stack top

    push current into stack

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

    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, -1);

        stack<int> stk;

        // Traverse twice to simulate circular array
        for(int i = 2 * n - 1; i >= 0; i--){

            int current_num = nums[i % n];

            // Remove smaller or equal elements
            while(!stk.empty() && current_num >= stk.top()){
                stk.pop();
            }

            // Store answer only during first traversal
            if(i < n && !stk.empty()){
                ans[i] = stk.top();
            }

            // Current element becomes a candidate
            stk.push(current_num);
        }

        return ans;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {1, 2, 1};

    vector<int> ans = obj.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";

    for(int x : ans){
        cout << x << " ";
    }

    cout << endl;
}