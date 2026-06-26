/*
Problem: Linked List Cycle

LeetCode:
https://leetcode.com/problems/linked-list-cycle/

Goal:
Determine whether a linked list contains a cycle.

Approach:
Fast & Slow Pointer (Floyd's Cycle Detection)

- Initialize two pointers:
    slow -> moves 1 step
    fast -> moves 2 steps

- If the linked list contains a cycle,
  both pointers will eventually meet.

- If fast reaches NULL,
  there is no cycle.

Key Insight:
In a cyclic linked list, the faster pointer
will eventually catch up with the slower pointer.

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

    bool hasCycle(ListNode *head) {

        if(head == nullptr){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){

            // Move pointers
            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if(slow == fast){
                return true;
            }
        }

        // Fast reached end → no cycle
        return false;
    }
};

int main(){

    // Creating linked list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating cycle: -4 -> 2
    head->next->next->next->next = head->next;

    Solution obj;

    cout << (obj.hasCycle(head) ? "Cycle Exists" : "No Cycle") << endl;

    return 0;
}