#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        unordered_map<int, int> hash;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
            hash[nums[i]] = i;
        int preN1 = nums[0] + 1;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == preN1) continue;
            preN1 = nums[i];
            int preN2 = nums[i + 1] + 1;
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (nums[j] == preN2) continue;
                preN2 = nums[j];
                int preN3 = nums[j + 1] + 1;
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[k] == preN3) continue;
                    preN3 = nums[k];
                    if (hash.find(target - nums[i] - nums[j] - nums[k]) != hash.end())
                        if (hash[target - nums[i] - nums[j] - nums[k]] > k)
                            res.push_back({nums[i], nums[j], nums[k], target - nums[i] - nums[j] - nums[k]});
                }
            }
        }
        return res;
    }
};