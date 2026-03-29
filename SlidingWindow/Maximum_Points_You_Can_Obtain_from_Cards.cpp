/*
Problem: Maximum Points You Can Obtain from Cards
LeetCode: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

Goal:
Pick exactly k cards from either start or end of array
to maximize total score.

Approach:
1. Take first k elements (initial window)
2. Gradually replace elements from left with elements from right
3. Track maximum sum

Example:
[1,2,3,4,5,6,1], k = 3

Start: [1,2,3]
Then:
[1,2] + [1]
[1] + [6,1]
[6,1] + [5]

Time Complexity: O(k)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int currentSum = 0;
        int n = cardPoints.size();

        // Step 1: take first k elements
        for(int i = 0; i < k; i++){
            currentSum += cardPoints[i];
        }

        int maximumSum = currentSum;

        int left = k - 1;
        int right = n - 1;

        // Step 2: shift window
        while(left >= 0){

            // remove from left
            currentSum -= cardPoints[left];

            // add from right
            currentSum += cardPoints[right];

            // update maximum
            maximumSum = max(maximumSum, currentSum);

            left--;
            right--;
        }

        return maximumSum;
    }
};

int main(){
    Solution obj;

    vector<int> cards = {1,2,3,4,5,6,1};
    int k = 3;

    cout << "Maximum Score: "
         << obj.maxScore(cards, k) << endl;

    return 0;
}