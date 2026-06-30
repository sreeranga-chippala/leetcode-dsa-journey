/*

Problem: Palindrome Linked List

LeetCode:
https://leetcode.com/problems/palindrome-linked-list/

Goal:
Determine whether a linked list is a palindrome.

Approach:
Fast & Slow Pointer + Reverse Second Half

Steps:
1. Find the middle of the linked list
2. Reverse the second half
3. Compare the first half and reversed second half
4. If all corresponding nodes match, return true

Key Insight:
Instead of using extra space, reverse only the
second half of the list and compare both halves.

PseudoCode :
    find the middle of the linkedlist
    first = head
    second = reversed second half

    while second exists:

        if values are different:
            return false

        move both pointers

    return true
    
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

    // Reverse a linked list
    ListNode* reverseList(ListNode* head){

        if(head == nullptr){
            return head;
        }

        ListNode* current = head;
        ListNode* back = nullptr;
        ListNode* front = nullptr;

        while(current != nullptr){

            // Store next node
            front = current->next;

            // Reverse current link
            current->next = back;

            // Move pointers
            back = current;
            current = front;
        }

        return back;
    }

    bool isPalindrome(ListNode* head) {

        if(head == nullptr || head->next == nullptr){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle node
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* temp1 = head;
        ListNode* temp2 = reverseList(slow);

        // Compare both halves
        while(temp2 != nullptr){

            if(temp1->val != temp2->val){
                return false;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};

int main(){

    // 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution obj;

    cout << (obj.isPalindrome(head) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}