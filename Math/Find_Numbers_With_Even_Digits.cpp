/*
Problem: Find Numbers with Even Number of Digits
LeetCode: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

Approach :
1. Traverse the array of numbers.
2. For each number, count how many digits it contains.
3. If the digit count is even, increase the counter.
4. Return the final count.

Example:

nums = [12,345,2,6,7896]

12   -> 2 digits (even)
345  -> 3 digits (odd)
2    -> 1 digit  (odd)
6    -> 1 digit  (odd)
7896 -> 4 digits (even)

Output = 2

Time Complexity: O(n * d)
n = number of elements
d = number of digits in each number

Space Complexity: O(1)
No extra space used.


*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    int findNumbers(vector<int>& nums) {
        
        int count = 0;


        for(auto num : nums){

            int digit_count = 0;


            while(num != 0){
                num = num / 10;   
                digit_count++;    
            }


            if(digit_count % 2 == 0){
                count++;
            }
        }

        return count;
    }
};
int main(){

    vector<int> gain = {12, 345, 2, 6, 7896};
    Solution obj;
    cout << obj.findNumbers(gain) << endl;
}
