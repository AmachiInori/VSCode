#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>>> hash;
        int preFirst = nums.back() - 1;
        for (int i = nums.size() - 1; i >= 3; i--) {
            if (preFirst == nums[i]) continue;
            if (nums[i] < target / 4) break;
            preFirst = nums[i];
            int preSecond = nums[i - 1] - 1;
            for (int j = i - 1; j >= 2; j--){
                if (nums[i] + nums[j] < target / 2) break;
                if (preSecond == nums[j]) continue;
                preSecond = nums[j];
                if(hash.find(nums[i] + nums[j]) != hash.end())
                    hash[nums[i] + nums[j]].push_back({j, i});
                else {
                    hash[nums[i] + nums[j]] = {{j, i}};
                }
            }
        }
        preFirst = nums[0] - 1;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (preFirst == nums[i]) continue;
            if (nums[i] > target / 4 + 1) break;
            preFirst = nums[i];
            int preSecond = nums[i + 1] - 1;
            for (int j = i + 1; j < nums.size() - 2; j++){
                if (preSecond == nums[j]) continue;
                if (nums[i] + nums[j] > target / 2 + 1) break;
                preSecond = nums[j];
                if (hash.find(target - nums[i] - nums[j]) != hash.end()) {
                    for (int k = 0; k < hash[target - nums[i] - nums[j]].size(); k++) {
                        if (hash[target - nums[i] - nums[j]][k].first > j)
                            res.push_back({nums[i], nums[j], nums[hash[target - nums[i] - nums[j]][k].first], nums[hash[target - nums[i] - nums[j]][k].second]});
                    }
                }
            }
        }
        return res;
    }
};