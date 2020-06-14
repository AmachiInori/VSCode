#ifndef _TREENODE_H
#define _TREENODE_H

#include <utility>
#include <cstdint>
using namespace std;

class treeNode {
private:
    pair<uint8_t, int> value;  
    treeNode* left;
    treeNode* right;
public:
    treeNode() : value({0, 0}), left(NULL), right(NULL){}
    treeNode(pair<uint8_t, int> cfreq) : value(cfreq), left(NULL), right(NULL){}
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
    bool compareTreenode(treeNode* a, treeNode* b) {return *a < *b;}
    void sink (int k) {
		while (k * 2 <= queueLength) {
			int j = 2 * k;
			if (j < queueLength && (compareTreenode(array[j], array[j + 1]))) j++;
			if (!(compareTreenode(array[j], array[j + 1]))) break;
			swap(array[k], array[j]);
			k = j;
		}
	}
    void swim(int k) {
		while (k > 1 && !(compareTreenode(array[k], array[k / 2]))) {
			swap(array[k / 2], array[k]);
			k /= 2;
		}
	}
public:
    treeNodePriorityQueue(int N) {
        array = new treeNode*[N + 1];
    }
    void pop() {
        swap(array[1], array[queueLength--]);
        array[queueLength + 1] = NULL;
    }
    void push(treeNode* v) {
        array[++queueLength] = v;
        swim(queueLength);
    }
    treeNode* top() {return array[1];}
    int size() {return queueLength;}
};

#endif