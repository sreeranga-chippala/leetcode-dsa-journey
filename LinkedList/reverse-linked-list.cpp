/*

Problem: Reverse Linked List

LeetCode:
https://leetcode.com/problems/reverse-linked-list/

Goal:
Reverse a singly linked list and return
the new head.

Approach:
Three Pointer Technique

Maintain:
- previous -> previous node
- current  -> current node
- front    -> next node

For every node:
1. Store next node in front
2. Reverse current node's link
3. Move previous forward
4. Move current forward

Key Insight:
Before changing links, always save the next node.
Otherwise, the remaining list gets lost.

PseudoCode : 

previous = null
current = head

while current exists:

    front = current.next

    current.next = previous

    previous = current

    current = front

return previous

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

    ListNode* reverseList(ListNode* head) {

        if(head == nullptr){
            return head;
        }

        ListNode* current = head;
        ListNode* previous = nullptr;
        ListNode* front = nullptr;

        while(current != nullptr){

            // Store next node
            front = current->next;

            // Reverse link
            current->next = previous;

            // Move pointers forward
            previous = current;
            current = front;
        }

        // Previous becomes new head
        return previous;
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    ListNode* reversedHead = obj.reverseList(head);

    printList(reversedHead);

    return 0;
}