/*
Problem: Delete Head of a Doubly Linked List
source : Strivers a-z DSA sheet

Goal:
Delete the first node and return
the new head.

Approach:
Pointer Manipulation

- Handle empty list
- Handle single-node list
- Move head to the second node
- Remove links to the old head
- Delete the old head

PseudoCode :

    if list is empty:
        return NULL

    if only one node:
        delete it
        return NULL

    temp = head

    move head forward

    head.prev = NULL

    delete temp

    return head

Complexity Analysis : 

Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode *prev;
    ListNode *next;

    ListNode(int x){
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

class Solution {
public:

    ListNode* deleteHead(ListNode*& head) {

        if(head == nullptr){
            return nullptr;
        }

        if(head->next == nullptr){
            delete head;
            return nullptr;
        }

        ListNode* temp = head;

        head = head->next;

        head->prev = nullptr;

        temp->next = nullptr;

        delete temp;

        return head;
    }
};