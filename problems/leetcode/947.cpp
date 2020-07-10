#include <bits/stdc++.h>
using namespace std;

class disjset {
private:
    vector<int> root;
public:
    disjset(int maxSize) : root(maxSize) {
        for (int i = 0; i < maxSize; i++)
            root[i] = i;
    }
    int find (int x) { return root[x] == x ? x : find(root[x]); }
    void merge (int x, int y) { root[find(x)] = find(y); }
    bool isEqual (int x, int y) { return find(x) == find(y); }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        disjset theSet = disjset(20000);
        for (auto &i : stones) {
            theSet.merge(i[0], i[1] + 10000);
        }
        unordered_map<int, bool> hash;
        for (auto &i : stones) {
            hash[theSet.find(i[0])] = 1;
            hash[theSet.find(i[1] + 10000)] = 1;
        }
        return stones.size() - hash.size();
    }
};