/*
Problem: Asteroid Collision

LeetCode:
https://leetcode.com/problems/asteroid-collision/

Goal:
Given a list of asteroids moving in a straight line:

- Positive value -> moving right
- Negative value -> moving left

When two asteroids moving in opposite directions collide:

- The smaller asteroid explodes.
- If both have the same size, both explode.
- Asteroids moving in the same direction never collide.

Return the final state of all remaining asteroids.

Approach:
Vector as Stack

- Use a vector as a stack to store surviving asteroids.
- Traverse each asteroid one by one.
- If the current asteroid is moving left and the top
  of the stack is moving right, a collision occurs.
- Continue removing smaller right-moving asteroids
  until:
    - the current asteroid is destroyed,
    - both are destroyed, or
    - no collision is possible.
- Push the current asteroid if it survives.

Key Insight:
Only a right-moving asteroid can collide with a
left-moving asteroid that appears later.

PseudoCode : 

create empty vector as stack

for each asteroid:

    destroyed = false

    while stack is not empty
    and current asteroid moves left
    and top moves right:

        if top is smaller:

            remove top

        else if both are equal:

            remove top
            destroyed = true
            break

        else:

            destroyed = true
            break

    if current asteroid is not destroyed:

        push it into stack

return stack

Complexity Analysis : 

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> asteroidCollision(vector<int>& arr) {

        vector<int> stk;

        for(int ast : arr){

            bool destroyed = false;

            // Resolve all possible collisions
            while(!stk.empty() &&
                  ast < 0 &&
                  stk.back() > 0){

                // Top asteroid is smaller
                if(stk.back() < abs(ast)){
                    stk.pop_back();
                    continue;
                }

                // Both have equal size
                else if(stk.back() == abs(ast)){
                    stk.pop_back();
                }

                // Current asteroid is destroyed
                destroyed = true;
                break;
            }

            // Current asteroid survives
            if(!destroyed){
                stk.push_back(ast);
            }
        }

        return stk;
    }
};

int main(){

    Solution obj;

    vector<int> asteroids = {10, 2, -5};

    vector<int> ans = obj.asteroidCollision(asteroids);

    cout << "Remaining Asteroids: ";

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}