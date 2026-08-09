/*
Problem: Binary Tree Zigzag Level Order Traversal

LeetCode:
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Goal:
Traverse a binary tree level by level, but alternate
the direction at every level.

Example:

Level 1 → Left to Right
Level 2 → Right to Left
Level 3 → Left to Right
Level 4 → Right to Left

Approach:
BFS + Queue + Index Placement

- Use a queue to perform normal level-order traversal.
- Maintain a boolean `leftToRight`.
- For every level:
    - Create a vector of size `size`.
    - If traversing left to right:
        place value at index i.
    - Otherwise:
        place value at index size - i - 1.
- Add children normally to the queue.
- Toggle the direction after every level.

Key Insight:
The queue always processes nodes from left to right.
Instead of changing the queue order, we change where
each node's value is placed in the current level.

Time Complexity: O(n)

Space Complexity: O(n)
*/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == nullptr){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){

            int size = q.size();

            // Create space for the current level
            vector<int> temp(size);

            for(int i = 0; i < size; i++){

                TreeNode* current = q.front();
                q.pop();

                int index;

                // Decide where to place the current value
                if(leftToRight){
                    index = i;
                }
                else{
                    index = size - i - 1;
                }

                temp[index] = current->val;

                // Add left child
                if(current->left){
                    q.push(current->left);
                }

                // Add right child
                if(current->right){
                    q.push(current->right);
                }
            }

            // Change direction for next level
            leftToRight = !leftToRight;

            ans.push_back(temp);
        }

        return ans;
    }
};