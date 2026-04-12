/*
Problem: Longest Repeating Character Replacement

LeetCode: https://leetcode.com/problems/longest-repeating-character-replacement/

Goal:
Find the length of the longest substring that can be made of 
same characters after replacing at most k characters.

Approach:
Try All Characters + Sliding Window

- For each character from 'A' to 'Z':
    → Treat it as the target character
    → Use sliding window to find max substring
      where at most k replacements are needed
- Track maximum length across all characters

Key Insight:
Convert problem into:
"Longest substring where at most k chars are not equal to target"

Time Complexity: O(26 * n) ≈ O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        int maxLen = 0;

        // Try each character as the target
        for(char target = 'A'; target <= 'Z'; target++){

            int i = 0;
            int tempK = k;

            for(int j = 0; j < s.length(); j++){

                // If current char is not target → use one replacement
                if(s[j] != target){
                    tempK--;
                }

                // If replacements exceeded, shrink window
                if(tempK < 0){
                    if(s[i] != target){
                        tempK++;
                    }
                    i++;
                }

                // Update max length
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};

int main(){
    Solution obj;

    string s = "AABABBA";
    int k = 1;

    cout << "Max Length: "
         << obj.characterReplacement(s, k) << endl;

    return 0;
}