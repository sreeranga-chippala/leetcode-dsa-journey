/*
Problem: Binary Tree Right Side View

LeetCode:
https://leetcode.com/problems/binary-tree-right-side-view/

Goal:
Return the nodes visible when looking at the
binary tree from the right side.

Approach:
BFS / Level Order Traversal

At every level:

- Process all nodes.
- The last node processed at that level is
  the rightmost node.
- Add that node to the answer.

Key Insight:
Because BFS processes each level from left
to right, the LAST node of every level is the
node visible from the right side.

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

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if(root == nullptr){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();

            int lastValue = -1;

            for(int i = 0; i < size; i++){

                TreeNode* current = q.front();
                q.pop();

                // Every node overwrites this value.
                // Therefore, after the loop it contains
                // the last/rightmost node of this level.
                lastValue = current->val;

                if(current->left != nullptr){
                    q.push(current->left);
                }

                if(current->right != nullptr){
                    q.push(current->right);
                }
            }

            // Add rightmost node of this level
            ans.push_back(lastValue);
        }

        return ans;
    }
};