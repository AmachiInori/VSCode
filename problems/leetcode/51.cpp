#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> result;
    vector<pair<int, int>> nowQueue;
    int _n;
public:
    void doQueuesP(int remain) {
        if (remain == 0) {
            string base(_n, '.');
            vector<string> res;
            for (int i = 0; i < _n; i++) {
                string temp(base);
                for_each(nowQueue.begin(), nowQueue.end(), [&temp, i](auto &temp_pair){
                    if (temp_pair.first == i) {
                        temp[temp_pair.second] = 'Q';
                    }
                });
                res.push_back(temp);
            }
            result.push_back(res);
            return;
        }
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _n; j++) {
                bool isLocaGood = true;
                for (auto &queue : nowQueue) {
                    if (queue.first == i || queue.second == j) {
                        isLocaGood = false;
                        break;
                    }
                    if (queue.first + queue.second == i + j || queue.first - queue.second == i - j) {
                        isLocaGood = false;
                        break;
                    }
                }
                if (isLocaGood) {
                    nowQueue.push_back({i, j});
                    doQueuesP(remain - 1);
                    nowQueue.pop_back();
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        _n = n;
        doQueuesP(n);
        sort(result.begin(), result.end());
        auto newEnd = unique(result.begin(), result.end());
        result.erase(newEnd, result.end());
        return result;
    }
};