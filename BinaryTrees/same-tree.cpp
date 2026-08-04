/*
Problem: Same Tree

LeetCode:
https://leetcode.com/problems/same-tree/

Goal:
Determine whether two binary trees are identical.

Two trees are considered the same if:

- They have the same structure.
- Every corresponding node has the same value.

Approach:
Recursive Depth First Search (DFS)

Compare both trees simultaneously.

Cases:

1. Both nodes are null
   → Trees match at this position.

2. One node is null
   → Trees have different structures.

3. Values are different
   → Trees are not identical.

4. Otherwise,
   recursively compare:
   - Left subtrees
   - Right subtrees

Key Insight:
Both the structure and the values of the trees
must match at every node.

PseudoCode : 

if both nodes are null:

    return true

if one node is null:

    return false

if node values are different:

    return false

compare left subtrees

compare right subtrees

return

    left comparison AND right comparison


Complexity Analysis : 

Time Complexity: O(n)
Space Complexity: O(h)

where:
n = number of nodes
h = height of the tree
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

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both nodes are empty
        if(p == nullptr && q == nullptr){
            return true;
        }

        // One node exists while the other doesn't
        if(p == nullptr || q == nullptr){
            return false;
        }

        // Current node values are different
        if(p->val != q->val){
            return false;
        }

        // Compare left subtrees
        bool isLeftSame =
            isSameTree(p->left, q->left);

        // Compare right subtrees
        bool isRightSame =
            isSameTree(p->right, q->right);

        // Both sides must match
        return isLeftSame && isRightSame;
    }
};