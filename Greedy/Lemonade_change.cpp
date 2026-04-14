/*
Problem: Lemonade Change

LeetCode: https://leetcode.com/problems/lemonade-change/

Goal:
Each lemonade costs $5.
Customers pay with $5, $10, or $20 bills.

Return true if you can provide correct change to every customer.

Approach:
Greedy (Prioritize Larger Change First)

- Track count of $5 and $10 bills
- For each customer:
    → If $5: just take it
    → If $10: give one $5
    → If $20:
        Prefer giving ($10 + $5) instead of (3 × $5)
        because $5 bills are more flexible for future use

Key Insight:
Always preserve smaller denominations ($5) when possible.

PseudoCode:

if bill == 5:
    five++

elif bill == 10:
    if five == 0 → return false
    five--, ten++

elif bill == 20:
    if ten > 0 and five > 0:
        ten--, five--
    elif five >= 3:
        five -= 3
    else:
        return false

Complexity Analysis: 

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0;   // Count of $5 bills
        int ten = 0;    // Count of $10 bills

        for(int bill : bills){

            if(bill == 5){
                five++;   // No change needed
            }
            else if(bill == 10){

                // Need to give $5 as change
                if(five == 0) return false;

                five--;
                ten++;
            }
            else if(bill == 20){

                // Prefer giving $10 + $5
                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                }
                // Otherwise give 3 × $5
                else if(five >= 3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};

int main(){
    Solution obj;

    vector<int> bills = {5,5,5,10,20};

    cout << "Can Provide Change: "
         << (obj.lemonadeChange(bills) ? "true" : "false") << endl;

    return 0;
}