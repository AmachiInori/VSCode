/*
 * @Author: your name
 * @Date: 2020-04-25 19:29:08
 * @LastEditTime: 2020-04-25 19:38:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\27.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums[i] = nums[nums.size() - 1];
                nums.pop_back();
                i--;
            }
        }
        return nums.size();
    }
};