/*
Problem: Add Two Numbers

LeetCode:
https://leetcode.com/problems/add-two-numbers/

Goal:
Add two non-negative integers represented as linked lists.
Each node stores one digit in reverse order.

Return the sum as a linked list.

Approach:
Simulation + Carry

- Create a dummy node to simplify list construction
- Traverse both linked lists simultaneously
- Add:
    digit from l1
    + digit from l2
    + carry
- Store the last digit in a new node
- Update carry
- Continue until both lists and carry are exhausted

Key Insight:
This is the same process as manual addition from right to left,
keeping track of the carry after every digit.

Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node simplifies list construction
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry > 0){

            int sum = carry;

            // Add digit from first list
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }

            // Add digit from second list
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }

            // Update carry
            carry = sum / 10;

            // Create node with current digit
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        ListNode* result = dummy->next;
        delete dummy;

        return result;
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

    // Number 342 -> 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Number 465 -> 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution obj;

    ListNode* result = obj.addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}