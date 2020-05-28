#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res(0);
        for (int i(0); i < grid.size(); i++) {
            for (int j(0); j < grid[i].size(); j++) {
                bool isfin(false);
                if (grid[i][j] == 0) continue;
                for (int k(0); k < grid[i].size(); k++) {
                    if (grid[i][k] == 1 && k != j) {
                        res++;
                        isfin = true;
                        break;
                    }
                }
                if (isfin) continue;
                for (int k(0); k < grid.size(); k++) {
                    if (grid[k][j] == 1 && k != i) {
                        res++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};