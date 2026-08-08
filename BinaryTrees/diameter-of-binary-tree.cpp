/*
Problem: Diameter of Binary Tree

LeetCode:
https://leetcode.com/problems/diameter-of-binary-tree/

Goal:
Find the length of the longest path between
any two nodes in a binary tree.

Important:
The diameter is measured in number of EDGES,
not number of nodes.

Approach:
Bottom-Up DFS

For every node:

    left_height  = height of left subtree
    right_height = height of right subtree

The longest path passing through the current node is:

    left_height + right_height

Update the global answer using this value.

Then return the height of the current node:

    1 + max(left_height, right_height)

Key Insight:
The diameter of the tree may pass through any node,
so while calculating the height of every node, we
simultaneously check the longest path passing
through that node.

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

    int height(TreeNode* root, int& ans){

        // Empty tree has height 0
        if(root == nullptr){
            return 0;
        }

        // Find height of left subtree
        int left_height =
            height(root->left, ans);

        // Find height of right subtree
        int right_height =
            height(root->right, ans);

        // Longest path passing through current node
        ans = max(ans,
                  left_height + right_height);

        // Return height of current subtree
        return 1 + max(left_height, right_height);
    }

    int diameterOfBinaryTree(TreeNode* root){

        if(root == nullptr){
            return 0;
        }

        int ans = -1;

        height(root, ans);

        return ans;
    }
};