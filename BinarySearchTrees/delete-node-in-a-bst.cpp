/*
Problem: Delete Node in a Binary Search Tree

LeetCode:
https://leetcode.com/problems/delete-node-in-a-bst/

Goal:
Delete the node whose value is equal to key
while maintaining the Binary Search Tree property.

BST Property:

        Left Subtree < Root < Right Subtree


Approach:
Iterative BST Traversal + Three Deletion Cases

First, search for the node to delete while keeping
track of its parent.

After finding the node, there are three cases:

Case 1:
    Node has no children.

    Replace the node with NULL.

Case 2:
    Node has exactly one child.

    Replace the node with its only child.

Case 3:
    Node has two children.

    Find the inorder successor.

    The inorder successor is the smallest node
    in the right subtree.

    Copy the successor's value into the current node.

    Then delete the successor node.

Important:
The root node needs special handling because it
does not have a parent.

PseudoCode : 

if root is NULL:

    return root


current = root
parent = NULL


while current is not NULL
      and current value is not key:

    parent = current

    if key < current value:

        current = current left child

    else:

        current = current right child


if current is NULL:

    return root


if current has zero or one child:

    child = current's existing child
            or NULL if it has no child

    if current is root:

        delete current

        return child


    if current is parent's left child:

        parent's left = child

    else:

        parent's right = child

    delete current


else:

    successorParent = current
    successor = current's right child

    while successor has a left child:

        successorParent = successor
        successor = successor's left child


    copy successor value into current


    if successor is successorParent's left child:

        successorParent's left = successor's right child

    else:

        successorParent's right = successor's right child

    delete successor


return root


Complexity Analysis : 

Time Complexity: O(h)
    where h = height of the BST.
Average case: O(log n)
Worst case: O(n)

Space Complexity: O(1)
The solution uses iterative traversal.
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
// Delete a node from the Binary Search Tree
// --------------------------------------------------

TreeNode* deleteNode(TreeNode* root, int key) {

    // If the tree is empty,
    // there is nothing to delete.
    if (root == nullptr) {
        return root;
    }


    // current points to the node
    // that we are currently examining.
    TreeNode* current = root;

    // parent keeps track of the parent
    // of the current node.
    TreeNode* parent = nullptr;


    // --------------------------------------------------
    // Search for the node containing key.
    // --------------------------------------------------

    while (current != nullptr && current->val != key) {

        // Store the current node as the parent
        // before moving to the next node.
        parent = current;


        // If key is smaller,
        // search in the left subtree.
        if (key < current->val) {

            current = current->left;
        }

        // Otherwise, search in the right subtree.
        else {

            current = current->right;
        }
    }


    // --------------------------------------------------
    // Node was not found.
    // --------------------------------------------------

    if (current == nullptr) {
        return root;
    }


    // --------------------------------------------------
    // CASE 1 & CASE 2:
    //
    // The node has zero or one child.
    //
    // If there is no left child,
    // the replacement is the right child.
    //
    // Otherwise, the replacement is the left child.
    // --------------------------------------------------

    if (current->left == nullptr ||
        current->right == nullptr) {

        TreeNode* child = nullptr;


        // If the node has a left child,
        // use it as the replacement.
        if (current->left != nullptr) {

            child = current->left;
        }

        // Otherwise, use the right child.
        else if (current->right != nullptr) {

            child = current->right;
        }


        // --------------------------------------------------
        // Special case:
        // The node being deleted is the root.
        //
        // Since root has no parent, the new root
        // should simply be its child.
        // --------------------------------------------------

        if (parent == nullptr) {

            delete current;

            return child;
        }


        // --------------------------------------------------
        // Connect the parent directly to the child.
        // This removes the current node from the tree.
        // --------------------------------------------------

        if (current == parent->left) {

            parent->left = child;
        }

        else {

            parent->right = child;
        }


        // Delete the current node.
        delete current;
    }


    // --------------------------------------------------
    // CASE 3:
    //
    // The node has two children.
    // --------------------------------------------------

    else {

        // Start from the right subtree.
        TreeNode* succParent = current;
        TreeNode* succ = current->right;


        // Find the smallest node in the
        // right subtree.
        //
        // The smallest node is the leftmost node.
        while (succ->left != nullptr) {

            succParent = succ;
            succ = succ->left;
        }


        // Copy the inorder successor's value
        // into the node that we wanted to delete.
        current->val = succ->val;


        // --------------------------------------------------
        // Remove the successor from its original position.
        //
        // The successor can have a right child,
        // but it cannot have a left child.
        // --------------------------------------------------

        if (succParent->left == succ) {

            succParent->left = succ->right;
        }

        else {

            succParent->right = succ->right;
        }


        // Delete the successor node.
        delete succ;
    }


    // Return the root of the modified BST.
    return root;
}


// --------------------------------------------------
// Inorder Traversal
//
// Left -> Root -> Right
//
// For a BST, inorder traversal prints
// values in sorted order.
// --------------------------------------------------

void inorder(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    inorder(root->left);

    cout << root->val << " ";

    inorder(root->right);
}


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
                Initial BST:

                     5
                   /   \
                  3     6
                 / \     \
                2   4     7

                Delete: 3

        Node 3 has two children.

        Its inorder successor is 4.

        So:

                5
              /   \
             4     6
            /       \
           2         7
    */


    // Create the BST.
    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);


    // Value to delete.
    int key = 3;


    // Print BST before deletion.
    cout << "BST before deletion: ";

    inorder(root);

    cout << endl;


    // Print the value being deleted.
    cout << "Value to delete: "
         << key
         << endl;


    // Delete the node.
    root = deleteNode(root, key);


    // Print BST after deletion.
    cout << "BST after deletion: ";

    inorder(root);

    cout << endl;


    return 0;
}