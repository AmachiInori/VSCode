/*
 * @Author: your name
 * @Date: 2020-04-21 16:46:09
 * @LastEditTime: 2020-04-21 17:18:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\1248.cpp
 */
#include <iostream>
#include <vector>
#define isOdd(x) (x - (x / 2) * 2) //是奇数返回1
using std::vector;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(!nums.size()) return 0;
        int pointer = 1;
        int *index = new int[nums.size() + 2]{-1};
        for (int i = 0; i < nums.size(); i++){
            if (isOdd(nums[i])){
                index[pointer++] = i;
            }
        }
        index[pointer] = nums.size();

        int result = 0;
        for (int i = 1; i + k - 1 < pointer; i++)
            result += (index[i] - index[i - 1]) * (index[i + k] - index[i + k - 1]);
        
        return result;
    }
};