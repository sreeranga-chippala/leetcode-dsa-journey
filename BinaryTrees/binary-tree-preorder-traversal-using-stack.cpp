/*
Problem: Binary Tree Preorder Traversal

LeetCode:
https://leetcode.com/problems/binary-tree-preorder-traversal/

Goal:
Return the preorder traversal of a binary tree.

Traversal Order:

Root

↓

Left

↓

Right

Approach:
Iterative DFS using Stack

- Push the root node.
- Repeatedly:
    - Pop the top node.
    - Visit it.
    - Push its right child.
    - Push its left child.

The left child is pushed after the right child
so that it is processed first (LIFO property).

Key Insight:
A stack processes the most recently added node first,
so pushing the right child before the left child
preserves preorder traversal.

PseudoCode : 

if tree is empty:

    return empty result

push root

while stack is not empty:

    pop node

    visit node

    push right child

    push left child

return result


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

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> result;

        if(root == nullptr){
            return result;
        }

        stack<TreeNode*> stk;

        stk.push(root);

        while(!stk.empty()){

            TreeNode* current = stk.top();
            stk.pop();

            // Visit current node
            result.push_back(current->val);

            // Push right child first
            if(current->right != nullptr){
                stk.push(current->right);
            }

            // Push left child second
            if(current->left != nullptr){
                stk.push(current->left);
            }
        }

        return result;
    }
};