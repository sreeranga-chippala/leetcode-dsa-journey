/*
Problem: Inorder Predecessor and Successor in a BST

Source : 
https://takeuforward.org/plus/dsa/problems/inorder-successor-and-predecessor-in-bst?source=strivers-a2z-dsa-track

Goal:
Find:

    1. Inorder predecessor of key
    2. Inorder successor of key

Definitions:

Predecessor:
    Largest value strictly smaller than key.

Successor:
    Smallest value strictly greater than key.


Approach:

For Successor:

    If current value > key:

        current can be a successor.

        Store it as successor
        and move LEFT to find a smaller
        possible successor.

    Otherwise:

        current value <= key

        Move RIGHT.


For Predecessor:

    If current value < key:

        current can be a predecessor.

        Store it as predecessor
        and move RIGHT to find a larger
        possible predecessor.

    Otherwise:

        current value >= key

        Move LEFT.


Time Complexity: O(h)

Space Complexity: O(1)

where h = height of the BST.
*/

#include <iostream>
#include <vector>
using namespace std;


// --------------------------------------------------
// Binary Search Tree Node
// --------------------------------------------------

struct TreeNode {

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {

        data = val;
        left = nullptr;
        right = nullptr;
    }
};


// --------------------------------------------------
// Find Inorder Successor
// --------------------------------------------------

int successor(TreeNode* root, int key) {

    // If the tree is empty,
    // successor does not exist.
    if (root == nullptr) {
        return -1;
    }


    // Stores the best successor found so far.
    int succ = -1;


    // Traverse the BST.
    while (root != nullptr) {

        // Current value is greater than key.
        if (root->data > key) {

            // Current node is a possible successor.
            succ = root->data;

            // Try to find a smaller value that is
            // still greater than key.
            root = root->left;
        }

        else {

            // Current value is less than or equal to key.
            // Therefore, move right to find a greater value.
            root = root->right;
        }
    }


    return succ;
}


// --------------------------------------------------
// Find Inorder Predecessor
// --------------------------------------------------

int predecessor(TreeNode* root, int key) {

    // If the tree is empty,
    // predecessor does not exist.
    if (root == nullptr) {
        return -1;
    }


    // Stores the best predecessor found so far.
    int pred = -1;


    // Traverse the BST.
    while (root != nullptr) {

        // Current value is smaller than key.
        if (root->data < key) {

            // Current node is a possible predecessor.
            pred = root->data;

            // Try to find a larger value that is
            // still smaller than key.
            root = root->right;
        }

        else {

            // Current value is greater than or equal to key.
            // Therefore, move left.
            root = root->left;
        }
    }


    return pred;
}


// --------------------------------------------------
// Find Both Predecessor and Successor
// --------------------------------------------------

vector<int> succPredBST(TreeNode* root, int key) {

    // ans[0] = predecessor
    // ans[1] = successor
    //
    // -1 means the value does not exist.
    vector<int> ans(2, -1);


    // Empty tree.
    if (root == nullptr) {
        return ans;
    }


    // Find predecessor.
    ans[0] = predecessor(root, key);


    // Find successor.
    ans[1] = successor(root, key);


    return ans;
}


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
                BST:

                     8
                   /   \
                  4     12
                 / \    / \
                2   6  10  14
               / \      \
              1   3      11

        key = 10

        Predecessor = 8
        Successor   = 11
    */


    // Create the BST.
    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(4);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(3);

    root->right->left->right = new TreeNode(11);


    // Value for which we want predecessor
    // and successor.
    int key = 10;


    // Find both values.
    vector<int> ans = succPredBST(root, key);


    // Print the result.
    cout << "Key: " << key << endl;

    cout << "Predecessor: "
         << ans[0]
         << endl;

    cout << "Successor: "
         << ans[1]
         << endl;


    return 0;
}