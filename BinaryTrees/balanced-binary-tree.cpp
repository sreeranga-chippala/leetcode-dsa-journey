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

PseudoCode : 

if node is null:

    return 0

find left subtree height

find right subtree height

if height difference > 1:

    tree is not balanced

return

1 + maximum(left height, right height)


Complexity Analysis : 

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

// more optimal method

/*
int height(TreeNode* root){
    if(root == nullptr) return 0;

    int left = height(root->left);
    if(left == -1) return -1;

    int right = height(root->right);
    if(right == -1) return -1;

    if(abs(left - right) > 1) return -1;

    return 1 + max(left, right);
}
*/