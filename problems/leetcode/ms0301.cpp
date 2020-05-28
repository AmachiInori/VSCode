#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using std::vector;
using std::stack;
using std::string;

class TripleInOne {
    vector<int> stack;
    int size;
public:
    TripleInOne(int stackSize) {
        size = stackSize;
        stack.resize(3 * stackSize + 3);
        stack[0] = 0;
        stack[stackSize + 1] = stackSize + 1;
        stack[stackSize * 2 + 2] = stackSize * 2 + 2;
    }
    void push(int stackNum, int value) {
        if (stack[stackNum * (size + 1)] + 1 < (stackNum + 1) * (size + 1)){
            stack[stack[stackNum * (size + 1)] + 1] = value;
            stack[stackNum * (size + 1)]++;
        }
    }
    int pop(int stackNum) {
        if (isEmpty(stackNum)) return -1;
        else {
            int temp = peek(stackNum);
            stack[stackNum * (size + 1)]--;
            return temp;
        }
    }
    int peek(int stackNum) {
        if (isEmpty(stackNum)) return -1;
        else return stack[stack[stackNum * (size + 1)]];
    }
    bool isEmpty(int stackNum) {
        if (stack[stackNum * (size + 1)] == stackNum * (size + 1)) return true;
        else return false;
    }
};