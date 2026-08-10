/*
Problem: Boundary Traversal of Binary Tree

Source :-

    LeetCode : 
    https://leetcode.com/problems/boundary-of-binary-tree/

    (or)

    Strivers A-Z DSA Sheet : 
    https://takeuforward.org/plus/dsa/problems/boundary-traversal?source=strivers-a2z-dsa-track
    

Goal:
Return the boundary nodes of a binary tree
in anti-clockwise order.

Boundary consists of:

1. Root
2. Left boundary (excluding leaves)
3. All leaf nodes
4. Right boundary (excluding leaves),
   added in reverse order

Approach:
Break the problem into three separate traversals.

Key Insight:
The left boundary and right boundary are traversed
differently, while all leaf nodes are collected
using DFS.

PseudoCode : 

if root is null:

    return empty result


if root is not a leaf:

    add root


collect left boundary

    start from root's left

    while node exists:

        if node is not leaf:

            add node

        prefer left child

        otherwise move to right child


collect all leaf nodes using DFS


collect right boundary

    start from root's right

    while node exists:

        if node is not leaf:

            store node temporarily

        prefer right child

        otherwise move to left child


reverse right boundary

add it to answer

return answer


Complexity Analysis : 

Time Complexity: O(n)
Space Complexity: O(h)
                  plus output/storage
*/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:

    // Check whether a node is a leaf
    bool is_leafNode(TreeNode* root){

        return root->left == nullptr &&
               root->right == nullptr;
    }

    // Collect left boundary
    void leftBoundary(TreeNode* root,
                      vector<int>& ans){

        if(root == nullptr){
            return;
        }

        TreeNode* current = root->left;

        while(current != nullptr){

            // Do not add leaf nodes here
            if(!is_leafNode(current)){
                ans.push_back(current->data);
            }

            // Prefer left child
            if(current->left != nullptr){
                current = current->left;
            }
            else{
                // Otherwise move to right child
                current = current->right;
            }
        }
    }

    // Collect right boundary
    void rightBoundaries(TreeNode* root,
                         vector<int>& ans){

        if(root == nullptr){
            return;
        }

        TreeNode* current = root->right;

        vector<int> temp;

        while(current != nullptr){

            // Do not add leaf nodes here
            if(!is_leafNode(current)){
                temp.push_back(current->data);
            }

            // Prefer right child
            if(current->right != nullptr){
                current = current->right;
            }
            else{
                // Otherwise move to left child
                current = current->left;
            }
        }

        // Right boundary must be added bottom-up
        for(int i = temp.size() - 1;
            i >= 0;
            i--){

            ans.push_back(temp[i]);
        }
    }

    // Collect all leaf nodes
    void leafNodes(TreeNode* root,
                   vector<int>& ans){

        if(root == nullptr){
            return;
        }

        // If leaf, add it
        if(is_leafNode(root)){
            ans.push_back(root->data);
            return;
        }

        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
    }

    vector<int> boundary(TreeNode* root){

        vector<int> ans;

        if(root == nullptr){
            return ans;
        }

        // Root is added separately.
        // If root itself is a leaf, it should
        // not be added again.
        if(!is_leafNode(root)){
            ans.push_back(root->data);
        }

        // 1. Left boundary
        leftBoundary(root, ans);

        // 2. Leaf nodes
        leafNodes(root, ans);

        // 3. Right boundary in reverse
        rightBoundaries(root, ans);

        return ans;
    }
};