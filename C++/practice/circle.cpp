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
bool isCircleInChain(node<elementType>* head) {
    unordered_map<node<elementType>*, bool> history;
    while(head != nullptr) {
        if (history.find(head) != history.end())  //“如果在history中找到了指针head的记录”
            return true;
        history[head] = 1;
        head = head->next;
    }
    return false;
}