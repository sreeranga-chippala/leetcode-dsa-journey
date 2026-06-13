/*

Problem: Delete Node in a Linked List

LeetCode:
https://leetcode.com/problems/delete-node-in-a-linked-list/

Goal:
Delete a given node from a singly linked list
when only the node to be deleted is provided.

Important:
- Head of the linked list is NOT given.
- The node to be deleted is guaranteed
  not to be the last node.

Approach:
Copy and Skip

Since we do not have access to the previous node,
we cannot delete the current node directly.

Steps:

1. Copy the value of the next node into
   the current node.

2. Store the next node in a temporary pointer.

3. Connect the current node to the
   next-next node.

4. Delete the stored node.

This effectively removes the desired node
from the linked list.

Key Insight:

Instead of deleting the current node,
overwrite it with the next node's data
and delete the next node.

Pseudocode:

DeleteNode(node):

    copy next node value into current node

    temp = next node

    current node points to next-next node

    delete temp

Complexity Analysis:

Time Complexity: O(1)

Space Complexity: O(1)

*/

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};

class Solution {
public:

    void deleteNode(ListNode* node) {

        // Copy next node's value
        node->val = node->next->val;

        // Store next node
        ListNode* temp = node->next;

        // Skip next node
        node->next = node->next->next;

        // Free memory
        delete temp;
    }
};

// Utility function to print linked list
void printList(ListNode* head) {

    while(head) {

        cout << head->val;

        if(head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    Solution obj;

    // 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Before Deletion: ";
    printList(head);

    // Delete node containing 5
    obj.deleteNode(head->next);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}