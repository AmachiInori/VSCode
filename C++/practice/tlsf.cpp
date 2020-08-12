#include <bits/stdc++.h>
using namespace std;

int unweightedPath (int totalNodeNumber, vector<vector <int>> Table, int start, int end) {
    vector<int> distance(totalNodeNumber, int(-1));
    queue<int> BFS;
    BFS.push(start);
    distance[start] = 0;
    
    int nowDist = 0;
    int nowQueueSize = BFS.size();
    while (nowQueueSize != 0) {
        for (int i = 0; i < nowQueueSize; i++) {
            for (int j = 0; j < Table[BFS.front()].size(); j++) {
                if (distance[Table[BFS.front()][j]] != -1) continue;
                BFS.push(Table[BFS.front()][j]);
                distance[Table[BFS.front()][j]] = distance[BFS.front()] + 1;
            }
            BFS.pop();
        }
        if (distance[end] != -1) return distance[end];
    }
    return distance[end];
}