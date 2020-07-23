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
class chainQueue {
private:
    node<elementType> *head = nullptr;
    node<elementType> *end = nullptr;
    unsigned int _size = 0;
public:
    chainQueue();
    ~chainQueue();
    void clear();
    unsigned int size() const { return _size; }
    void push(elementType val);
    void pop();
    elementType getHead() const;
    elementType getEnd() const;
};

template<class elementType>
chainQueue<elementType>::chainQueue() {
    if (head != nullptr) {
        this->clear();
        delete head;
    }
    head = new node<elementType>;
    end = head;
}

template<class elementType>
chainQueue<elementType>::~chainQueue() {
    this->clear();
    delete head;
}

template<class elementType>
void chainQueue<elementType>::clear() {
    node<elementType> *str = head->next;
    while (str != nullptr) {
        node<elementType> *tempPtN = str;
        str = str->next;
        delete tempPtN;
    }
    _size = 0;
    end = head;
}

template<class elementType>
void chainQueue<elementType>::push(elementType val) {
    node<elementType> *newPtN = new node<elementType>(val);
    end->next = newPtN;
    end = newPtN;
    _size++;
}

template<class elementType>
void chainQueue<elementType>::pop() {
    if (_size == 0)
        throw("empty queue!");
    node<elementType> *tempPtN = head->next;
    head->next = tempPtN->next;
    delete tempPtN;
    _size--;
    if (_size == 0)
        end = head;
}

template<class elementType>
elementType chainQueue<elementType>::getEnd() const {
    if (_size == 0)
        throw("empty queue!");
    return end->data;
}

template<class elementType>
elementType chainQueue<elementType>::getHead() const {
    return head->next->data;
}

int main() {
    chainQueue<int> test;
    test.push(1);
    cout << test.size();
    test.push(2);
    cout << test.size();
    test.push(3);
    test.pop();
    cout << test.size();
    test.pop();
    cout << test.size();
    test.pop();
    return 0;
}