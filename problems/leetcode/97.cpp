#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, false)); //不可用bool，或赋值运算会出问题。
        dp[0][0] = true;
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i > 0) dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                if (j > 0) dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp.back().back();
    }
};