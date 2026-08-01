/*
Problem: Minimum Platforms

source : 
    https://takeuforward.org/plus/dsa/problems/minimum-number-of-platforms-required-for-a-railway?source=strivers-a2z-dsa-track

Goal:
Given arrival and departure times of trains,
find the minimum number of platforms required
so that no train waits.

Approach:
Sorting + Two Pointers

- Sort arrival times.
- Sort departure times.
- Compare the earliest arrival and departure.
- If a train arrives before the earliest departure,
  one more platform is needed.
- Otherwise, a platform becomes free.

Key Insight:
The maximum number of trains present at the station
at any instant equals the minimum number of platforms
required.

PseudoCode : 

sort arrival times

sort departure times

arrivalPointer = 0

departurePointer = 0

currentPlatforms = 0

maximumPlatforms = 0

while arrivals and departures remain:

    if next train arrives before earliest departure:

        currentPlatforms++

        update maximumPlatforms

        move arrival pointer

    else:

        currentPlatforms--

        move departure pointer

return maximumPlatforms


Complexity Analysis : 

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int findPlatform(vector<int>& Arrival,
                     vector<int>& Departure) {

        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());

        int i = 0;
        int j = 0;

        int platformsNeeded = 0;
        int answer = 0;

        while(i < Arrival.size() &&
              j < Departure.size()){

            // Train arrives before earliest departure
            if(Arrival[i] < Departure[j]){

                platformsNeeded++;

                answer = max(answer,
                             platformsNeeded);

                i++;
            }
            else{

                // Train departs
                platformsNeeded--;

                j++;
            }
        }

        return answer;
    }
};

int main(){

    Solution obj;

    vector<int> arrival = {900,940,950,1100,1500,1800};
    vector<int> departure = {910,1200,1120,1130,1900,2000};

    cout << obj.findPlatform(arrival, departure);

    return 0;
}