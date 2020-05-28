#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res = {{}};
    vector<int> temp;
public:
    void runner(vector<int>& nums, int loca) {
        for (int i = loca; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            res.push_back(temp);
            runner(nums, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        runner(nums, 0);
        return res;
    }
};