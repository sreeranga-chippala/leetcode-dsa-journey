/*
Problem: Maximum Meetings in One Room

Source : 
    https://takeuforward.org/plus/dsa/problems/n-meetings-in-one-room?source=strivers-a2z-dsa-track

Goal:
Given start and end times of meetings,
schedule the maximum number of meetings
in a single room.

Approach:
Greedy (Earliest Finish Time First)

- Store each meeting as {start, end}.
- Sort meetings by end time.
- Select the first meeting.
- For every remaining meeting:
    - If its start time is greater than the
      end time of the last selected meeting,
      schedule it.

Key Insight:
Choosing the meeting that finishes earliest
leaves the maximum time available for future meetings.

PseudoCode : 

create (start, end) pairs

sort by ending time

select first meeting

for remaining meetings:

    if start > previous meeting end:

        select meeting

return selected meeting count


Complexity Analysis : 

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int>& a,
             const vector<int>& b){

    return a[1] < b[1];
}

class Solution {
public:

    int maxMeetings(vector<int>& start,
                    vector<int>& end){

        int n = start.size();

        vector<vector<int>> meetings(n);

        for(int i = 0; i < n; i++){

            meetings[i] = {start[i], end[i]};
        }

        sort(meetings.begin(),
             meetings.end(),
             compare);

        int meetingCount = 1;

        int lastEndTime = meetings[0][1];

        for(int i = 1; i < n; i++){

            if(meetings[i][0] > lastEndTime){

                meetingCount++;

                lastEndTime = meetings[i][1];
            }
        }

        return meetingCount;
    }
};

int main(){

    Solution obj;

    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};

    cout << obj.maxMeetings(start, end);

    return 0;
}