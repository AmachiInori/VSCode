/*
 * @Author: your name
 * @Date: 2020-04-18 16:13:17
 * @LastEditTime: 2020-04-18 16:36:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\11盛水.cpp
 */
/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai)
。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0, temp = 0;
        while (right - left > 0)
        {
            temp = height[left] > height[right] ? height[right] : height[left];
            temp *= right - left;
            if (temp > result) result = temp;
            if (height[left] > height[right]) right--;
            else left++;
        }
        return result;
    }
};