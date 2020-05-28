/*
 * @Author: your name
 * @Date: 2020-04-24 17:12:36
 * @LastEditTime: 2020-04-24 18:24:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\m51.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        return MSort(nums, 0, nums.size() - 1, temp);
    }
    int MSort(vector<int>& nums, int left, int right, vector<int>& result) {
        if (left >= right) return 0;
        int res = 0;
        int center = (right + left) / 2; //向左倾向的均值
        res += MSort(nums, left, center, result) + MSort(nums, center + 1, right, result);

        int lPoint = left, rPoint = center + 1;
        int pos = lPoint;
        while (lPoint <= center && rPoint <= right) {
            if (nums[lPoint] > nums[rPoint]) {
                res += center - lPoint + 1;
                result[pos++] = nums[rPoint++];
            }
            else result[pos++] = nums[lPoint++];
        }
        while (lPoint <= center) result[pos++] = nums[lPoint++];
        while (rPoint <= right) result[pos++] = nums[rPoint++];
        for (int i = left; i <= right; i++) nums[i] = result[i];
        return res;
    }
};

int main(){
    Solution s;
    vector<int> x({1, 3, 2, 3, 1});
    std::cout << s.reversePairs(x);
    system("pause");
    return 0;
}