/*
Problem: Kth Smallest Element in a BST

LeetCode:
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Goal:
Find the kth smallest element in a Binary Search Tree.

Key Property:

Inorder traversal of a BST:

    Left -> Root -> Right

produces the values in sorted ascending order.

Therefore:

    1st visited node = smallest
    2nd visited node = 2nd smallest
    ...
    kth visited node = kth smallest

Approach:
Recursive Inorder Traversal

Variables:

    count:
        Keeps track of the current position
        in the inorder traversal.

    ans:
        Stores the kth smallest value.

During inorder traversal:

    1. Traverse left subtree.
    2. Check whether current node is the kth node.
    3. Increment count.
    4. Traverse right subtree.

Time Complexity: O(n)

Space Complexity: O(h)

where h = height of the BST.
The recursive call stack can contain
up to h nodes.
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
// Inorder Traversal
// --------------------------------------------------

void inorder(TreeNode* root, int k, int& count, int& ans) {

    // Base case:
    // If there is no node, return.
    if (root == nullptr) {
        return;
    }


    // Visit the left subtree first.
    inorder(root->left, k, count, ans);


    // 'count' represents the current position
    // in the sorted inorder traversal.
    if (count == k) {

        ans = root->val;
    }


    // Move to the next position.
    count++;


    // Visit the right subtree.
    inorder(root->right, k, count, ans);
}


// --------------------------------------------------
// Find kth Smallest Element
// --------------------------------------------------

int kthSmallest(TreeNode* root, int k) {

    // If the tree is empty,
    // return -1.
    if (root == nullptr) {
        return -1;
    }


    // Inorder position starts from 1.
    int count = 1;

    // Stores the answer.
    int ans = -1;


    // Perform inorder traversal.
    inorder(root, k, count, ans);


    return ans;
}


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
                BST:

                     5
                   /   \
                  3     6
                 / \
                2   4
               /
              1

        Inorder:
        1 2 3 4 5 6

        k = 3

        Answer = 3
    */


    // Create the BST.
    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);


    // Find the 3rd smallest element.
    int k = 3;


    // Call the function.
    int answer = kthSmallest(root, k);


    // Print the result.
    cout << "K: " << k << endl;

    cout << "Kth Smallest Element: "
         << answer
         << endl;


    return 0;
}