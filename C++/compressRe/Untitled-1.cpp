#include <cmath>
#include <iostream>
#include <utility>
#include "treenode.h"
const int LEN = 500;
using namespace std;

int main() {
    treeNode* v[LEN];
    treeNodePriorityQueue q(LEN);

    for (int i = 0; i < LEN; i++) {
        v[i] = new treeNode({i, i * pow(-1, i)});
        q.push(v[i]);
        cout << (int)q.top()->getWord() << ' ' << q.top()->totalFreq() << endl;
    }
    cout << "-----------------" << endl;
    for (int i = 0; i < LEN; i++) {
        cout << (int)q.top()->getWord() << ' ' << q.top()->totalFreq() << endl;
        q.pop();
    }
    return 0;
}