/*
Problem: Binary Tree Preorder Traversal

LeetCode:
https://leetcode.com/problems/binary-tree-preorder-traversal/

Goal:
Return the preorder traversal of a binary tree.

Preorder Traversal Order:

Root

↓

Left Subtree

↓

Right Subtree

Approach:
Recursive Depth First Search (DFS)

- Visit the current node.
- Traverse the left subtree.
- Traverse the right subtree.

Key Insight:
Preorder processes the root before visiting
its children.

PseudoCode :

if node is null:

    return

visit current node

traverse left subtree

traverse right subtree

Complexity Analysis : 

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

    void helper(TreeNode* node,
                vector<int>& result){

        if(node == nullptr){
            return;
        }

        // Visit current node
        result.push_back(node->val);

        // Visit left subtree
        helper(node->left, result);

        // Visit right subtree
        helper(node->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> result;

        helper(root, result);

        return result;
    }
};