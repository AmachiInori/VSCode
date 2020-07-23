#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(), vector(dungeon[0].size(), 0));
        dp.back().back() = dungeon.back().back() - 1;
        if (dp.back().back() >= 0) dp.back().back() = -1;
        for (int i = dungeon.back().size() - 2; i >= 0; i--) {
            dp.back()[i] = dp.back()[i + 1] + dungeon.back()[i];
            if (dp.back()[i] >= 0) dp.back()[i] = -1;
        }
        for (int i = dungeon.size() - 2; i >= 0; i--) {
            dp[i].back() = dp[i + 1].back() + dungeon[i].back();
            if (dp[i].back() >= 0) dp[i].back() = -1;
        }
        for (int i = dungeon.size() - 2; i >= 0; i--) {
            for (int j = dungeon.back().size() - 2; j >= 0; j--) {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + dungeon[i][j];
                if (dp[i][j] >= 0) dp[i][j] = -1;
            }
        }
        return -dp[0][0];
    }
};
