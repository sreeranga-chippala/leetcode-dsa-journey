/*
Problem: Binary Tree Inorder Traversal

LeetCode:
https://leetcode.com/problems/binary-tree-inorder-traversal/

Goal:
Return the inorder traversal of a binary tree.

Inorder Traversal Order:

Left Subtree

↓

Root

↓

Right Subtree

Approach:
Recursive Depth First Search (DFS)

- Traverse the left subtree.
- Visit the current node.
- Traverse the right subtree.

Key Insight:
Inorder always processes the root after
completing the left subtree.

PseudoCode : 

if node is null:

    return

traverse left subtree

visit current node

traverse right subtree


Complexity Analysis : 

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

    void helper(TreeNode* root,
                vector<int>& result){

        if(root == nullptr){
            return;
        }

        // Visit left subtree
        helper(root->left, result);

        // Visit current node
        result.push_back(root->val);

        // Visit right subtree
        helper(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> result;

        helper(root, result);

        return result;
    }
};