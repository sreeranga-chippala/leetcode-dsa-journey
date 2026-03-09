/*
Problem: Valid Anagram
LeetCode: https://leetcode.com/problems/valid-anagram/

Goal:
Check if two strings are anagrams of each other.

Definition:
Two strings are anagrams if they contain the same characters
with the same frequency.

Example:
s = "anagram"
t = "nagaram"
Output: true

Approach:
1. If lengths are different → not an anagram.
2. Use a hash map to count characters in string s.
3. Traverse string t and decrease counts.
4. If any count becomes negative → not an anagram.

Time Complexity: O(n)
Space Complexity: O(1) (26 characters for lowercase letters)

Day 6 - LeetCode Journey
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:

    bool isAnagram(string s, string t) {

        unordered_map<char,int> um;

        // If lengths differ → impossible to be anagram
        if(s.length() != t.length())
            return false;

        // Count characters in string s
        for(auto c : s){
            um[c]++;
        }

        // Decrease counts using string t
        for(auto c : t){
            um[c]--;

            // If count becomes negative → mismatch
            if(um[c] < 0)
                return false;
        }

        return true;
    }
};

int main(){

    Solution obj;

    string s = "anagram";
    string t = "nagaram";

    if(obj.isAnagram(s,t))
        cout << "True (Anagram)" << endl;
    else
        cout << "False (Not Anagram)" << endl;

    return 0;
}