/*
Problem: Binary Tree Maximum Path Sum

LeetCode:
https://leetcode.com/problems/binary-tree-maximum-path-sum/

Goal:
Find the maximum possible sum of a path
between any two nodes.

A path:

- Can start at any node.
- Can end at any node.
- Must follow parent-child connections.
- Cannot visit the same node twice.

Approach:
Bottom-Up DFS / Tree DP

For every node:

1. Find the maximum downward contribution
   from the left subtree.

2. Find the maximum downward contribution
   from the right subtree.

3. Ignore negative contributions.

4. Calculate the best path passing through
   the current node:

       node + left + right

5. Update the global answer.

6. Return only ONE branch to the parent:

       node + max(left, right)

Why only one branch?

A path returned to the parent cannot split into
both left and right because then the parent would
be connected to two branches and create a path
with more than one direction.

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

    int max_down_path_sum(TreeNode* root,
                          int& ans){

        // Empty subtree
        if(root == nullptr){
            return 0;
        }

        // Maximum contribution from left subtree
        int left =
            max_down_path_sum(root->left, ans);

        // Ignore negative contribution
        if(left < 0){
            left = 0;
        }

        // Maximum contribution from right subtree
        int right =
            max_down_path_sum(root->right, ans);

        // Ignore negative contribution
        if(right < 0){
            right = 0;
        }

        // Best path passing through current node
        int currentPath =
            root->val + left + right;

        // Update global maximum
        ans = max(ans, currentPath);

        // Return only one branch to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root){

        int ans = INT_MIN;

        max_down_path_sum(root, ans);

        return ans;
    }
};