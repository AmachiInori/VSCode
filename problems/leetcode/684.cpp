#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<unordered_map<int, bool>> hashs;
    void merge(unordered_map<int, bool> &a, unordered_map<int, bool> &b) {
        for (auto &i : b) a[i.first] = 1;
        return;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nowRes = -1;
        for (int i = 0; i < edges.size(); i++) {
            int fLoca = -1, sLoca = -1;
            for (int j = 0; j < hashs.size(); j++) {
                if(hashs[j].find(edges[i][0]) != hashs[j].end()) fLoca = j;
                if(hashs[j].find(edges[i][1]) != hashs[j].end()) sLoca = j;
            }
            if (fLoca == -1 && sLoca == -1) {
                unordered_map<int, bool>* tempH = new unordered_map<int, bool>;
                tempH -> insert({edges[i][0], 1});
                tempH -> insert({edges[i][1], 1});
                hashs.push_back(*tempH);
            } else if (fLoca == sLoca) {
                nowRes = i;
            } else if (fLoca == -1) {
                hashs[sLoca][edges[i][0]] = 1;
            } else if (sLoca == -1) {
                hashs[fLoca][edges[i][1]] = 1;
            } else {
                merge(hashs[fLoca], hashs[sLoca]);
                hashs[sLoca] = hashs.back();
                hashs.pop_back();
            }
        }
        if (nowRes == -1) return {-1, -1};
        return edges[nowRes];
    }
};

int main() {
    Solution s;
    vector<vector<int>> test = {{1,2},{4,3},{2,3},{1,4},{1,5}};
    vector<int> res = s.findRedundantConnection(test);
    cout << res[0] << ' ' << res[1];
    return 0;
}