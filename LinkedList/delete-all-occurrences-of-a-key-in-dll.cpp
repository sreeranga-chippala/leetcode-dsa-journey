/*
Problem: Delete All Occurrences in a Doubly Linked List
source : Strivers a-z DSA sheet

Goal:
Delete every node whose value equals target.

Approach:
Traversal + Pointer Updates

- Traverse the list
- If current node matches target:
    - Update previous node's next pointer
    - Update next node's previous pointer
    - Handle head deletion separately
    - Delete current node

Key Insight:
Store both previous and next pointers before
deleting the current node.

PseudoCode :

    current = head

    while current exists:

        save previous node

        save next node

        if current value equals target:

            if current is head:
                update head

            connect previous with next

            connect next with previous

            delete current

        move to next node
        
Complexity Analysis :

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

struct ListNode{

    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int x){
        val = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
public:

    ListNode* deleteAllOccurrences(ListNode* head, int target) {

        ListNode* temp = head;

        while(temp != nullptr){

            ListNode* back = temp->prev;
            ListNode* front = temp->next;

            if(temp->val == target){

                // Update head
                if(temp == head){
                    head = front;
                }

                // Connect previous node
                if(back != nullptr){
                    back->next = front;
                }

                // Connect next node
                if(front != nullptr){
                    front->prev = back;
                }

                temp->prev = nullptr;
                temp->next = nullptr;

                delete temp;
            }

            temp = front;
        }

        return head;
    }
};