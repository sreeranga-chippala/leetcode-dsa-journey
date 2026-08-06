/*
Problem: Binary Tree Inorder Traversal

LeetCode:
https://leetcode.com/problems/binary-tree-inorder-traversal/

Goal:
Return the inorder traversal of a binary tree.

Traversal Order:

Left

↓

Root

↓

Right

Approach:
Iterative DFS using Stack

- Start from the root.
- Continuously move to the left child,
  pushing every node into the stack.
- When no left child exists:
    - Pop the top node.
    - Visit it.
    - Move to its right child.
- Repeat until both the stack is empty
  and the current node becomes nullptr.

Key Insight:
The stack stores the path from the root
to the current node, allowing us to return
after finishing the left subtree.

PseudoCode : 

create empty stack

current = root

while current exists OR stack not empty:

    while current exists:

        push current

        move left

    pop stack

    visit node

    move right

return result


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

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> result;

        stack<TreeNode*> stk;

        TreeNode* current = root;

        while(current != nullptr || !stk.empty()){

            // Reach the leftmost node
            while(current != nullptr){

                stk.push(current);

                current = current->left;
            }

            // Visit the leftmost node
            current = stk.top();
            stk.pop();

            result.push_back(current->val);

            // Traverse the right subtree
            current = current->right;
        }

        return result;
    }
};