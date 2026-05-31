/*
Problem: Minimum Number of Days to Make m Bouquets

LeetCode: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

Goal:
Find the minimum number of days needed to make
exactly m bouquets, where each bouquet requires
k adjacent flowers.

Approach:
Binary Search on Answer

- Minimum possible day = minimum bloom day
- Maximum possible day = maximum bloom day

For a given day:
    - Count how many bouquets can be formed
    - Only flowers bloomed on or before that day can be used

If we can make at least m bouquets:
    → day is valid
    → try smaller day

Else:
    → day is too early
    → try larger day

Key Insight:
As days increase, more flowers bloom.
So the ability to make bouquets is monotonic.

Time Complexity: O(n log D)
    n = number of flowers
    D = max bloom day

Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day){

        int flowers = 0;
        int bouquets = 0;

        for(int bloom : bloomDay){

            // Flower has bloomed
            if(bloom <= day){

                flowers++;

                // Enough adjacent flowers for one bouquet
                if(flowers == k){
                    bouquets++;
                    flowers = 0;
                }
            }
            else{
                // Adjacency breaks
                flowers = 0;
            }

            // Early exit
            if(bouquets >= m){
                return true;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        // Impossible case
        if((long long)m * k > n){
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low < high){

            int mid = low + (high - low) / 2;

            if(canMakeBouquets(bloomDay, m, k, mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};

int main(){
    Solution obj;

    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;

    cout << "Minimum Days: "
         << obj.minDays(bloomDay, m, k) << endl;

    return 0;
}