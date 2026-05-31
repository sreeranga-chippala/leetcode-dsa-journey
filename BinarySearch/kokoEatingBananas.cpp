/*
Problem: Koko Eating Bananas

LeetCode: https://leetcode.com/problems/koko-eating-bananas/

Goal:

Find the minimum eating speed (bananas/hour)
such that Koko can finish all bananas within h hours.

Approach:
Binary Search on Answer

- Minimum possible speed = 1
- Maximum possible speed = maximum pile size

For each speed:
    - Calculate total hours needed
    - If hours <= h:
        → speed is valid
        → try smaller speed
    - Else:
        → speed is too slow
        → try larger speed

Key Insight:
The answer space is sorted.

As speed increases:
    required hours decreases.

This monotonic property allows binary search.

PseudoCode : 

initialize low = 1
initialize high = maximum pile size

while low < high:

    mid = low + (high - low) / 2

    calculate total hours needed at speed = mid

    if hours <= h:
        speed works
        try smaller speed
        high = mid

    else:
        speed too slow
        try larger speed
        low = mid + 1

return low


Complexity Analyssis :

Time Complexity: O(n log M)
    n = number of piles
    M = maximum pile size

Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high){

            int mid = low + (high - low) / 2;

            long long hours = 0;

            // Calculate hours needed at current speed
            for(int pile : piles){
                hours += (pile + mid - 1) / mid; // ceil(pile / mid)
            }

            // Speed is sufficient
            if(hours <= h){
                high = mid;
            }
            // Speed is too slow
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};

int main(){
    Solution obj;

    vector<int> piles = {3,6,7,11};
    int h = 8;

    cout << "Minimum Eating Speed: "
         << obj.minEatingSpeed(piles, h) << endl;

    return 0;
}