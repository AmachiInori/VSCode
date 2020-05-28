#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m);
        for (auto &i : dp) i.resize(n);
        for (auto &i : dp) i[0] = 1;
        for (auto &i : dp[0]) i = 1;
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp.back().back();
    }
};