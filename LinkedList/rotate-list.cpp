/*
Problem: Rotate List

LeetCode:
https://leetcode.com/problems/rotate-list/

Goal:
Rotate the linked list to the right by k positions.

Approach:
Circular Linked List

- Handle edge cases:
    • Empty list
    • Single node
    • k = 0

- Find:
    • Length of the list
    • Tail node

- Reduce unnecessary rotations:
    k = k % length

- Connect tail to head to form a circular list

- Find the new tail:
    It is (length - k - 1) nodes from the head

- New head is the node after the new tail

- Break the circular link

Key Insight:
Instead of rotating one step at a time,
convert the list into a circle and break it
at the correct position.

PseudoCode :

    if list is empty, has one node, or k = 0:
        return head

    find length and tail

    k = k % length

    if k == 0:
        return head

    connect tail to head

    move to (length - k - 1)th node

    newHead = next node

    break the circular link

    return newHead

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

    ListNode* rotateRight(ListNode* head, int k) {

        // Edge cases
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }

        // Find length and tail
        int n = 1;
        ListNode* tail = head;

        while(tail->next != nullptr){
            tail = tail->next;
            n++;
        }

        // Remove extra rotations
        k = k % n;

        if(k == 0){
            return head;
        }

        // Make the list circular
        tail->next = head;

        // Find new tail
        ListNode* new_tail = head;

        for(int i = 0; i < n - k - 1; i++){
            new_tail = new_tail->next;
        }

        // New head
        ListNode* new_head = new_tail->next;

        // Break the circle
        new_tail->next = nullptr;

        return new_head;
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

    head = obj.rotateRight(head, 2);

    printList(head);

    return 0;
}