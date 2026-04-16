/*
Problem: Valid Parenthesis String

LeetCode: https://leetcode.com/problems/valid-parenthesis-string/

Goal:
Check if a string with '(', ')', '*' can be valid.

Approach:
Greedy + Range Tracking

- low  → minimum possible open brackets
- high → maximum possible open brackets

Pseudocode:

initialize low = 0
initialize high = 0

for each character c in string:

    if c == '(':
        low++
        high++

    else if c == ')':
        low--
        high--

    else (c == '*'):
        low--      // treat as ')'
        high++     // treat as '('

    if high < 0:
        return false

    if low < 0:
        low = 0

if low == 0:
    return true
else:
    return false


Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for(char c : s){

            if(c == '('){
                low++;
                high++;
            }
            else if(c == ')'){
                low--;
                high--;
            }
            else{ // '*'
                low--;
                high++;
            }

            if(high < 0) return false;

            if(low < 0) low = 0;
        }

        return low == 0;
    }
};

int main(){
    Solution obj;

    string s = "(*)";

    cout << (obj.checkValidString(s) ? "true" : "false") << endl;

    return 0;
}