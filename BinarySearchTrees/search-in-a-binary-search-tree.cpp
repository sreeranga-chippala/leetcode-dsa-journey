/*

Problem: Search in a Binary Search Tree

LeetCode:
https://leetcode.com/problems/search-in-a-binary-search-tree/

Goal:
Search for a given value in a Binary Search Tree.

Return the subtree rooted at the node
containing the value.

If the value is not found,
return nullptr.

Approach:
Iterative BST Search

BST Property:

Left Subtree

< Root

< Right Subtree

- Compare the current node with the target.
- If equal:
    return current node.
- If target is greater:
    move right.
- Otherwise:
    move left.

Key Insight:
At every step, half of the remaining tree
is discarded because of the BST property.

PseudoCode : 

current = root

while current exists:

    if value found:

        return current

    if target is greater:

        move right

    else:

        move left

return null


Complexity Analysis : 

Time Complexity:O(h)
Space Complexity:O(1)

where h is the tree height.
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

    TreeNode* searchBST(TreeNode* root,
                        int val) {

        TreeNode* current = root;

        while(current != nullptr){

            // Value found
            if(current->val == val){
                return current;
            }

            // Search right subtree
            else if(current->val < val){
                current = current->right;
            }

            // Search left subtree
            else{
                current = current->left;
            }
        }

        // Value not found
        return nullptr;
    }
};