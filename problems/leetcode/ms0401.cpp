#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> adjTable(n, vector<int>({}));
        for_each(graph.begin(), graph.end(), [&adjTable](const vector<int>& temp) {
            adjTable[temp[0]].push_back(temp[1]);
        });

        queue<int> BFS;
        vector<int> visited(n, int(0));
        BFS.push(start);
        int nowQueueSize = 0;
        while (nowQueueSize = BFS.size()) {
            for (int i = 0; i < nowQueueSize; i++) {
                visited[BFS.front()] = 1;
                for (int j = 0; j < adjTable[BFS.front()].size(); j++) {
                    if (visited[adjTable[BFS.front()][j]] == 0) {
                        BFS.push(adjTable[BFS.front()][j]);
                    }
                }
                BFS.pop();
            }
        }
        return visited[target] == 1;
    }
};