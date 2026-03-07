/*
Problem: Palindrome Number
LeetCode: https://leetcode.com/problems/palindrome-number/

Goal:
Determine whether an integer is a palindrome.

A palindrome number reads the same forward and backward.

Example:
121  -> palindrome
123  -> not palindrome

Approach:
1. Store the original number.
2. Reverse the digits of the number.
3. Compare the reversed number with the original number.
4. If they are equal → palindrome.

Special Case:
Negative numbers cannot be palindromes.

Example:
x = 121

Reverse process:
digit = 1 → reversed = 1
digit = 2 → reversed = 12
digit = 1 → reversed = 121

Compare:
121 == 121 → true

Time Complexity: O(d)
d = number of digits

Space Complexity: O(1)

Date: Day 4 of LeetCode Journey
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    bool isPalindrome(int x) {

        long long original = x;
        long long reversed = 0;
        long long digit;

        // Negative numbers are not palindrome
        if(x < 0)
            return false;

        // Reverse the digits
        while(x != 0){

            digit = x % 10;
            reversed = reversed * 10 + digit;
            x = x / 10;
        }

        // Compare original and reversed numbers
        return original == reversed;
    }
};

int main(){
    Solution obj;
    cout << obj.isPalindrome(121) << endl;
}