#include <bits/stdc++.h>
using namespace std;

int Prim(const vector<vector<int>> &Graph) {
    vector<int> distance(Graph.size(), int(INT_MAX));
    unordered_map<int, bool> visited;
    int nowPoint = 0;
    int res = 0;

    while (visited.size() != Graph.size()) {
        visited[nowPoint] = 1;
        for (int i = 0; i < Graph[nowPoint].size(); i++) {
            if (visited.find(i) == visited.end() && Graph[nowPoint][i] != 0) {
                distance[i] = std::min(distance[i], Graph[nowPoint][i]);
            }
        }
        int minPoint, minValue = INT_MAX;
        for (int i = 0; i < distance.size(); i++) {
            if (visited.find(i) == visited.end() && distance[i] < minValue) {
                minValue = distance[i];
                minPoint = i;
            }
        }
        if (visited.size() == Graph.size()) minValue = 0;
        res += minValue;
        nowPoint = minPoint;
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
    cout << Prim(test);
    return 0;
}