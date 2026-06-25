/*
Problem: Remove Nth Node From End of List

LeetCode:
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Goal:
Remove the nth node from the end of the linked list
and return the modified head.

Approach:
Two Pointer Technique

- Initialize two pointers: fast and slow
- Move fast pointer n steps ahead
- If fast becomes NULL:
    → Remove the head node
- Otherwise:
    → Move both pointers together until
      fast reaches the last node
- Slow will now be just before the node to delete
- Remove the target node

Key Insight:
Maintain a gap of n nodes between fast and slow.
When fast reaches the end, slow reaches the node
just before the one to be deleted.

PseudoCode : 

fast = head
slow = head

move fast pointer n steps ahead

if fast is NULL:
    delete head
    return new head

while fast.next exists:

    move fast one step

    move slow one step

nodeToDelete = slow.next

slow.next = nodeToDelete.next

delete nodeToDelete

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

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer n steps ahead
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // If head needs to be removed
        if(fast == nullptr){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Move both pointers together
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        // Delete nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        return head;
    }
};

// Helper function to print linked list
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

    head = obj.removeNthFromEnd(head, 2);

    printList(head);

    return 0;
}