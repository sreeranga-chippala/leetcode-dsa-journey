/*
Problem: Linked List Cycle II

LeetCode:
https://leetcode.com/problems/linked-list-cycle-ii/

Goal:
Return the node where the cycle begins.
If there is no cycle, return NULL.

Approach:
Floyd's Cycle Detection (Fast & Slow Pointer)

Phase 1:
- Move slow by 1 step
- Move fast by 2 steps
- If they meet, a cycle exists

Phase 2:
- Place a new pointer (entry) at the head
- Move both entry and slow one step at a time
- The node where they meet is the start of the cycle

Key Insight:
After the first meeting inside the cycle,
the distance from the head to the cycle start
equals the distance from the meeting point
to the cycle start.

Pseudocode : 

Phase 1: Detect Cycle 
    if head is NULL:
        return NULL

    slow = head
    fast = head

    while fast exists and fast.next exists:

        move slow by 1 step

        move fast by 2 steps

        if slow == fast:
            cycle found
            break

    if no cycle:
        return NULL

Phase 2: Find Cycle Start 
    entry = head

    while entry != slow:

        move entry by 1 step

        move slow by 1 step

    return entry
    
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

    ListNode* detectCycle(ListNode* head) {

        if(head == nullptr){
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;

        // Phase 1: Detect cycle
        while(fast != nullptr && fast->next != nullptr){

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                hasCycle = true;
                break;
            }
        }

        // No cycle found
        if(!hasCycle){
            return nullptr;
        }

        // Phase 2: Find cycle entry
        ListNode* entry = head;

        while(entry != slow){

            entry = entry->next;
            slow = slow->next;
        }

        return entry;
    }
};

int main(){

    // Create list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle: -4 -> 2
    head->next->next->next->next = head->next;

    Solution obj;

    ListNode* start = obj.detectCycle(head);

    if(start){
        cout << "Cycle starts at node: " << start->val << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    return 0;
}