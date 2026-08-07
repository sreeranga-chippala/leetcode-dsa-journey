/*
Problem: Balanced Binary Tree

LeetCode:
https://leetcode.com/problems/balanced-binary-tree/

Goal:
Determine whether a binary tree is height-balanced.

A binary tree is balanced if:

For every node,

| Height of Left Subtree
- Height of Right Subtree |

<= 1

Approach:
Bottom-Up DFS

- Recursively calculate the height of
  the left subtree.
- Recursively calculate the height of
  the right subtree.
- Compute the height difference.
- If the difference is greater than 1,
  the tree is not balanced.
- Return the height of the current node.

Key Insight:
While computing heights, we can simultaneously
check whether every node satisfies the balance
condition.

Time Complexity: O(n)

Space Complexity: O(h)

where:
n = number of nodes
h = height of the tree
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

    int height(TreeNode* root, bool& isBalanced){

        // Empty tree has height 0
        if(root == nullptr){
            return 0;
        }

        // Height of left subtree
        int leftHeight =
            height(root->left, isBalanced);

        // Height of right subtree
        int rightHeight =
            height(root->right, isBalanced);

        // Check balance condition
        if(abs(leftHeight - rightHeight) > 1){
            isBalanced = false;
        }

        // Return current node height
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {

        bool isBalancedTree = true;

        height(root, isBalancedTree);

        return isBalancedTree;
    }
};