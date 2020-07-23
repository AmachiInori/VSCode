#include <bits/stdc++.h>
using namespace std;

struct UFSNode {
    unsigned int classNum;
    unsigned int size;
    int next;
};

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
class chainList {
protected:
    node<elementType> *head = nullptr;
    int length = 0;
    bool validIndex(int index) { return index >= 0 && index < length; }
public:
    chainList();
    chainList(const chainList<elementType> &copyList);
    chainList(const vector<elementType> &copyVector);
    ~chainList();
    void makeEmpty();

    int size() const { return length; }
    bool empty() const { return length == 0; }
    chainList<elementType>& operator=(const chainList<elementType> &A);

    elementType& operator[](const unsigned int index);
    void pop(const unsigned int index);
    void push(elementType val, const unsigned int index);
    void merge(chainList<elementType> const &A);
};

class UFSChain {
private:
    vector<UFSNode> arr;
public:
    UFSChain(int initSize = 0);
    void unite(int classA, int classB);
    int operator[](unsigned int index) { return arr[index].classNum; }
};

UFSChain::UFSChain(int initSize) : arr(initSize) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i].classNum = i;
        arr[i].size = 1;
        arr[i].next = -1;
    }
}

template<class elementType>
chainList<elementType>::chainList() {
    if (this->length != 0)
        this->makeEmpty();
    if (this->head == nullptr) this->head = new node<elementType>;
    this->length = 0;
}

template<class elementType>
chainList<elementType>::chainList(const chainList<elementType> &copyList) {
    if (this->length != 0)
        this->makeEmpty();
    if (this->head == nullptr) this->head = new node<elementType>;
    this->length = 0;
    *this = copyList;
}

template<class elementType>
chainList<elementType>::chainList(const vector<elementType> &copyVector) {
    if (this->length != 0)
        this->makeEmpty();
    if (this->head == nullptr) this->head = new node<elementType>;
    this->length = 0;
    if (copyVector.empty()) return;
    node<elementType> *str = head;
    for (int i = 0; i < copyVector.size(); i++) {
        node<elementType> *tempPtN = new node<elementType>(copyVector[i]);
        str->next = tempPtN;
        str = str->next;
    }
    this->length = copyVector.size();
}

template<class elementType>
chainList<elementType>::~chainList() {
    this->makeEmpty();
    delete head;
}

template<class elementType>
void chainList<elementType>::makeEmpty() {
    node<elementType> *str = head -> next;
    while (str != nullptr) {
        node<elementType> *tempPtN = str->next;
        delete str;
        str = tempPtN;
    }
    head->next = nullptr;
}

template<class elementType>
chainList<elementType>& chainList<elementType>::operator=(const chainList<elementType> &A) {
    if (!this->empty()) this->makeEmpty();
    if (A.empty()) return *this;
    node<elementType> *strThis = head, *strThat = A.head;
    while (strThat != nullptr) {
        strThis->data = strThat->data;
        if (strThat->next != nullptr) {
            node<elementType> *tempPtN = new node<elementType>;
            strThis->next = tempPtN;
        }
        strThis = strThis->next, strThat = strThat->next;
    }
    this->length = A.length;
    return *this;
}

template<class elementType>
elementType& chainList<elementType>::operator[](const unsigned int index) {
    if (!this->validIndex(index)) throw("Invalid Index");
    node<elementType> *str = this->head;
    for (int i = 0; i < index + 1; i++){
        str = str->next;
    }
    return str->data;
}

template<class elementType>
void chainList<elementType>::pop(const unsigned int index) {
    if (!this->validIndex(index)) throw("Invalid Index");
    node<elementType> *str = this->head;
    for (int i = 0; i < index; i++){
        str = str->next;
    }
    node<elementType> *tempPtN = str->next;
    str->next = tempPtN->next;
    delete tempPtN;
    this->length--;
}

template<class elementType>
void chainList<elementType>::push(elementType val, const unsigned int index) {
    this->length++;
    if (!this->validIndex(index)) throw("Invalid Index");
    node<elementType> *str = this->head;
    for (int i = 0; i < index; i++){
        str = str->next;
    }
    node<elementType> *tempPtN = new node<elementType>(val, str->next);
    str->next = tempPtN;
}

template<class elementType>
void chainList<elementType>::merge(chainList<elementType> const &A) {
    chainList<elementType> tempChain(A);
    node<elementType> *str = this->head;
    while (str->next != nullptr) {
        str = str->next;
    }
    str->next = tempChain.head->next;
    this->length += tempChain.length;
    tempChain.head->next = nullptr;
};

void UFSChain::unite(int classA, int classB) {
    if (arr[arr[classA].classNum].size > arr[arr[classB].classNum].size) {
        swap(classA, classB);
    }
    int str = arr[classA].classNum;
    arr[arr[classB].classNum].size += arr[arr[classA].classNum].size; //只有首节点的size属性会被调用，因此只需要维护一个
    while (arr[str].next != -1) {
        arr[str].classNum = classB;
        str = arr[str].next;
    }
    arr[str].classNum = arr[classB].classNum;
    arr[str].next = arr[classB].next;
    arr[arr[classB].classNum].next = classA;
}

int main() {
    UFSChain test(5);
    test.unite(1, 2);
    test.unite(1, 3);
    test.unite(0, 1);
    cout << test[0] << test[1] << test[2] << test[3] << test[4] << endl;
    return 0;
}