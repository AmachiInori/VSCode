/*
 * @Author: your name
 * @Date: 2020-04-18 16:43:09
 * @LastEditTime: 2020-04-19 10:19:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\42接雨水.cpp
 */
//https://leetcode-cn.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {
        if (!height.size()) return 0;
        int loca = 0;
        for (int i = 0; i < height.size(); i++)
            if (height[i] > height[loca]) loca = i;
        return left(height, loca) + right(height, loca);
    }
    int left(vector<int>& height, int start){
        if (start == 0) return 0;
        int loca = 0;
        for (int i = start - 1; i >= 0; i--)
            if (height[i] > height[loca]) loca = i;
        return calcu(height, loca, start) + left(height, loca);
    }
    int right(vector<int>& height, int start){
        if (start == height.size() - 1) return 0;
        int loca = height.size() - 1;
        for (int i = start + 1; i < height.size() - 1; i++)
            if (height[i] > height[loca]) loca = i;
        return calcu(height, start, loca) + right(height, loca);
    }
    int calcu(vector<int>& height, int start, int final){
        int res = (height[start] < height[final] ? height[start] : height[final]) * (final - start + 1);
        for (int i = start; i <= final; i++)
            res -= height[i] > (height[start] < height[final] ? height[start] : height[final]) ? (height[start] < height[final] ? height[start] : height[final]) : height[i];
        return res;
    }
};