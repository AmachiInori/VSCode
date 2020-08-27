#include <bits/stdc++.h>
using namespace std;

class Ford_Fulkerson {
private:
    vector<vector<int>> originGraph;
    vector<vector<int>> residualGraph;
    deque<int> path;
    bool FindPath(int start, int end);
public:
    explicit Ford_Fulkerson(const vector<vector<int>> &graph) 
        : originGraph(graph), residualGraph(graph) {}
    int getMaxFlow(int start, int end);
};

bool Ford_Fulkerson::FindPath(int start, int end) {
    path.clear();

    vector<int> parent(originGraph.size(), int(-1));
    vector<int> visited(originGraph.size(), int(0));
    queue<int> BFS;
    BFS.push(start);

    int nowQueueSize = 0;
    while (nowQueueSize = BFS.size()) {
        for (int i = 0; i < nowQueueSize; i++) {
            visited[BFS.front()] = 1;
            for (int j = 0; j < residualGraph[BFS.front()].size(); j++) {
                if (!visited[j] && residualGraph[BFS.front()][j] > 0) {
                    BFS.push(j);
                    parent[j] = BFS.front();
                }
            }
            BFS.pop();
        }
        if (visited[end]) break;
    }

    if (parent[end] == -1) return false;
    while (end != -1) {
        path.push_front(end);
        end = parent[end];
    }
    return true;
}

int Ford_Fulkerson::getMaxFlow(int start, int end) {
    int res = 0;
    while (FindPath(start, end)) {
        int temp = INT_MAX;
        for (int i = 0; i < path.size() - 1; i++) {
            temp = std::min(temp, residualGraph[path[i]][path[i + 1]]);
        }
        res += temp;
        for (int i = 0; i < path.size() - 1; i++) {
            residualGraph[path[i]][path[i + 1]] -= temp;
            residualGraph[path[i + 1]][path[i]] += temp;
        }
    }

    return res;
}

int main() {
    vector<vector<int>> test = {
        {0, 3, 2, 0, 0, 0},
        {0, 0, 1, 3, 4, 0},
        {0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 20},
        {0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0}
    };
    Ford_Fulkerson tec(test);
    cout << tec.getMaxFlow(0, 5);
    return 0;
}