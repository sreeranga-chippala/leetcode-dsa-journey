/*
Problem: Find the Highest Altitude
LeetCode: https://leetcode.com/problems/find-the-highest-altitude/

Pattern: Prefix Sum / Array Traversal

Time Complexity: O(n)
Space Complexity: O(1)

Date: 04-03-2026
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int current = 0;
        int max_altitude = 0;

        for(int g : gain){
            current += g;
            max_altitude = max(max_altitude, current);
        }

        return max_altitude;
    }
};

int main(){
    vector<int> gain = {-5, 1, 5, 0,-7};
    Solution obj;
    cout << obj.largestAltitude(gain) << endl;
}