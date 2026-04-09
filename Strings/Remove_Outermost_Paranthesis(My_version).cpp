/*

Problem: Remove Outermost Parentheses

LeetCode: https://leetcode.com/problems/remove-outermost-parentheses/

Goal:
Given a valid parentheses string, remove the outermost parentheses 
of every primitive substring.

Approach:
Counting + Substring Extraction

- Traverse the string and count opening and closing brackets
- When counts become equal → we found a primitive substring
- Extract substring excluding outermost parentheses:
    → from (start + 1) to (i - 1)
- Reset counters and continue

Key Insight:
Each primitive valid substring has equal '(' and ')'.
Removing outermost means skipping first and last char of that block.

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {

        int i = 0;
        int count_open = 0, count_close = 0;
        int start = 0;

        string result = "";

        while(i < s.size()){

            // Count parentheses
            if(s[i] == '('){
                count_open++;
            }
            else{
                count_close++;
            }

            // When a primitive substring ends
            if(count_open == count_close){

                // Only add if length > 2 (to avoid empty "()")
                if(i - start > 1){
                    result += s.substr(start + 1, i - start - 1);
                }

                // Reset for next primitive
                count_open = count_close = 0;
                start = i + 1;
            }

            i++;
        }

        return result;
    }
};

int main(){
    Solution obj;

    string s = "(()())(())";

    cout << "Result: "
         << obj.removeOuterParentheses(s) << endl;

    return 0;
}