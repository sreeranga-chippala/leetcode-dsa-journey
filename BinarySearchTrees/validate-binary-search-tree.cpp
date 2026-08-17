/*
Problem: Validate Binary Search Tree

LeetCode:
https://leetcode.com/problems/validate-binary-search-tree/

Goal:
Determine whether a binary tree is a valid Binary Search Tree.

BST Property:

    Every node must satisfy:

        minimum < node->val < maximum

Approach:
Inorder Traversal + Valid Range

For every node, maintain:

    mini = smallest allowed value
    maxi = largest allowed value

For the current node:

    mini < root->val < maxi

Then update the range:

    Left subtree:

        mini remains the same
        maxi becomes root->val

    Right subtree:

        mini becomes root->val
        maxi remains the same

The bounds are exclusive because
BST values must be strictly smaller or
strictly greater.

Time Complexity: O(n)

Space Complexity: O(h)

where h = height of the tree.
*/

#include <iostream>
#include <climits>
using namespace std;


// --------------------------------------------------
// Binary Tree Node
// --------------------------------------------------

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {

        val = x;
        left = nullptr;
        right = nullptr;
    }
};


// --------------------------------------------------
// Validate BST using Range
// --------------------------------------------------

void inorder(TreeNode* root,
             long mini,
             long maxi,
             bool& ans) {

    // If there is no node,
    // there is nothing to validate.
    if (root == nullptr) {
        return;
    }


    // --------------------------------------------------
    // Validate the left subtree.
    //
    // The upper bound becomes the current node's value.
    // --------------------------------------------------

    inorder(root->left,
            mini,
            root->val,
            ans);


    // --------------------------------------------------
    // Check whether the current node violates
    // the valid range.
    //
    // Valid condition:
    //
    //     mini < root->val < maxi
    //
    // Therefore invalid if:
    //
    //     root->val <= mini
    // OR
    //     root->val >= maxi
    // --------------------------------------------------

    if (mini >= root->val ||
        maxi <= root->val) {

        ans = false;
    }


    // --------------------------------------------------
    // Validate the right subtree.
    //
    // The lower bound becomes the current node's value.
    // --------------------------------------------------

    inorder(root->right,
            root->val,
            maxi,
            ans);
}


// --------------------------------------------------
// Check whether the tree is a valid BST
// --------------------------------------------------

bool isValidBST(TreeNode* root) {

    // Assume the tree is valid initially.
    bool ans = true;


    // An empty tree is a valid BST.
    if (root == nullptr) {
        return ans;
    }


    // Initially, the root can contain
    // any value within the long integer range.
    long mini = LONG_MIN;
    long maxi = LONG_MAX;


    // Validate the entire tree.
    inorder(root, mini, maxi, ans);


    return ans;
}


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
                Tree:

                     5
                   /   \
                  3     7
                 / \   / \
                2   4 6   8

        This is a valid BST.
    */


    // Create the tree.
    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);


    // Check whether the tree is a valid BST.
    bool result = isValidBST(root);


    // Print the result.
    if (result) {

        cout << "Valid BST: Yes" << endl;
    }

    else {

        cout << "Valid BST: No" << endl;
    }


    return 0;
}