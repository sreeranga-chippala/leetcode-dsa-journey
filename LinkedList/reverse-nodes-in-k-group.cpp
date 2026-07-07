/*
Problem: Reverse Nodes in k-Group

LeetCode:
https://leetcode.com/problems/reverse-nodes-in-k-group/

Goal:
Reverse the nodes of a linked list in groups of size k.

- If the remaining nodes are fewer than k,
  leave them unchanged.

Approach:
Group-wise Reversal

1. Find the kth node from the current position.
2. If fewer than k nodes remain:
      attach the remaining nodes and stop.
3. Temporarily disconnect the group.
4. Reverse the current group.
5. Connect the reversed group with the previous part.
6. Repeat for the next group.

Key Insight:
Reverse one group at a time while maintaining
connections between consecutive groups.

PseudoCode :

Find kth Node {
    move k-1 steps forward

    if kth node exists:
        return kth

    return NULL
}

reverseKthGroup{
    current = head
    previousGroupTail = NULL

    while current exists:

        find kth node

        if kth does not exist:

            connect remaining nodes

            stop

        save next group

        disconnect current group

        reverse current group

        connect previous group
        with reversed group

        update previousGroupTail

        move to next group

    return head
}
    
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

    // Return the kth node from the current node
    ListNode* get_kth(ListNode* current, int k){

        int count = 0;

        while(current != nullptr && count != k - 1){

            count++;
            current = current->next;
        }

        if(count == k - 1){
            return current;
        }

        return nullptr;
    }

    // Reverse a linked list
    ListNode* reverse(ListNode* head){

        ListNode* current = head;
        ListNode* back = nullptr;
        ListNode* front = nullptr;

        while(current != nullptr){

            front = current->next;
            current->next = back;
            back = current;
            current = front;
        }

        return back;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* current = head;
        ListNode* previousNode = nullptr;

        while(current != nullptr){

            // Find kth node
            ListNode* kth = get_kth(current, k);

            // Remaining nodes fewer than k
            if(kth == nullptr){

                if(previousNode != nullptr){
                    previousNode->next = current;
                }

                break;
            }

            ListNode* nextNode = kth->next;

            // Separate current group
            kth->next = nullptr;

            // Reverse current group
            ListNode* reversedHead = reverse(current);

            // Connect with previous part
            if(current == head){
                head = reversedHead;
            }
            else{
                previousNode->next = reversedHead;
            }

            // Current becomes the tail after reversal
            previousNode = current;
            current = nextNode;
        }

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

    head = obj.reverseKGroup(head, 2);

    printList(head);

    return 0;
}