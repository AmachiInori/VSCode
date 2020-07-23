#include <bits/stdc++.h>
using namespace std;

template<class elementType>
struct node {
    elementType data;
    node<elementType> *next;
    node(elementType _data = 0, node<elementType>* _next = nullptr) : data(_data), next(_next) {}
    bool operator==(const node<elementType> &x) {
        return this->data == x.data && this->next == x.next;
    }
};

template<class elementType>
class stackChain {
private:
    node<elementType> *head;
    unsigned int _size = 0;
public:
    stackChain();
    ~stackChain();
    void clear();
    void push(elementType value);
    void pop();
    elementType top() const { return head->next->data; }
    unsigned int size() { return _size; }
    bool empty() { return this->_size == 0; }
};

template<class elementType>
stackChain<elementType>::stackChain() {
    head = new node<elementType>;
}

template<class elementType>
stackChain<elementType>::~stackChain() {
    this->clear();
    delete head;
}

template<class elementType>
void stackChain<elementType>::clear() {
    node<elementType> *str = head->next;
    while (str) {
        node<elementType> *tempPtN = str;
        str = str->next;
        delete tempPtN;
    }
    head->next = nullptr;
    this->_size = 0;
}

template<class elementType>
void stackChain<elementType>::push(elementType value) {
    node<elementType> *str = new node<elementType>(value, head->next);
    head->next = str;
    this->_size++;
}

template<class elementType>
void stackChain<elementType>::pop() {
    node<elementType> *str = head->next;
    head->next = head->next->next;
    delete str;
    this->_size--;
}

int main() {
    stackChain<int> test;
    test.push(1);
    cout << test.top() << ' ' << test.size();
    test.push(21);
    cout << test.top() << ' ' << test.size();
    test.pop();
    cout << test.top() << ' ' << test.size();
    test.clear();
    cout << test.top() << ' ' << test.size();
    return 0;
}
