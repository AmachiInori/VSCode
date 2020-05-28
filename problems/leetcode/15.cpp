/*
 * @Author: your name
 * @Date: 2020-04-25 17:33:23
 * @LastEditTime: 2020-04-25 17:49:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\15.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> temp(3, 0);
        sort(nums.begin(), nums.end());
        runner(nums, used, res, temp, 0, 0);
        
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        
        return res;
    }

    void runner(vector<int>& nums, vector<bool>& used, vector<vector<int>>& result, vector<int> temp, int depth, int loca) {
        if (depth == 3) {
            if(temp[0] + temp[1] + temp[2] == 0) result.push_back(temp);
            return;
        }
        for (int i = loca; i < nums.size(); i++) {
            if (!used[i]) {
                temp[depth] = nums[i];
                used[i] = true;
                runner(nums, used, result, temp, depth + 1, i + 1);
                used[i] = false;
            }
        }
    }
};