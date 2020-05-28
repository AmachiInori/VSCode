#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;

class MinStack {
    stack<int> mainStack;
    stack<int> sortStack;
public:
    MinStack() {
        sortStack.push(INT_MAX);
    }
    
    void push(int x) {
        mainStack.push(x);
        sortStack.push(std::min(x, sortStack.top()));
    }
    
    void pop() {
        mainStack.pop();
        sortStack.pop();
    }
    
    int top() {return mainStack.top();}
    
    int getMin() {return sortStack.top();}
};