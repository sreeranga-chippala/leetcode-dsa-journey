/*
Problem: Reverse String
LeetCode: https://leetcode.com/problems/reverse-string/

Goal:
Reverse the character array in-place.

Approach:
Two Pointer Technique.

start pointer → beginning
end pointer → last index

Swap elements until pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {

        int start = 0;
        int end = s.size() - 1;

        while(start < end){

            // swap characters
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;

            start++;
            end--;
        }
    }
};