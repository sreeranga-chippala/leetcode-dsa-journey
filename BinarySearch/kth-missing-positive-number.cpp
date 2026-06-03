/*
Problem: Kth Missing Positive Number

LeetCode:
https://leetcode.com/problems/kth-missing-positive-number/

Goal:
Find the kth missing positive integer from a sorted array.

Approach:
Binary Search on Missing Count

Observation:

For index i:

Expected value = i + 1

Missing numbers before arr[i]:

    arr[i] - (i + 1)

Example:

arr = [2,3,4,7,11]

Index:      0 1 2 3 4
Expected:   1 2 3 4 5
Actual:     2 3 4 7 11

Missing:
2 - 1 = 1
3 - 2 = 1
4 - 3 = 1
7 - 4 = 3
11 - 5 = 6

Use binary search to find the first position
where missing count >= k.

Key Insight:
After binary search:
    low = number of array elements before answer

Answer:
    low + k

PseudoCode : 

low = 0
high = n - 1

while low <= high:

    mid = low + (high - low) / 2

    missing = arr[mid] - (mid + 1)

    if missing < k:
        low = mid + 1
    else:
        high = mid - 1

return low + k


Complexity Analysis : 

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int low = 0;
        int high = arr.size() - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // Missing numbers before arr[mid]
            int missing = arr[mid] - (mid + 1);

            if(missing < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return low + k;
    }
};

int main(){
    Solution obj;

    vector<int> arr = {2,3,4,7,11};
    int k = 5;

    cout << "Kth Missing Positive: "
         << obj.findKthPositive(arr, k) << endl;

    return 0;
}