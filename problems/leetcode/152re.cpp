#include <bits/stdc++.h>
using namespace std;

int maxThr(int a, int b, int c) {
    a = max(a, b);
    a = max(a, c);
    return a;
}

int minThr(int a, int b, int c) {
    a = min(a, b);
    a = min(a, c);
    return a;
}

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxDP(nums.size(), nums[0]);
        vector<int> minDP(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            maxDP[i] = maxThr(maxDP[i - 1] * nums[i], nums[i], minDP[i - 1] * nums[i]);
            minDP[i] = minThr(minDP[i - 1] * nums[i], nums[i], maxDP[i - 1] * nums[i]);
        }
        return *max_element(maxDP.begin(), maxDP.end());
    }
};