#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<vector<int>> dp = vector(prices.size(), vector(3,0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < dp.size(); i++) {
            dp[i][0] = std::max(dp[i - 1][2] - prices[i], dp[i - 1][0]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]);
        }
        return std::max(dp.back()[1], dp.back()[2]);
    }
};