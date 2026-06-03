/*
Problem: Aggressive Cows

Platform:
SPOJ / Coding Ninjas / Striver DSA Sheet

Goal:
Place k cows in stalls such that the
minimum distance between any two cows
is maximized.

Approach:
Binary Search on Answer

- Sort stall positions
- Search for the maximum possible minimum distance

For a given distance:
    - Greedily place cows
    - If all k cows can be placed:
        → distance is possible
        → try a larger distance
    - Else:
        → distance is too large
        → try a smaller distance

Key Insight:
If distance D works,
then every distance smaller than D also works.

This creates a monotonic pattern.

PseudoCode : 

helper : 
    place first cow at first stall

    cowCount = 1
    lastPosition = first stall

    for each remaining stall:

        if current stall - lastPosition >= distance:

            place cow
            cowCount++
            update lastPosition

            if cowCount == k:
                return true

    return false
Main :
    sort stall positions

    low = 1
    high = last stall - first stall
    answer = -1

    while low <= high:

        mid = low + (high - low) / 2

        if k cows can be placed with distance = mid:
            answer = mid
            try larger distance
            low = mid + 1

        else:
            distance too large
            high = mid - 1

    return answer

Complexity Analysis : 

Time Complexity: O(n log D)
    n = number of stalls
    D = max_position - min_position

Space Complexity: O(1)
*/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    // Helper function to check if we can place 'k' cows with at least 'dist' gap
    bool canPlaceCows(const vector<int>& nums, int k, int dist) {
        int cowCount = 1; // Place the first cow in the first stall
        int lastPosition = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - lastPosition >= dist) {
                cowCount++;          // Place the next cow here
                lastPosition = nums[i]; // Update the last placed cow's position
                
                if (cowCount >= k) {
                    return true; // Successfully placed all k cows
                }
            }
        }
        return false; // Not enough stalls met the distance requirement
    }

public:
    int aggressiveCows(vector<int>& nums, int k) {
        // Step 1: Sort the stall positions
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int low = 1;                          // Minimum possible distance
        int high = nums[n - 1] - nums[0];     // Maximum possible distance
        int ans = 0;
        
        // Step 2: Binary search on the distance
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canPlaceCows(nums, k, mid)) {
                ans = mid;        // 'mid' is feasible, record it
                low = mid + 1;    // Try to find a larger maximum-minimum distance
            } else {
                high = mid - 1;   // 'mid' is too large, reduce the distance
            }
        }
        
        return ans;
    }
};

int main(){
    Solution obj;

    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    cout << "Maximum Minimum Distance: "
         << obj.aggressiveCows(stalls, k) << endl;

    return 0;
}