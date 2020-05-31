#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max(0);
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                max = std::max(max, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        return max;
    }
};