/*

Problem: Best Time to Buy and Sell Stock
LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Goal:
Find maximum profit from one buy and one sell.

Approach:
Track minimum price seen so far
and compute possible profit.

Time Complexity: O(n)
Space Complexity: O(1)

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min = prices[0];
        int max = 0;

        for(int i = 0; i < prices.size(); i++){

            // update minimum price
            if(prices[i] < min){
                min = prices[i];
            }

            // calculate profit
            if(prices[i] - min > max){
                max = prices[i] - min;
            }
        }

        return max;
    }
};