/*
Problem: Rotate String
LeetCode: https://leetcode.com/problems/rotate-string/

Goal:
Check if string s can become goal after rotations.

Approach:
1. If lengths differ → false
2. Concatenate string with itself
3. Check if goal is substring of (s + s)

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length())
            return false;

        string s1 = s + s;

        // find returns string::npos if not found
        return s1.find(goal) != string::npos;
    }
};

int main(){
    Solution obj;

    string s = "abcde";
    string goal = "cdeab";

    if(obj.rotateString(s, goal))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}