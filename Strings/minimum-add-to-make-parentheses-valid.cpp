/*
Problem: Minimum Add to Make Parentheses Valid

LeetCode:
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

Goal:
Find the minimum number of parentheses that must
be added to make the given string valid.

Approach:
Counter Technique

- required_closed:
    Counts how many ')' are needed to match
    the currently unmatched '('.

- required_open:
    Counts how many '(' must be added because
    an unmatched ')' was encountered.

Traverse the string:
- If '(':
    increase required_closed.
- If ')':
    - If an unmatched '(' exists,
      match it.
    - Otherwise,
      one '(' must be added.

At the end:
- required_closed represents unmatched '('.
- required_open represents unmatched ')'.

Answer:
required_closed + required_open

Key Insight:
Instead of using a stack, maintain only the
number of unmatched opening brackets.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    int minAddToMakeValid(string s) {

        if(s.empty()){
            return 0;
        }

        int required_closed = 0;
        int required_open = 0;

        for(char ch : s){

            // Opening bracket
            if(ch == '('){
                required_closed++;
            }
            else{

                // Match with an opening bracket
                if(required_closed > 0){
                    required_closed--;
                }
                // Need to add an opening bracket
                else{
                    required_open++;
                }
            }
        }

        // Total additions required
        return required_closed + required_open;
    }
};

int main(){

    Solution obj;

    string s = "()))((";

    cout << "Minimum Additions: "
         << obj.minAddToMakeValid(s)
         << endl;

    return 0;
}