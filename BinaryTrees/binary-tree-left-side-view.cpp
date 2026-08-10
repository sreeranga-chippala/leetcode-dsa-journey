/*
Problem: Left View of Binary Tree

Goal:
Return the nodes visible when looking at the
binary tree from the left side.

Approach:
BFS / Level Order Traversal

Your approach:

- Process every level using a queue.
- Push the RIGHT child before the LEFT child.
- Therefore, the leftmost node is processed LAST.
- Store the last processed node of every level.

Time Complexity: O(n)

Space Complexity: O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:

    vector<int> leftView(Node* root) {

        vector<int> ans;

        if(root == nullptr){
            return ans;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();

            for(int i = 0; i < size; i++){

                Node* current = q.front();
                q.pop();

                // First node of every level
                if(i == 0){
                    ans.push_back(current->data);
                }

                if(current->left){
                    q.push(current->left);
                }

                if(current->right){
                    q.push(current->right);
                }
            }
        }

        return ans;
    }
};