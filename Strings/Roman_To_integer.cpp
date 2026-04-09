/*
Problem: Roman to Integer

LeetCode: https://leetcode.com/problems/roman-to-integer/

Goal:
Convert a Roman numeral string into an integer.

Approach:
Greedy + Look Ahead

- Traverse the string from left to right
- Convert each character to its integer value
- If current value < next value:
    → subtract current (e.g., IV → 5 - 1)
- Else:
    → add current

Key Insight:
Roman numerals use subtraction only when a smaller value 
comes before a larger value.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    // Helper function to map Roman character to integer value
    int find_value(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0; // Safe fallback
        }
    }

    int romanToInt(string s) {

        int result = 0;
        int n = s.length();

        for(int i = 0; i < n; i++){

            int current = find_value(s[i]);

            // If next value is greater → subtraction case
            if(i + 1 < n && current < find_value(s[i + 1])){
                result -= current;
            }
            else{
                result += current;
            }
        }

        return result;
    }
};

int main(){
    Solution obj;

    string s = "MCMXCIV"; // Expected: 1994

    cout << "Integer Value: "
         << obj.romanToInt(s) << endl;

    return 0;
}