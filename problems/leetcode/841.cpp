#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), int(0));
        queue<int> BFS;
        BFS.push(0);

        int nowQueueSize = 0;
        while (nowQueueSize = BFS.size()) {
            for (int i = 0; i < nowQueueSize; i++) {
                visited[BFS.front()] = 1;
                for (auto &j : rooms[BFS.front()]) {
                    if (visited[j] == 0) {
                        BFS.push(j);
                    }
                }
                BFS.pop();
            }
        }

        int res = 0;
        for_each(visited.begin(), visited.end(), [&res](int temp) {
            if (temp == 1) 
                res++;
        });
        return res == rooms.size();
    }
};