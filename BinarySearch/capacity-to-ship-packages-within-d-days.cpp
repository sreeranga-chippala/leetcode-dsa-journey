/*
Problem: Capacity To Ship Packages Within D Days

LeetCode:
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

Goal:
Find the minimum ship capacity required to ship
all packages within the given number of days.

Approach:
Binary Search on Answer

- Minimum capacity:
    max(weights)
    (must at least carry the heaviest package)

- Maximum capacity:
    sum(weights)
    (carry everything in one day)

For a given capacity:
    - Simulate shipping
    - Count how many days are needed

If daysNeeded <= days:
    → capacity works
    → try smaller capacity

Else:
    → capacity too small
    → try larger capacity

Key Insight:
As capacity increases,
days needed decreases.

This monotonic behavior enables binary search.

PseudoCode : 

Feasibility Function:
    daysNeeded = 1
    currentLoad = 0

    for each package:

        if currentLoad + package > capacity:
            daysNeeded++
            currentLoad = package

        else:
            currentLoad += package

    return (daysNeeded <= days)

Main Function:

    low = maximum package weight
    high = sum of all package weights

    while low < high:

        mid = low + (high - low) / 2

        if capacity = mid can ship within given days:
            try smaller capacity
            high = mid

        else:
            capacity too small
            low = mid + 1

    return low

Complexity Analysis : 

Time Complexity: O(n log S)
    n = number of packages
    S = sum of all weights

Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool canShip(vector<int>& weights, int mid, int days){
        int daysNeeded = 1; // Start on day 1
        int currentWeight = 0;

        for(int weight : weights) {
            // If adding this package exceeds the ship's capacity (mid)
            if (currentWeight + weight > mid) {
                daysNeeded++;       // Move to the next day
                currentWeight = weight; // Put the package on the new day's ship
            } else {
                currentWeight += weight; // Pack it into the current day's ship
            }
        }

        // Return true if we successfully loaded everything within the target days
        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int weight : weights){
            high += weight;
        }

        int ans = high; // To store our minimum valid capacity

        while(low <= high){
            int mid = low + (high - low)/2;

            if(canShip(weights, mid, days)) {
                ans = mid;        // This capacity works, record it!
                high = mid - 1;   // Try to find an even smaller capacity on the left
            } else {
                low = mid + 1;    // The capacity is too small, check the right side
            }
        }
        return ans;
    }
};