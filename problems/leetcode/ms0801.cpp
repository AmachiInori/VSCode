#include <iostream>
#include <vector>

using std::vector;

class Solution {
    int const mod = 1000000007;
public:
    int waysToStep(int n) {
        vector<int> dp(n + 3, 0);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            long temp = (long)dp[i - 1] + (long)dp[i - 2] + (long)dp[i - 3];
            dp[i] = temp % mod;
        }
        return dp[n];
    }
};