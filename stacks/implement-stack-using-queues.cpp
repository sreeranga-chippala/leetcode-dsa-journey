/*
Problem: Implement Stack using Queues

LeetCode:
https://leetcode.com/problems/implement-stack-using-queues/

Goal:
Implement a stack using only queue operations.

The stack should support:

- push()
- pop()
- top()
- empty()

Approach:
Two Queue Technique

- queue1 stores the current stack.
- queue2 is used temporarily during push.

For every push:
1. Insert the new element into queue2.
2. Move all elements from queue1 to queue2.
3. Swap queue1 and queue2.

This ensures that the newest element always
remains at the front of queue1.

Key Insight:
By rearranging elements during push,
pop() and top() become O(1).

Time Complexity:
push()  -> O(n)
pop()   -> O(1)
top()   -> O(1)
empty() -> O(1)

Space Complexity: O(n)
*/

#include <iostream>
#include <queue>
using namespace std;

class MyStack {

public:

    queue<int> queue1;
    queue<int> queue2;

    MyStack() {

    }

    // Push element onto stack
    void push(int x) {

        // Insert new element
        queue2.push(x);

        // Move all previous elements
        while(!queue1.empty()){

            queue2.push(queue1.front());
            queue1.pop();
        }

        // queue1 becomes the main queue
        swap(queue1, queue2);
    }

    // Remove top element
    int pop() {

        if(empty()){
            return -1;
        }

        int element = queue1.front();
        queue1.pop();

        return element;
    }

    // Return top element
    int top() {

        return queue1.front();
    }

    // Check whether stack is empty
    bool empty() {

        return queue1.empty();
    }
};

int main(){

    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Top: " << st.top() << endl;

    cout << "Popped: " << st.pop() << endl;

    cout << "Top: " << st.top() << endl;

    return 0;
}