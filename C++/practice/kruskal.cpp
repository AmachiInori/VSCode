#include <bits/stdc++.h>
using namespace std;

struct UFSNode {
    unsigned int classNum;
    unsigned int size;
    unsigned int next;
};

class UFSChain {
private:
    vector<UFSNode> arr;
public:
    UFSChain(int initSize = 0);
    void unite(int classA, int classB);
    int operator[](unsigned int index) const { return arr[index].classNum; }
};

UFSChain::UFSChain(int initSize) 
    : arr(initSize) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i].classNum = i;
        arr[i].size = 1;
        arr[i].next = -1;
    }
}

void UFSChain::unite(int classA, int classB) {
    if (arr[arr[classA].classNum].size > arr[arr[classB].classNum].size) {
        swap(classA, classB);
    }
    int str = arr[classA].classNum;
    arr[arr[classB].classNum].size += arr[arr[classA].classNum].size;
    while (arr[str].next != -1) {
        arr[str].classNum = classB;
        str = arr[str].next;
    }
    arr[str].classNum = arr[classB].classNum;
    arr[str].next = arr[classB].next;
    arr[arr[classB].classNum].next = classA;
}

int kruskal(const vector<vector<int>> &Graph) {
    vector<vector<int>> edge;
    for (int i = 0; i < Graph.size(); i++) {
        for (int j = 0; j < Graph.size(); j++) {
            if (Graph[i][j] != 0) {
                edge.push_back({Graph[i][j], i, j});
            }
        }
    }

    sort(edge.begin(), edge.end(), [](vector<int> A, vector<int> B) {
        return A[0] < B[0];
    });

    int res = 0;
    UFSChain ufs(Graph.size());
    for (int i = 0; i < edge.size(); i++) {
        if (ufs[edge[i][1]] != ufs[edge[i][2]]) {
            res += edge[i][0];
            ufs.unite(edge[i][1], edge[i][2]);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> test = {
        {0, 2, 4, 1, 0, 0, 0}, 
        {2, 0, 0, 3, 10, 0, 0},
        {4, 0, 0, 2, 0, 5, 0},
        {1, 3, 2, 0, 7, 8, 4},
        {0, 10, 0, 7, 0, 0, 6},
        {0, 0, 5, 8, 0, 0, 1},
        {0, 0, 0, 4, 6, 1, 0}
    };
    cout << kruskal(test);
    return 0;
}