/*
Problem: Longest Common Prefix
LeetCode: https://leetcode.com/problems/longest-common-prefix/

Goal:
Find the longest common prefix among all strings.

Example:
["flower","flow","flight"] → "fl"

Approach:
- Take first string as reference
- Compare character by character with all other strings
- Stop when mismatch occurs

Time Complexity: O(n * m)
n = number of strings
m = length of shortest string

Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) return "";

        for(int i = 0; i < strs[0].size(); i++){

            char c = strs[0][i];

            for(int j = 1; j < strs.size(); j++){

                // mismatch or index out of range
                if(i == strs[j].length() || strs[j][i] != c){
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};

int main(){
    Solution obj;

    vector<string> strs = {"flower","flow","flight"};

    cout << "Longest Common Prefix: "
         << obj.longestCommonPrefix(strs) << endl;

    return 0;
}