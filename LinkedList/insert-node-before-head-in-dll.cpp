/*
Problem: Insert Before Head in a Doubly Linked List

Goal:
Insert a new node before the current head
and return the updated head.

Approach:
Pointer Manipulation

- Create a new node
- Set:
    newNode->next = head
    newNode->prev = NULL
- Update the old head's previous pointer
- Return the new node as the head

PseudoCode :

    create new node

    newNode.next = head

    if head exists:
        head.prev = newNode

    return newNode

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

    ListNode(int x, ListNode *p = nullptr, ListNode *n = nullptr){
        data = x;
        prev = p;
        next = n;
    }
};

class Solution {
public:

    ListNode* insertBeforeHead(ListNode* head, int X) {

        // Create new head node
        ListNode* newNode = new ListNode(X, nullptr, head);

        // Update previous pointer of old head
        if(head != nullptr){
            head->prev = newNode;
        }

        return newNode;
    }
};