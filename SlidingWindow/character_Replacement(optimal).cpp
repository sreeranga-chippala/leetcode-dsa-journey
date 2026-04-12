/*
Problem: Longest Repeating Character Replacement

LeetCode: https://leetcode.com/problems/longest-repeating-character-replacement/

Goal:
Find the length of the longest substring that can be made of 
same characters after replacing at most k characters.

Approach:
Sliding Window + Frequency Array

- Maintain a frequency array of size 26
- Track max frequency (maxFreq) of any character in current window
- If (window_size - maxFreq) > k:
    → shrink window from left
- Return final window size

Key Insight:
We only care about the most frequent character in the window.
Other characters can be replaced using k operations.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        int count[26] = {0};   // Frequency array
        int i = 0, j = 0;
        int maxFreq = 0;

        for(j = 0; j < s.length(); j++){

            // Increase frequency of current character
            count[s[j] - 'A']++;

            // Update max frequency in window
            if(count[s[j] - 'A'] > maxFreq){
                maxFreq = count[s[j] - 'A'];
            }

            // If replacements needed exceed k, shrink window
            if((j - i + 1) - maxFreq > k){
                count[s[i] - 'A']--;
                i++;
            }
        }

        // Final window size
        return j - i;
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