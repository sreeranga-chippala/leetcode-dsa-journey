/*

Problem: Largest Odd Number in String
LeetCode: https://leetcode.com/problems/largest-odd-number-in-string/

Goal:
Find the largest odd-number substring from the given number string.

Approach:
Traverse from right to left.
Return substring ending at first odd digit.

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {

        for(int i = num.length() - 1; i >= 0; i--){

            int digit = num[i] - '0';

            // check if odd
            if(digit % 2 != 0){
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};

int main(){
    Solution obj;
    string num = "35427";

    cout << "Largest Odd Substring: "
         << obj.largestOddNumber(num) << endl;

    return 0;
}