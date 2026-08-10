/*
Problem: Left View of Binary Tree

Source : 
    CCBP : 
    https://learning.ccbp.in/question/ebd358f6-881b-43ed-87ca-847def1ff3be
    
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

PseudoCode : 

if root is null:

    return empty result

push root

while queue is not empty:

    get level size

    for i = 0 to level size - 1:

        remove node

        if i == 0:

            add node to answer

        push left child

        push right child

return answer


Complexity Analysis : 

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