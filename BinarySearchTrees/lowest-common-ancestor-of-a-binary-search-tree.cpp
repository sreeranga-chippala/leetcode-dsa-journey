/*
Problem: Lowest Common Ancestor of a Binary Search Tree

LeetCode:
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

Goal:
Find the lowest common ancestor (LCA) of two nodes
p and q in a Binary Search Tree.

Approach:
Use the BST property and iterative traversal.

For the current root:

1. If both p and q are smaller than root:
       LCA must be in the left subtree.

2. If both p and q are greater than root:
       LCA must be in the right subtree.

3. Otherwise:
       One node is on the left and the other is on
       the right, or the current root itself is p/q.

       Therefore, current root is the LCA.

PseudoCode : 

if root is NULL:

    return NULL


while root is not NULL:

    if p and q are both smaller than root:

        move root to left subtree


    else if p and q are both greater than root:

        move root to right subtree


    else:

        current root is the LCA

        return root


return NULL


Complexity Analysis : 

Time Complexity: O(h)
Space Complexity: O(1)

where h = height of the BST.
*/

#include <iostream>
using namespace std;


// --------------------------------------------------
// Binary Search Tree Node
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
// Find Lowest Common Ancestor
// --------------------------------------------------

TreeNode* lowestCommonAncestor(
    TreeNode* root,
    TreeNode* p,
    TreeNode* q
) {

    // If the tree is empty,
    // there is no common ancestor.
    if (root == nullptr) {
        return root;
    }


    // Traverse the BST iteratively.
    while (root != nullptr) {

        // If both p and q are smaller than root,
        // their LCA must be somewhere in the left subtree.
        if (p->val < root->val &&
            q->val < root->val) {

            root = root->left;
        }


        // If both p and q are greater than root,
        // their LCA must be somewhere in the right subtree.
        else if (p->val > root->val &&
                 q->val > root->val) {

            root = root->right;
        }


        // Otherwise, the paths to p and q split here.
        //
        // This means the current root is their
        // lowest common ancestor.
        else {

            return root;
        }
    }


    return root;
}


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
                BST:

                     6
                   /   \
                  2     8
                 / \   / \
                0   4 7   9
                   / \
                  3   5

        p = 2
        q = 8

        LCA = 6
    */


    // Create the BST.
    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);


    // Select nodes p and q.
    TreeNode* p = root->left;       // 2
    TreeNode* q = root->right;      // 8


    // Find the Lowest Common Ancestor.
    TreeNode* lca = lowestCommonAncestor(root, p, q);


    // Print the result.
    cout << "Node p: " << p->val << endl;
    cout << "Node q: " << q->val << endl;
    cout << "Lowest Common Ancestor: "
         << lca->val
         << endl;


    return 0;
}