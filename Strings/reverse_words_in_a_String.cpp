/*
Problem: Reverse Words in a String

LeetCode: https://leetcode.com/problems/reverse-words-in-a-string/

Goal:
Reverse the order of words in a string.
- Remove extra spaces
- Ensure only single spaces between words

Approach:
Two Pointers + In-place Reversal

Steps:
1. Traverse string and extract words while removing extra spaces
2. Reverse each individual word while copying
3. Remove leftover characters at end
4. Reverse entire string to get final answer

Key Insight:
- First reverse each word → then reverse whole string
- This gives words in reversed order without extra space

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        int left = 0;              // Position to write characters
        int right = 0;             // Pointer to scan string
        int n = s.length();

        while(right < n){

            // Step 1: Skip spaces
            while(right < n && s[right] == ' '){
                right++;
            }

            // Step 2: Process a word
            if(right < n){

                // Add space before next word (except first)
                if(left != 0){
                    s[left++] = ' ';
                }

                int start = left;

                // Copy word
                while(right < n && s[right] != ' '){
                    s[left++] = s[right++];
                }

                // Reverse the copied word
                reverse(s.begin() + start, s.begin() + left);
            }
        }

        // Step 3: Remove extra trailing characters
        s.erase(s.begin() + left, s.end());

        // Step 4: Reverse entire string
        reverse(s.begin(), s.end());

        return s;
    }
};

int main(){
    Solution obj;

    string s = "  the sky   is blue  ";

    cout << "Reversed: "
         << obj.reverseWords(s) << endl;

    return 0;
}