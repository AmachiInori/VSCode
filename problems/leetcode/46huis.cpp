/*
 * @Author: your name
 * @Date: 2020-04-25 16:34:03
 * @LastEditTime: 2020-04-25 16:34:04
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\46.cpp
 */
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> temp(nums.size(), 0);
        runner(nums, used, res, temp, 0);
        return res;
    }
    void runner(vector<int>& nums, vector<bool>& used, vector<vector<int>>& result, vector<int> temp, int depth) {
        if (depth == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                temp[depth] = nums[i];
                used[i] = true;
                runner(nums, used, result, temp, depth + 1);
                used[i] = false;
            }
        }
    }
};