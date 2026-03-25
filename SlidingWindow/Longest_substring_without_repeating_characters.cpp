/*
Problem: Longest Substring Without Repeating Characters
LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Goal:
Find the length of the longest substring without repeating characters.

Approach:
Sliding Window + HashMap
- Use two pointers: left and right
- Expand window using right
- If duplicate found, move left pointer
- Track max window size

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> mp;
        int left = 0, maxSize = 0;

        for(int right = 0; right < s.size(); right++){

            char ch = s[right];

            // if duplicate inside window
            if(mp.find(ch) != mp.end() && mp[ch] >= left){
                left = mp[ch] + 1;
            }

            mp[ch] = right;

            maxSize = max(maxSize, right - left + 1);
        }

        return maxSize;
    }
};

int main(){
    Solution obj;
    string s = "abcabcbb";
    cout << "Longest substring length: "
         << obj.lengthOfLongestSubstring(s) << endl;
    return 0;
}