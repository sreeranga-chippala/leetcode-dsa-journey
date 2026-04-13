/*
Problem: Assign Cookies
LeetCode: https://leetcode.com/problems/assign-cookies/

Goal:
Assign cookies to children such that:
- Each child i has a greed factor g[i]
- Each cookie j has size s[j]
- A child is satisfied if s[j] >= g[i]

Maximize the number of satisfied children.

Approach:
Greedy + Sorting

- Sort both greed array (g) and cookie array (s)
- Use two pointers:
    i → children
    j → cookies
- Try to satisfy smallest greed child with smallest available cookie
- If cookie satisfies child:
    → assign it and move both pointers
- Else:
    → try next larger cookie

Key Insight:
Always satisfy the least greedy child first using the smallest possible cookie.

Time Complexity: O(n log n + m log m)
Space Complexity: O(1) (ignoring sort space)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int content = 0;
        int i = 0;  // pointer for children
        int j = 0;  // pointer for cookies

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(i < g.size() && j < s.size()){

            // If current cookie can satisfy current child
            if(s[j] >= g[i]){
                content++;
                i++;  // move to next child
            }

            j++;      // always move to next cookie
        }

        return content;
    }
};

int main(){
    Solution obj;

    vector<int> g = {1,2,3};
    vector<int> s = {1,1};

    cout << "Content Children: "
         << obj.findContentChildren(g, s) << endl;

    return 0;
}