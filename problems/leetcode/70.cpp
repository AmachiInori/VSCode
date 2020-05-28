#include <iostream>
#include <vector>

using std::vector;

class Solution {
    vector<int> dp;
public:
    int climbStairs(int n) {
        dp = vector<int>(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        return climbStarisRunner(n);
    }
    int climbStarisRunner(int n){
        if (n < 0) return 0;
        if (dp[n] != 0) return dp[n];
        int res = climbStarisRunner(n - 1) + climbStarisRunner(n - 2);
        dp[n] = res;
        return res;
    }
};

int main(){
    Solution s;
    s.climbStairs(2);
    return 0;
}