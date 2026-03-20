/*
Problem: Longest Consecutive Sequence
LeetCode: https://leetcode.com/problems/longest-consecutive-sequence/

Goal:
Find the length of the longest consecutive elements sequence.

Approach:
HashSet

- Insert all elements into set
- Start sequence only if (n-1) is not present
- Expand forward to count streak

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> numset(nums.begin(), nums.end());

        int longest = 0;

        for(int n : numset){

            // start only if it's beginning of sequence
            if(numset.find(n - 1) == numset.end()){

                int currentNum = n;
                int currentStreak = 1;

                while(numset.find(currentNum + 1) != numset.end()){
                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {100,4,200,1,3,2};

    cout << "Longest Consecutive Length: "
         << obj.longestConsecutive(nums) << endl;

    return 0;
}