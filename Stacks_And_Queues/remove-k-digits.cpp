/*
Problem: Remove K Digits

LeetCode:
https://leetcode.com/problems/remove-k-digits/

Goal:
Remove exactly k digits from the given number so
that the resulting number is the smallest possible.

Approach:
Greedy + Monotonic Increasing Stack

- Traverse each digit from left to right.
- Maintain a monotonic increasing stack.
- If the current digit is smaller than the stack top,
  remove larger digits while k > 0.
- Push the current digit into the stack.
- If k is still greater than 0 after traversal,
  remove digits from the end (largest remaining).
- Build the answer from the stack.
- Remove leading zeros (which appear as trailing zeros
  before reversing the string).

Key Insight:
A larger digit appearing before a smaller digit
should be removed first because it has a greater
impact on the final number.

PseudoCode :

create empty stack

for each digit:

    while k > 0
    and stack not empty
    and top > current digit:

        pop stack
        k--

    push current digit

while k > 0:

    pop stack
    k--

build answer from stack

remove leading zeros

reverse answer

if answer is empty:

    return "0"

return answer

Complexity Analysis : 

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:

    string removeKdigits(string num, int k) {

        stack<char> stk;

        int n = num.length();

        // Build a monotonic increasing stack
        for(int i = 0; i < n; i++){

            while(k > 0 &&
                  !stk.empty() &&
                  stk.top() > num[i]){

                stk.pop();
                k--;
            }

            stk.push(num[i]);
        }

        // Remove remaining digits from the end
        while(k > 0){

            stk.pop();
            k--;
        }

        string ans = "";

        // Stack -> String
        while(!stk.empty()){

            ans.push_back(stk.top());
            stk.pop();
        }

        // Remove leading zeros
        // (currently trailing because string is reversed)
        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }
};

int main(){

    Solution obj;

    string num = "1432219";
    int k = 3;

    cout << obj.removeKdigits(num, k);

    return 0;
}