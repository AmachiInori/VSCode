#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int> dp = vector<int>(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i < nums.size() + 1; i++){
            dp[i] = dp[i - 1] > (dp[i - 2] + nums[i - 1]) ? dp[i - 1] : (dp[i - 2] + nums[i - 1]);
        }
        return dp[nums.size()];
    }
};
