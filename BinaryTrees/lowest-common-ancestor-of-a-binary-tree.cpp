/*
Problem: Lowest Common Ancestor of a Binary Tree

LeetCode:
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

Goal:
Find the lowest node in the tree that has both
p and q as descendants.

A node can also be an ancestor of itself.

Approach:
Recursive DFS

For every node:

- If the node is null, return null.
- If the node is p or q, return that node.
- Search the left subtree.
- Search the right subtree.

After both searches:

- If left is null → return right.
- If right is null → return left.
- If both are non-null → current node is the LCA.

Key Insight:
If p and q are found in different subtrees,
the current node is their Lowest Common Ancestor.

Time Complexity: O(n)

Space Complexity: O(h)
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

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                    TreeNode* p,
                                    TreeNode* q) {

        // Base case:
        // Empty node OR p/q found
        if(root == nullptr ||
           root == p ||
           root == q){

            return root;
        }

        // Search left subtree
        TreeNode* left =
            lowestCommonAncestor(root->left, p, q);

        // Search right subtree
        TreeNode* right =
            lowestCommonAncestor(root->right, p, q);

        // p and q are not found on the left
        if(left == nullptr){
            return right;
        }

        // p and q are not found on the right
        if(right == nullptr){
            return left;
        }

        // One node found on each side
        return root;
    }
};