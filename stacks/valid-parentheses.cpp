/*
Problem: Valid Parentheses

LeetCode:
https://leetcode.com/problems/valid-parentheses/

Goal:
Determine whether the given string of parentheses
is valid.

A string is valid if:
- Every opening bracket has a corresponding closing bracket.
- Brackets are closed in the correct order.
- Every closing bracket matches the most recent unmatched opening bracket.

Approach:
Stack

- Traverse the string from left to right.
- Push every opening bracket onto the stack.
- For every closing bracket:
    - If the stack is empty, return false.
    - Pop the top element.
    - Check whether it matches the current closing bracket.
- At the end:
    - If the stack is empty, the string is valid.
    - Otherwise, it is invalid.

Key Insight:
The last opening bracket encountered must be
the first one to be closed (LIFO order),
making a stack the ideal data structure.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:

    bool isValid(string s) {

        stack<char> stk;

        for(char ch : s){

            // Push opening brackets
            if(ch == '(' || ch == '{' || ch == '['){
                stk.push(ch);
            }
            else{

                // No matching opening bracket
                if(stk.empty()){
                    return false;
                }

                char topBracket = stk.top();
                stk.pop();

                // Check matching pair
                if((topBracket == '(' && ch == ')') ||
                   (topBracket == '{' && ch == '}') ||
                   (topBracket == '[' && ch == ']')){
                    continue;
                }

                return false;
            }
        }

        // Stack should be empty
        return stk.empty();
    }
};

int main(){

    Solution obj;

    string s = "()[]{}";

    cout << (obj.isValid(s) ? "Valid" : "Invalid") << endl;

    return 0;
}