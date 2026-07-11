/*

Problem: Min Stack

LeetCode:
https://leetcode.com/problems/min-stack/

Goal:
Design a stack that supports the following operations
in constant time:

- push()
- pop()
- top()
- getMin()

Approach:
Two Stack Technique

- mainStack stores all elements.
- minStack stores the minimum element corresponding
  to every position in mainStack.

For every push:
- Push value into mainStack.
- If value is smaller than the current minimum,
  push value into minStack.
- Otherwise, push the current minimum again.

For every pop:
- Pop from both stacks.

Key Insight:
The top of minStack always stores the minimum
element of the stack at that moment.

PseudoCode :

push(value){
    push value into main stack

    if min stack is empty
    or value is smaller than current minimum:

        push value into min stack

    else:

        push current minimum again
}

pop(){
    pop from main stack

    pop from min stack
}

top(){
    return top of main stack
}

getMin(){
    return top of min stack
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

class MinStack {

    stack<int> mainStack;
    stack<int> minStack;

public:

    MinStack() {

    }

    // Push element into stack
    void push(int value) {

        mainStack.push(value);

        // New minimum found
        if(minStack.empty() || value < minStack.top()){
            minStack.push(value);
        }
        else{
            // Repeat current minimum
            minStack.push(minStack.top());
        }
    }

    // Remove top element
    void pop() {

        if(!mainStack.empty()){

            mainStack.pop();
            minStack.pop();
        }
    }

    // Return top element
    int top() {

        return mainStack.top();
    }

    // Return minimum element
    int getMin() {

        return minStack.top();
    }
};

int main(){

    MinStack obj;

    obj.push(-2);
    obj.push(0);
    obj.push(-3);

    cout << "Minimum: " << obj.getMin() << endl;

    obj.pop();

    cout << "Top: " << obj.top() << endl;
    cout << "Minimum: " << obj.getMin() << endl;

    return 0;
}