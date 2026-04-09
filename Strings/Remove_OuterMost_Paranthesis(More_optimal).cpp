/*
Problem: Remove Outermost Parentheses

LeetCode: https://leetcode.com/problems/remove-outermost-parentheses/

Goal:
Remove the outermost parentheses of every primitive substring.

Approach:
Depth Tracking (Optimal)

- Maintain a depth counter (opened)
- Only include parentheses when they are NOT outermost

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int opened = 0;

        for (char c : s) {
            if (c == '(') {
                // If opened > 0, this '(' is NOT an outermost one
                if (opened > 0) result += c;
                opened++;
            } else {
                opened--;
                // If opened > 0, this ')' is NOT an outermost one
                if (opened > 0) result += c;
            }
        }
        return result;
    }
};

int main() {
    Solution obj;

    string s = "(()())(())";

    cout << "Result: "
         << obj.removeOuterParentheses(s) << endl;

    return 0;
}