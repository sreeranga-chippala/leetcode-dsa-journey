/*
Problem: Maximum Depth of Binary Tree

LeetCode:
https://leetcode.com/problems/maximum-depth-of-binary-tree/

Goal:
Find the maximum depth (height) of a binary tree.

Depth:
Number of nodes along the longest path from
the root node to the deepest leaf node.

Approach:
Recursive Depth First Search (DFS)

- If the current node is null,
  its depth is 0.
- Recursively find the depth of the
  left subtree.
- Recursively find the depth of the
  right subtree.
- The depth of the current node is:

    1 + max(leftDepth, rightDepth)

Key Insight:
The height of a tree depends on the taller
of its two subtrees.

Time Complexity: O(n)

Space Complexity: O(h)

where h is the height of the tree.
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

    int maxDepth(TreeNode* root) {

        // Empty tree has depth 0
        if(root == nullptr){
            return 0;
        }

        // Find depth of left subtree
        int leftDepth = maxDepth(root->left);

        // Find depth of right subtree
        int rightDepth = maxDepth(root->right);

        // Current node contributes one level
        return 1 + max(leftDepth, rightDepth);
    }
};