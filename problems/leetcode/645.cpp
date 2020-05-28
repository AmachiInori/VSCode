#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<bool> hash(nums.size() + 1, 0);
        int fengnu, sum = 0;
        for (auto &i : nums) {
            if (hash[i])
                fengnu = i;
            hash[i] = true;
            sum += i;
        }
        return {fengnu, ((int)nums.size() + 1) * (int)nums.size() / 2 - sum + fengnu};
    }
};