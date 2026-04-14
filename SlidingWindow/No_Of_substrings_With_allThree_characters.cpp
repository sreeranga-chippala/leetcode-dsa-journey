/*
Problem: Number of Substrings Containing All Three Characters

LeetCode: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

Goal:
Count the number of substrings that contain at least one 'a', 'b', and 'c'.

Approach:
Last Seen Index Tracking

- Track last seen index of 'a', 'b', and 'c'
- At each index i:
    → Find minimum of last_a, last_b, last_c
    → All substrings starting from [0 ... min_pos] and ending at i are valid

Key Insight:
If all characters are seen, the earliest valid starting point is:
    min(last_a, last_b, last_c)

Number of valid substrings ending at i = min_pos + 1

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();

        int last_a = -1;
        int last_b = -1;
        int last_c = -1;

        int total = 0;

        for(int i = 0; i < n; i++){

            // Update last seen indices
            if(s[i] == 'a'){
                last_a = i;
            }
            else if(s[i] == 'b'){
                last_b = i;
            }
            else if(s[i] == 'c'){
                last_c = i;
            }

            // If all characters are seen
            if(last_a != -1 && last_b != -1 && last_c != -1){

                // Find earliest index among last occurrences
                int min_pos = last_a;

                if(last_b < min_pos){
                    min_pos = last_b;
                }
                if(last_c < min_pos){
                    min_pos = last_c;
                }

                // Add number of valid substrings ending at i
                total += (min_pos + 1);
            }
        }

        return total;
    }
};

int main(){
    Solution obj;

    string s = "abcabc";

    cout << "Total Substrings: "
         << obj.numberOfSubstrings(s) << endl;

    return 0;
}