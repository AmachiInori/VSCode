#ifndef _TREENODE_H
#define _TREENODE_H

#include <utility>
#include <cstdint>
#include <iostream>
using namespace std;

class treeNode {
private:
    pair<uint8_t, int> value;
    treeNode* left;
    treeNode* right;
public:
    treeNode() : value({0, 0}), left(NULL), right(NULL){}
    explicit treeNode(pair<uint8_t, int> cfreq) : value(cfreq), left(NULL), right(NULL){}
    treeNode(pair<uint8_t, int> cfreq, treeNode* L, treeNode* R) : value(cfreq), left(L), right(R){}

    bool operator< (const treeNode &a) const {
        if (value.second == a.value.second) return value.first > a.value.first;
        else return value.second > a.value.second;
    }
    uint8_t getWord() const {return value.first;}
    int totalFreq() const {return value.second;}
    bool isLeaf() const {return !(left || right);}
    treeNode* getLeft() {return left;}
    treeNode* getRight() {return right;}
};

class treeNodePriorityQueue {
private:
    treeNode** array;
    int queueLength = 0;
    bool compareTreenode(treeNode* a, treeNode* b) {return (*a) < (*b);}
public:
    treeNodePriorityQueue(int N) {
        array = new treeNode*[N + 1];
        array[0] = new treeNode({0, INT_MIN});
    }
    void pop() {
        int i, child;
        treeNode* min, *last;
        min = array[1];
        last = array[queueLength--];
        for (i = 1; i * 2 <= queueLength; i = child) {
            child = i * 2;
            if (compareTreenode(array[child], array[child + 1]))
                child++;
            if (compareTreenode(last, array[child]))
                array[i] = array[child];
            else break;
        }
        array[i] = last;
    }
    void push(treeNode* v) {
        if (!queueLength) {
            array[++queueLength] = v;
            return;
        }
        int i;
        for (i = ++queueLength; compareTreenode(array[i / 2], v); i /= 2)
            array[i] = array[i / 2];
        array[i] = v;
    }
    treeNode* top() {return array[1];}
    int size() {return queueLength;}
};

#endif