/*
Problem: Delete the Middle Node of a Linked List

LeetCode:
https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

Goal:
Delete the middle node of a linked list
and return the modified head.

Middle Node:
- For odd length → exact middle
- For even length → second middle

Approach:
Fast & Slow Pointer

- Use slow and fast pointers
- Move:
    slow -> 1 step
    fast -> 2 steps

- Keep a prev pointer behind slow
- When fast reaches the end:
    slow points to middle node
    prev points to node before middle

Delete middle node:
    prev->next = slow->next

Key Insight:
Slow reaches the middle while fast reaches the end.

PseudoCode :

if list has 0 or 1 node:
    return null

slow = head
fast = head
prev = null

while fast exists and fast.next exists:

    prev = slow

    move slow by 1 step

    move fast by 2 steps

prev.next = slow.next

delete slow

return head

Complexity Analysis :

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

struct ListNode {

    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

class Solution {
public:

    ListNode* deleteMiddle(ListNode* head) {

        // Single node case
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast != nullptr && fast->next != nullptr){

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Remove middle node
        prev->next = slow->next;

        delete slow;

        return head;
    }
};

void printList(ListNode* head){

    while(head != nullptr){

        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution obj;

    head = obj.deleteMiddle(head);

    printList(head);

    return 0;
}