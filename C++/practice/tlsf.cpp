#include <bits/stdc++.h>
using namespace std;

int unweightedPath (int totalNodeNumber, vector<vector<int>> Table, int start, int end) {
    vector<int> distance(totalNodeNumber, int(-1));
    queue<int> BFS;
    BFS.push(start);
    distance[start] = 0;
    
    int nowQueueSize;
    while (nowQueueSize = BFS.size()) {
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

int Dijkstra (int totalNodeNumber, vector<vector<pair<int, int>>> Table, int start, int end) {
    vector<int> distance(totalNodeNumber, int(INT_MAX));
    queue<int> BFS;
    BFS.push(start);
    distance[start] = 0;
    
    int nowQueueSize;
    while (nowQueueSize = BFS.size()) {
        for (int i = 0; i < nowQueueSize; i++) {
            for (int j = 0; j < Table[BFS.front()].size(); j++) {
                if (distance[Table[BFS.front()][j].first] > distance[BFS.front()] + Table[BFS.front()][j].second){
                    BFS.push(Table[BFS.front()][j].first);
                    distance[Table[BFS.front()][j].first] = distance[BFS.front()] + Table[BFS.front()][j].second;
                }
                
            }
            BFS.pop();
        }
    }
    return distance[end];
}


int main() {
    vector<vector<pair<int, int>>> test = {
        {}, 
        {{2, 10}, {4, 2}}, 
        {{3, 5}}, 
        {}, 
        {{5, 3}}, 
        {{2, 2}, {6, 1}, {7, 1}}, 
        {{3, 4}}, 
        {{8, 1}}, 
        {{6, 1}}
    };
    cout << Dijkstra(9, test, 1, 3);
    return 0;
}