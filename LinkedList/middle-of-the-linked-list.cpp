/*
Problem: Middle of the Linked List

LeetCode:
https://leetcode.com/problems/middle-of-the-linked-list/

Goal:
Return the middle node of the linked list.

If there are two middle nodes,
return the second middle node.

Approach:
Fast and Slow Pointer

- Initialize two pointers:
    slow = head
    fast = head

- Move:
    slow -> 1 step
    fast -> 2 steps

- When fast reaches the end:
    slow will be at the middle

Key Insight:
Fast moves twice as fast as slow.
So by the time fast finishes the list,
slow has covered only half the distance.

PseudoCode : 

slow = head
fast = head

while fast exists
and fast.next exists:

    move slow by 1 step

    move fast by 2 steps

return slow

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

    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){

            // Move slow by 1 step
            slow = slow->next;

            // Move fast by 2 steps
            fast = fast->next->next;
        }

        // Slow pointer reaches middle
        return slow;
    }
};

int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    ListNode* middle = obj.middleNode(head);

    cout << "Middle Node: "
         << middle->val
         << endl;

    return 0;
}