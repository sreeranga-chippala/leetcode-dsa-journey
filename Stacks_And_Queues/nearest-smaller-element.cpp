/*
Problem: Nearest Smaller Element

Goal:
For every element in the array, find the nearest
smaller element on its left.

If no such element exists, return -1.

Approach:
Monotonic Increasing Stack

- Maintain a stack of elements in increasing order.
- For every element:
    - Remove all elements greater than or equal to
      the current element.
    - The remaining top (if any) is the nearest
      smaller element.
    - Push the current element into the stack.

Key Insight:
The stack always stores possible candidates for
the nearest smaller element.

PseudoCode : 

create empty stack

for each element:

    while stack is not empty
    and stack top >= current element:

        pop stack

    if stack is not empty:

        answer = stack top

    else:

        answer = -1

    push current element

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

    vector<int> nearestSmallerElement(vector<int>& arr) {

        int n = arr.size();

        vector<int> ans(n, -1);

        stack<int> stk;

        for(int i = 0; i < n; i++){

            // Remove elements that cannot be the answer
            while(!stk.empty() && arr[i] <= stk.top()){
                stk.pop();
            }

            // Top is the nearest smaller element
            if(!stk.empty()){
                ans[i] = stk.top();
            }

            // Push current element
            stk.push(arr[i]);
        }

        return ans;
    }
};

int main(){

    Solution obj;

    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> ans = obj.nearestSmallerElement(arr);

    cout << "Nearest Smaller Elements: ";

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}