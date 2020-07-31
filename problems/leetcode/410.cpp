#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<long>> dp(nums.size() + 1, vector<long>(m + 1, INT_MAX));
        vector<long> sum(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        dp[0][0] = 0;
        for(int i = 1; i <= nums.size(); i++) {
            for(int j = 1; j <= i && j <= m; j++) {
                for(int k = 0; k <= i - 1; k++) {
                    dp[i][j] = min(max(dp[k][j - 1], sum[i] - sum[k]), dp[i][j]);
                }
            }
        }
        return dp.back().back();
    }
};