#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, vector<int>> hash;
    unordered_map<int, vector<int>> antiHash;
    unordered_map<int, int> used;
public:
    int runner(int n) {
        int res(0);
        used[n] = 1;
        for (int i = 0; i < antiHash[n].size(); i++) {
            if (used.find(antiHash[n][i]) == used.end()) {
                res++;
                hash[n].push_back(antiHash[n][i]);
            }
        }
        for (int i = 0; i < hash[n].size(); i++) {
            runner(hash[n][i]);
        }
        return res;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for (int i = 0; i <= n; i++)
            hash[i] = {}, antiHash = {};
        for (auto &i : connections) {
            antiHash[i[0]].push_back(i[1]);
            hash[i[1]].push_back(i[0]);
        }
        return runner(0);
    }
};