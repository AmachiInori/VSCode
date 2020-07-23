#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, bool> runned;
        vector<unordered_map<int, int>> sets(2);
        queue<int> BFS;
        for (int i = 0; i < graph.size(); i++){
            if (!graph[i].empty()) {
                sets[0][i] = 1;
                BFS.push(i);
                break;
            }
        }
        bool loca = true;
        while (!BFS.empty()) {
            int time = BFS.size();
            for (int i = 0; i < time; i++) {
                if (runned.find(BFS.front()) != runned.end()) {
                    BFS.pop();
                    continue;
                }
                for (int j = 0; j < graph[BFS.front()].size(); j++) {
                    if (sets[(int)!loca].find(graph[BFS.front()][j]) != sets[(int)!loca].end())
                        return false;
                    sets[loca][graph[BFS.front()][j]] = true;
                    BFS.push(graph[BFS.front()][j]);
                }
                runned[BFS.front()] = 1;
                BFS.pop();
            }
            loca ^= 1;
        }
        return true;
    }
};