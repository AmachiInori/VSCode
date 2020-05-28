#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> enqueueStack;
    stack<int> dequeueStack;
    int size;
public:
    MyQueue() {size = 0;}
    void push(int x) {
        size++;
        enqueueStack.push(x);
    }

    int pop() {
        int temp = this -> peek();
        dequeueStack.pop();
        size--;
        return temp;
    }

    int peek() {
        if (dequeueStack.empty()) {
            while (!enqueueStack.empty()) {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }
        return dequeueStack.top();
    }

    bool empty() {return size == 0;}
};