/*
Problem: Asteroid Collision

LeetCode:
https://leetcode.com/problems/asteroid-collision/

Goal:
Given asteroids moving in a straight line:

- Positive value  -> moving right
- Negative value  -> moving left

When two asteroids moving in opposite directions
collide:

- Smaller asteroid explodes.
- If both are equal, both explode.
- Asteroids moving in the same direction never collide.

Return the final state of the asteroids.

Approach:
Stack Simulation

- Traverse the asteroid array.
- Push every right-moving asteroid.
- For a left-moving asteroid:
    - While the top of the stack is a smaller
      right-moving asteroid, destroy it.
    - If the stack is empty or the top is
      left-moving, push the current asteroid.
    - If both asteroids are equal in size,
      destroy both.

Key Insight:
Only a right-moving asteroid can collide with
a left-moving asteroid that appears later.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> stk;

        for(int asteroid : asteroids){

            // Right-moving asteroid
            if(asteroid > 0){
                stk.push(asteroid);
            }
            else{

                // Destroy smaller right-moving asteroids
                while(!stk.empty() &&
                      stk.top() > 0 &&
                      stk.top() + asteroid < 0){

                    stk.pop();
                }

                // No collision possible
                if(stk.empty() || stk.top() < 0){
                    stk.push(asteroid);
                }

                // Both explode
                else if(stk.top() + asteroid == 0){
                    stk.pop();
                }

                // If stk.top() > |asteroid|,
                // current asteroid is destroyed.
            }
        }

        // Convert stack to vector
        vector<int> ans(stk.size());

        int i = stk.size() - 1;

        while(!stk.empty()){

            ans[i] = stk.top();
            stk.pop();
            i--;
        }

        return ans;
    }
};

int main(){

    Solution obj;

    vector<int> asteroids = {5, 10, -5};

    vector<int> ans = obj.asteroidCollision(asteroids);

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}