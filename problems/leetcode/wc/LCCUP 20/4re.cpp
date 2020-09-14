#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        vector<int> dp(target + 1);
        dp[0] = dp[1] = inc;
        for (int i = 0; i < target + 1; i++) {
            dp[i] = inc * i;
            for (int j = 0; j < jump.size(); j++) {
                dp[i] = min(dp[i], dp[i / jump[j]] + i % jump[j] * inc + cost[j]);
                dp[i] = min(dp[i], (dp[i / jump[j] + 1]) + (jump[j] - i % jump[j]) * dec + cost[j]);
            }
        }
        return dp.back();
    }
};