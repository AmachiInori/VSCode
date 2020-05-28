#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        vector<vector<int>> dp(grid.size());
        for (auto &i : dp) i = vector<int>(grid[0].size());
        dp[0][0] = grid[0][0];
        for (int i = 1; i < dp[0].size(); i++) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < dp.size(); i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for (int i = 1; i < dp.size(); i++)
            for (int j = 1; j < dp[i].size(); j++)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        return dp.back().back();
    }
};