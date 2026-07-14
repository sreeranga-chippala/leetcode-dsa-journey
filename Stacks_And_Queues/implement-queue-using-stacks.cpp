/*
Problem: Implement Queue using Stacks

LeetCode:
https://leetcode.com/problems/implement-queue-using-stacks/

Goal:
Implement a queue using only stack operations.

The queue should support:

- push()
- pop()
- peek()
- empty()

Approach:
Two Stack Technique

- stack1:
    Used for insertion.

- stack2:
    Used for deletion and front access.

Whenever stack2 becomes empty:
- Transfer all elements from stack1 to stack2.
- This reverses the order, making the oldest
  element appear on top.

Key Insight:
Each element is transferred at most once from
stack1 to stack2, giving an amortized O(1)
time complexity.


PseudoCode : 

push(value){
    push element into stack1
}

pop(){
    if stack2 is empty:

    move all elements
    from stack1 to stack2

    remove top of stack2

    return removed value
}

peek(){
    if stack2 is empty:

    move all elements
    from stack1 to stack2

    return top of stack2
}

empty(){
    return

        (stack1 empty

        AND

        stack2 empty)
}
        
Complexity Analysis : 

Time Complexity:
push()   -> O(1)
pop()    -> O(1)
top()    -> O(1)
getMin() -> O(1)

Space Complexity: O(n)
*/


#include <iostream>
#include <stack>
using namespace std;

class MyQueue {

    stack<int> stack1;
    stack<int> stack2;

public:

    MyQueue() {

    }

    // Insert element into queue
    void push(int x) {

        stack1.push(x);
    }

    // Remove front element
    int pop() {

        // Transfer elements if needed
        if(stack2.empty()){

            while(!stack1.empty()){

                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int value = stack2.top();
        stack2.pop();

        return value;
    }

    // Return front element
    int peek() {

        // Transfer elements if needed
        if(stack2.empty()){

            while(!stack1.empty()){

                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return stack2.top();
    }

    // Check whether queue is empty
    bool empty() {

        return stack1.empty() && stack2.empty();
    }
};

int main(){

    MyQueue q;

    q.push(1);
    q.push(2);

    cout << "Front: " << q.peek() << endl;

    cout << "Removed: " << q.pop() << endl;

    cout << "Empty? " << q.empty() << endl;

    return 0;
}
