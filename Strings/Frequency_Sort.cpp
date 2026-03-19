/*
Problem: Sort Characters By Frequency
LeetCode: https://leetcode.com/problems/sort-characters-by-frequency/

Goal:
Sort characters in decreasing order of frequency.

Example:
Input: "tree"
Output: "eetr" or "eert"

Approach:
1. Count frequency using HashMap
2. Use Bucket Sort (index = frequency)
3. Build result from highest frequency to lowest

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> mp;
        int maximum = 0;

        // count frequency
        for(char c : s){
            mp[c]++;
            maximum = max(maximum, mp[c]);
        }

        // bucket array
        vector<string> bucket(maximum + 1);

        // fill buckets
        for(auto i : mp){
            bucket[i.second] += string(i.second, i.first);
        }

        // build result
        string result = "";
        for(int i = maximum; i >= 1; i--){
            result += bucket[i];
        }

        return result;
    }
};

int main(){
    Solution obj;
    string s = "tree";

    cout << "Sorted by frequency: "
         << obj.frequencySort(s) << endl;

    return 0;
}