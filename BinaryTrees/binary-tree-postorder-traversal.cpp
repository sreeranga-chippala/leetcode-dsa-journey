/*

Problem: Binary Tree Postorder Traversal

LeetCode:
https://leetcode.com/problems/binary-tree-postorder-traversal/

Goal:
Return the postorder traversal of a binary tree.

Postorder Traversal Order:

Left Subtree

↓

Right Subtree

↓

Root

Approach:
Recursive Depth First Search (DFS)

- Traverse the left subtree.
- Traverse the right subtree.
- Visit the current node.

Key Insight:
Postorder processes the root only after both
subtrees have been completely explored.

PseudoCode : 

if node is null:

    return

traverse left subtree

traverse right subtree

visit current node


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

        // Visit left subtree
        helper(node->left, result);

        // Visit right subtree
        helper(node->right, result);

        // Visit current node
        result.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> result;

        helper(root, result);

        return result;
    }
};