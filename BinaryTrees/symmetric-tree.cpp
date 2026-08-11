/*
Problem: Symmetric Tree

LeetCode:
https://leetcode.com/problems/symmetric-tree/

Goal:
Determine whether a binary tree is symmetric
around its center.

Approach:
Recursive DFS

For two trees to be mirror images:

1. Both nodes must be null
   → They match.

2. One node is null and the other isn't
   → They don't match.

3. Their values must be equal.

4. The left subtree of the first tree must
   mirror the right subtree of the second tree.

5. The right subtree of the first tree must
   mirror the left subtree of the second tree.

Key Insight:

        root
       /    \
      A      B

A and B must be mirror images.

So compare:

A.left  ↔ B.right
A.right ↔ B.left

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

    bool isMirror(TreeNode* root1,
                  TreeNode* root2){

        // Both nodes are null
        if(root1 == nullptr && root2 == nullptr){
            return true;
        }

        // One node is null
        if(root1 == nullptr || root2 == nullptr){
            return false;
        }

        // Values are different
        if(root1->val != root2->val){
            return false;
        }

        // Compare opposite subtrees
        return isMirror(root1->left, root2->right) &&
               isMirror(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root){

        if(root == nullptr){
            return true;
        }

        return isMirror(root->left, root->right);
    }
};