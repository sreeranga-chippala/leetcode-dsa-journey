/*
Problem: Odd Even Linked List

LeetCode:
https://leetcode.com/problems/odd-even-linked-list/

Goal:
Rearrange the linked list such that:
- All nodes at odd positions appear first
- All nodes at even positions appear next

The relative order within the odd and even groups
must remain the same.

Approach:
Two Pointer Rearrangement

- Maintain:
    odd  -> last node in odd-position list
    even -> last node in even-position list
    evenHead -> head of even-position list

- Re-link odd nodes together
- Re-link even nodes together
- Finally connect odd list with even list

Key Insight:
We are rearranging node links, not node values.

PseudoCode : 

    if list has fewer than 3 nodes:
        return head

    odd = head
    even = head.next
    evenHead = even

    while even exists and even.next exists:

        odd.next = even.next
        move odd forward

        even.next = odd.next
        move even forward

    odd.next = evenHead

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

    ListNode* oddEvenList(ListNode* head) {

        // Lists with fewer than 3 nodes need no rearrangement
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even != nullptr && even->next != nullptr){

            // Link next odd node
            odd->next = even->next;
            odd = odd->next;

            // Link next even node
            even->next = odd->next;
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;

        return head;
    }
};

// Helper function
void printList(ListNode* head){

    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main(){

    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    head = obj.oddEvenList(head);

    printList(head);

    return 0;
}