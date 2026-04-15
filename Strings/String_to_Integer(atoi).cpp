/*
Problem: String to Integer (atoi)

LeetCode: https://leetcode.com/problems/string-to-integer-atoi/

Goal:
Convert a string to a 32-bit signed integer.

Rules:
- Ignore leading whitespaces
- Optional '+' or '-' sign
- Read digits until non-digit
- Clamp result within INT_MIN to INT_MAX

Approach:
Parsing + Overflow Check

Steps:
1. Skip leading spaces
2. Detect sign
3. Convert digits one by one
4. Handle overflow before it happens

Key Insight:
Check overflow during building:
    result = result * 10 + digit

Pseudocode:
initialize i = 0
initialize result = 0
initialize sign = +1

skip all leading spaces

if current character is '-' → sign = -1, move i
else if '+' → move i

while current character is a digit:
    digit = current character - '0'

    // check overflow before updating result
    if result > (INT_MAX - digit) / 10:
        if sign == +1 → return INT_MAX
        else → return INT_MIN

    result = result * 10 + digit
    move i forward

return result * sign

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        int n = s.length();
        int sign = 1;
        long result = 0;
        int i = 0;

        // Step 1: Skip leading spaces
        while(i < n && s[i] == ' '){
            i++;
        }

        // Step 2: Handle sign
        if(i < n && s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+'){
            i++;
        }

        // Step 3: Convert digits
        while(i < n && isdigit(s[i])){

            int digit = s[i] - '0';

            result = result * 10 + digit;

            // Step 4: Handle overflow
            if(sign == 1 && result > INT_MAX) return INT_MAX;
            if(sign == -1 && -result < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(result * sign);
    }
};

int main(){
    Solution obj;

    string s = "   -42";

    cout << "Converted Integer: "
         << obj.myAtoi(s) << endl;

    return 0;
}