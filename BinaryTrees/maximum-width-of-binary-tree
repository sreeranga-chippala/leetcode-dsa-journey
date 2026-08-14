/*
Problem: Maximum Width of Binary Tree

LeetCode:
https://leetcode.com/problems/maximum-width-of-binary-tree/

Goal:
Find the maximum width of a binary tree.

Width of a level:
Position of the rightmost node
-
Position of the leftmost node
+
1

Important:
Null positions between two nodes are also counted.

Approach:
BFS + Positional Indexing

Imagine the tree is stored like a complete binary tree.

For a node at index i:

    left child  = 2*i + 1
    right child = 2*i + 2

We store:

    {node, index}

For every level:

    width = rightmost_index - leftmost_index + 1

To prevent very large indices, we normalize
the indices at every level by subtracting the
first index of that level.

PseudoCode : 

if root is null:

    return 0

push root with index 0

while queue is not empty:

    store index of first node in current level

    get current level size

    for every node in this level:

        remove node

        normalize its index

        calculate current width

        if left child exists:

            push left child with
            2 * index + 1

        if right child exists:

            push right child with
            2 * index + 2

    update maximum width

return maximum width


Complexity Analysis : 

Time Complexity: O(n)
Space Complexity: O(n)
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

    int widthOfBinaryTree(TreeNode* root) {

        if(root == nullptr){
            return 0;
        }

        long long ans = -1;

        // {node, position}
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while(!q.empty()){

            // First position of current level
            long long start_index = q.front().second;

            long long size = q.size();

            long long width = 0;

            for(int i = 0; i < size; i++){

                TreeNode* current = q.front().first;

                // Normalize index to avoid overflow
                long long current_index =
                    q.front().second - start_index;

                q.pop();

                // Since nodes are processed left to right,
                // the current index is the width endpoint.
                width = current_index + 1;

                // Left child
                if(current->left != nullptr){
                    q.push({
                        current->left,
                        2 * current_index + 1
                    });
                }

                // Right child
                if(current->right != nullptr){
                    q.push({
                        current->right,
                        2 * current_index + 2
                    });
                }
            }

            ans = max(ans, width);
        }

        return ans;
    }
};