/*

Problem: Intersection of Two Linked Lists

LeetCode:
https://leetcode.com/problems/intersection-of-two-linked-lists/

Goal:
Return the node where two singly linked lists intersect.
If they do not intersect, return NULL.

Approach:
Two Pointer Switching Technique

- Initialize two pointers:
    ptrA = headA
    ptrB = headB

- Traverse both lists simultaneously
- When a pointer reaches the end of its list,
  redirect it to the head of the other list

- Eventually:
    • If an intersection exists, both pointers
      meet at the intersection node
    • Otherwise, both become NULL

Key Insight:
By switching lists, both pointers travel
the same total distance (lengthA + lengthB),
eliminating any difference in list lengths.

PseudoCode :

if either list is empty:
    return NULL

pointerA = headA
pointerB = headB

while pointerA != pointerB:

    if pointerA is NULL:
        pointerA = headB
    else:
        pointerA = pointerA.next

    if pointerB is NULL:
        pointerB = headA
    else:
        pointerB = pointerB.next

return pointerA

Complexity Analysis : 

Time Complexity: O(n + m)
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

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while(ptrA != ptrB){

            // Move pointer A
            if(ptrA == nullptr){
                ptrA = headB;
            }
            else{
                ptrA = ptrA->next;
            }

            // Move pointer B
            if(ptrB == nullptr){
                ptrB = headA;
            }
            else{
                ptrB = ptrB->next;
            }
        }

        // Either intersection node or NULL
        return ptrA;
    }
};

int main(){

    // Common part: 8 -> 4 -> 5
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution obj;

    ListNode* intersection = obj.getIntersectionNode(headA, headB);

    if(intersection){
        cout << "Intersection Node: " << intersection->val << endl;
    }
    else{
        cout << "No Intersection" << endl;
    }

    return 0;
}