/*
Problem: Fractional Knapsack

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

Goal:
Given the profit and weight of each item,
maximize the total profit that can be placed
inside a knapsack of limited capacity.

Unlike the 0/1 Knapsack problem,
items can be taken fractionally.

Approach:
Greedy (Profit per Unit Weight)

- Compute the profit per unit weight for each item.
- Sort all items in descending order of
  profit per unit weight.
- Pick the most profitable item first.
- If the entire item fits, take it completely.
- Otherwise, take only the fraction that fits.

Key Insight:
Choosing the item with the highest profit per
unit weight first always produces the maximum
possible profit.

Time Complexity: O(n log n)

Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    double fractionalKnapsack(vector<int>& profits,
                              vector<int>& weights,
                              int capacity) {

        int n = profits.size();

        double totalProfit = 0;

        // {profit per kg, weight}
        vector<pair<double, int>> profitPerKg(n);

        // Compute profit per unit weight
        for(int i = 0; i < n; i++){

            profitPerKg[i].first =
                (double)profits[i] / weights[i];

            profitPerKg[i].second =
                weights[i];
        }

        // Sort by highest profit per kg
        sort(profitPerKg.begin(),
             profitPerKg.end(),
             greater<pair<double, int>>());

        // Pick items greedily
        for(int i = 0; i < n; i++){

            // Entire item fits
            if(profitPerKg[i].second <= capacity){

                totalProfit +=
                    profitPerKg[i].first *
                    profitPerKg[i].second;

                capacity -=
                    profitPerKg[i].second;
            }
            else{

                // Take only the required fraction
                totalProfit +=
                    profitPerKg[i].first *
                    capacity;

                break;
            }
        }

        return totalProfit;
    }
};

int main(){

    Solution obj;

    vector<int> profits = {60, 100, 120};
    vector<int> weights = {10, 20, 30};

    int capacity = 50;

    cout << "Maximum Profit: "
         << obj.fractionalKnapsack(profits,
                                   weights,
                                   capacity);

    return 0;
}