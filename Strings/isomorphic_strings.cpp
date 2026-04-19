/*

Problem: Isomorphic Strings
LeetCode: https://leetcode.com/problems/isomorphic-strings/

Goal:
Check if two strings are isomorphic.

Definition:
Characters in s can be replaced to get t
with a one-to-one mapping.

Approach:
Use two hash maps:
s → t mapping
t → s mapping

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.length() != t.length())
            return false;

        unordered_map<char,char> s2t;
        unordered_map<char,char> t2s;

        for(int i = 0; i < s.length(); i++){

            char cs = s[i];
            char ct = t[i];
            // check consistency
            if(s2t.count(cs) && s2t[cs] != ct)
                return false;

            if(t2s.count(ct) && t2s[ct] != cs)
                return false;

            s2t[cs] = ct;
            t2s[ct] = cs;
        }

        return true;
    }
};

int main(){
    Solution obj;

    string s = "egg";
    string t = "add";

    if(obj.isIsomorphic(s, t))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}