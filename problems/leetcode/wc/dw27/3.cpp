#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> graph;
public:
    bool find(vector<vector<int>>& dict, int target, int nowNumber) {
        if (graph[target][nowNumber]) return true;
        int res(false);
        for (int i(0); i < graph.size(); i++) {
            if (graph[i][nowNumber]) res = res || find(dict, target, i);
        }
        if (res) graph[target][nowNumber] = true;
        return res;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> res(queries.size(), false);
        graph.resize(n);
        for (auto &i : graph) i = vector<int>(n, 0);
        for (int i(0); i < prerequisites.size(); i++) 
            graph[prerequisites[i][0]][prerequisites[i][1]] = 1;
        for (int i(0); i < graph.size(); i++) {
            for (int j(0); j < graph.size(); j++) {
                if (graph[i][j]) {
                    for (int k(0); k < graph.size(); k++)
                        if (graph[j][k]) graph[i][k] = 1;
                }
            }
        }
        for (int i(0); i < queries.size(); i++) {
            if (find(prerequisites, queries[i][0], queries[i][1])) 
                res[i] = true;
        }
        return res;
    }
};

