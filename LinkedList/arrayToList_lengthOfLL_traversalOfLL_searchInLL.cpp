/*
Problem: Search an Element in a Singly Linked List

Goal:
Given a linked list and a key k,
determine whether the key exists in the list.

Approach:
Linear Traversal

- Start from the head node
- Traverse node by node
- Compare each node's data with k
- If found, return true
- If end of list is reached, return false

Key Insight:
Unlike arrays, linked lists do not support random access.
We must traverse sequentially.

PseudoCode :

* Array → Linked List: 
    if array is empty:
        return null

    create head node using first element

    current = head

    for each remaining element:

        create new node

        connect current.next to new node

        move current forward

    return head

* Search in Linked List : 
    current = head

    while current is not null:

        if current.data == key:
            return true

        move current to next node

    return false

* Length of Linked List:
    count = 0

    current = head

    while current is not null:

        count++

        move current forward

    return count
* Traversal of Linked List : 
    temp = head
    while  temp is not null:
        if temp is k then 
            return k
        else
            temp = temp -> next
            
Complexity Analysis : 

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

// Convert array to linked list
Node* array_to_LL(int arr[], int n){

    if(n == 0){
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* cur = head;

    for(int i = 1; i < n; i++){

        Node* temp = new Node(arr[i]);

        cur->next = temp;
        cur = cur->next;
    }

    return head;
}

// Print linked list
void print_LL(Node* head){

    Node* temp = head;

    while(temp != nullptr){

        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Find length of linked list
int length_LL(Node* head){

    int count = 0;
    Node* temp = head;

    while(temp != nullptr){

        count++;
        temp = temp->next;
    }

    return count;
}

// Search key in linked list
bool search_LL(Node* head, int k){

    Node* temp = head;

    while(temp != nullptr){

        // Key found
        if(temp->data == k){
            return true;
        }

        temp = temp->next;
    }

    // Key not found
    return false;
}

int main(){

    int n, k;
    cin >> n >> k;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Node* head = array_to_LL(arr, n);

    cout << search_LL(head, k) << endl;

    return 0;
}