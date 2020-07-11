#include <bits/stdc++.h>

template<class elementType>
class monotoneStack {
private:
    std::stack<elementType> data;
    bool (*compare)(elementType const &a, elementType const &b);
    bool static _compare(elementType const &a, elementType const &b) const { return a > b; };
    elementType bottom;
public:
    monotoneStack(bool (*cmp)(elementType const, elementType const) = _compare) : compare(cmp) {};

    elementType top() const { return data.top(); }
    elementType bottom() const;
    unsigned int size() const { return data.size(); }
    bool empty() const { return data.empty(); }
    void push(elementType val);
    void pop() { data.pop(); }
};

template<class elementType>
void monotoneStack<elementType>::push(elementType val) {
    while (size() && !compare(val, data.top()))
        data.pop();
    if (empty()) bottom = val;
    data.push(val);
}

template<class elementType>
elementType monotoneStack<elementType>::bottom() const {
    if (size()) return bottom;
    else throw("empty stack");
}