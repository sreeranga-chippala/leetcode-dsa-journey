/*
Problem: Binary Search Tree Iterator

LeetCode:
https://leetcode.com/problems/binary-search-tree-iterator/

Goal:
Implement an iterator over a Binary Search Tree
that returns the next smallest value each time
next() is called.

BST Property:

    Inorder traversal of a BST gives values
    in ascending order.

    Left → Root → Right

Approach:
Stack + Controlled Inorder Traversal

Instead of storing the complete inorder traversal,
we use a stack.

Initially:
    Push the entire left path from the root.

For next():

    1. Take the top node from the stack.
    2. Remove it from the stack.
    3. If it has a right subtree,
       push the left path of that subtree.
    4. Return the node's value.

The stack always contains the nodes required
to produce the next smallest element.

Time Complexity:

    Constructor:
        O(h)

    next():
        Amortized O(1)

    hasNext():
        O(1)

Space Complexity:
    O(h)

where h = height of the BST.
*/

#include <iostream>
#include <stack>
using namespace std;


// --------------------------------------------------
// Binary Search Tree Node
// --------------------------------------------------

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};


// --------------------------------------------------
// BST Iterator
// --------------------------------------------------

class BSTIterator {

public:

    // Stack stores the nodes that are candidates
    // for the next smallest value.
    stack<TreeNode*> stk;


    // --------------------------------------------------
    // Push the leftmost path of a subtree.
    // --------------------------------------------------

    void pushLeastNumber(TreeNode* root) {

        // Keep moving left while storing every node.
        while (root != nullptr) {

            stk.push(root);

            root = root->left;
        }
    }


    // --------------------------------------------------
    // Constructor
    // --------------------------------------------------

    BSTIterator(TreeNode* root) {

        // The smallest element in a BST is the
        // leftmost node.
        //
        // Therefore, initially push the complete
        // left path from the root.
        pushLeastNumber(root);
    }


    // --------------------------------------------------
    // Return the next smallest element.
    // --------------------------------------------------

    int next() {

        // The top of the stack is the next smallest node.
        TreeNode* temp = stk.top();

        // Remove it from the stack.
        stk.pop();


        // --------------------------------------------------
        // If the node has a right subtree,
        // the next values may come from that subtree.
        //
        // Push the leftmost path of the right subtree.
        // --------------------------------------------------

        if (temp->right != nullptr) {

            pushLeastNumber(temp->right);
        }


        // Return the current node's value.
        return temp->val;
    }


    // --------------------------------------------------
    // Check whether another element exists.
    // --------------------------------------------------

    bool hasNext() {

        // If the stack is not empty,
        // at least one node remains.
        return !stk.empty();
    }
};


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
                BST:

                     7
                   /   \
                  3     15
                 / \      \
                2   5      20
                   /
                  4

        Inorder traversal:

        2 3 4 5 7 15 20
    */


    // Create the BST.
    TreeNode* root = new TreeNode(7);

    root->left = new TreeNode(3);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);

    root->left->right->left = new TreeNode(4);

    root->right->right = new TreeNode(20);


    // Create the BST iterator.
    BSTIterator iterator(root);


    cout << "BST elements in ascending order: ";


    // Keep calling next() while elements remain.
    while (iterator.hasNext()) {

        cout << iterator.next() << " ";
    }


    cout << endl;


    return 0;
}