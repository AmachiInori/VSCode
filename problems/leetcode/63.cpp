#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size());
        for (auto &i : dp) i.resize(obstacleGrid[0].size());
        dp[0][0] = 1;
        for (int i = 0; i < obstacleGrid.size(); i++)
            for (int j = 0; j < obstacleGrid[i].size(); j++)
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
        for (int i = 1; i < obstacleGrid[0].size(); i++)
            if (obstacleGrid[0][i] != 1) dp[0][i] = dp[0][i - 1];
        for (int i = 1; i < obstacleGrid.size(); i++)
            if (obstacleGrid[i][0] != 1) dp[i][0] = dp[i - 1][0];
        
        for (int i = 1; i < obstacleGrid.size(); i++)
            for (int j = 1; j < obstacleGrid[i].size(); j++)
                if (obstacleGrid[i][j] != 1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp.back().back();
    }
};