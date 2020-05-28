/*
 * @Author: your name
 * @Date: 2020-04-28 19:55:55
 * @LastEditTime: 2020-04-28 20:22:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\ms56.cpp
 */
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int preRes = 0, diffPoint = 1;
        for (int i : nums)
            preRes ^= i;
        while (!(diffPoint & preRes)) diffPoint <<= 1;
        int resA = 0, resB = 0;
        for (int i : nums) {
            if (i & diffPoint) resA ^= i;
            else resB ^= i;
        }
        return {resA, resB};
    }
};