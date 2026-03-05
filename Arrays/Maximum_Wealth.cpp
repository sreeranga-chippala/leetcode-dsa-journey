/*
Problem: Richest Customer Wealth
LeetCode: https://leetcode.com/problems/richest-customer-wealth/

Pattern: Array Traversal
Time Complexity: O(n*m)
Space Complexity: O(1)

Date: 05-03-2026
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maximum = 0;
        int main_vector_size = accounts.size();
        for(auto i = 0; i < main_vector_size; i++){
            int wealth = 0;
            for(auto j = 0 ; j < accounts[i].size(); j++){
                wealth += accounts[i][j];
            }
            maximum = max(maximum, wealth);
        }
        
        return maximum;
    }
};
int main(){
    vector<vector<int>> gain = {{1,2,3},{3,2,1}};
    Solution obj;
    cout << obj.maximumWealth(gain) << endl;
}