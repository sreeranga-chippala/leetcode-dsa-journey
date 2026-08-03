/*
Problem: Binary Tree Level Order Traversal

LeetCode:
https://leetcode.com/problems/binary-tree-level-order-traversal/

Goal:
Return the nodes of the tree level by level
from top to bottom.

Approach:
Breadth First Search (BFS)

- Use a queue to process nodes level by level.
- Store the number of nodes present in the
  current level.
- Remove each node from the queue.
- Add its children to the queue.
- Store all values of the current level
  in a separate vector.

Key Insight:
A queue naturally processes nodes in the
same order they appear level by level.

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

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;

        // Empty tree
        if(root == nullptr){
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            vector<int> currentLevel;

            // Number of nodes in this level
            int size = q.size();

            for(int i = 0; i < size; i++){

                TreeNode* node = q.front();
                q.pop();

                // Store current node
                currentLevel.push_back(node->val);

                // Add left child
                if(node->left != nullptr){
                    q.push(node->left);
                }

                // Add right child
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }

            // Store one complete level
            result.push_back(currentLevel);
        }

        return result;
    }
};