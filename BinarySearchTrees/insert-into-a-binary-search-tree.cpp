/*
Problem: Insert into a Binary Search Tree

LeetCode:
https://leetcode.com/problems/insert-into-a-binary-search-tree/

Goal:
Insert a value into a Binary Search Tree (BST)
and return the root of the modified tree.

BST Property:

        left subtree < root < right subtree

For every node:

    if val < node->val
        go to the left subtree

    if val > node->val
        go to the right subtree

When we reach a nullptr position,
that is the correct place to insert
the new node.

Approach:
Iterative BST Traversal

Instead of using recursion, we maintain a
temporary pointer 'temp' and move down the tree.

Time Complexity:
O(h)

where h = height of the BST.

Average case:
O(log n)

Worst case:
O(n)

Space Complexity:
O(1)

The iterative approach does not use
extra recursion stack space.
*/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If the tree is empty,
        // the new node becomes the root.
        if (root == nullptr) {

            TreeNode* current = new TreeNode(val);

            return current;
        }

        // Start traversal from the root.
        TreeNode* temp = root;

        while (true) {

            // If value is smaller,
            // it belongs in the left subtree.
            if (val < temp->val) {

                // If left position is empty,
                // insert the new node here.
                if (temp->left == nullptr) {

                    temp->left = new TreeNode(val);

                    break;
                }

                // Otherwise continue traversing left.
                temp = temp->left;
            }

            // If value is greater,
            // it belongs in the right subtree.
            else if (val > temp->val) {

                // If right position is empty,
                // insert the new node here.
                if (temp->right == nullptr) {

                    temp->right = new TreeNode(val);

                    break;
                }

                // Otherwise continue traversing right.
                temp = temp->right;
            }

            // Duplicate value.
            else {

                // Do not insert duplicates.
                return root;
            }
        }

        // Root remains unchanged.
        return root;
    }
};