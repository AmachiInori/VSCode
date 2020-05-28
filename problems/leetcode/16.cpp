/*
 * @Author: your name
 * @Date: 2020-04-28 20:22:53
 * @LastEditTime: 2020-04-28 21:04:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\16.cpp
 */
#include <vector>
#include <algorithm>
#include <math.h>

using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int minErr = INT_MAX;
        int count = 0;

        while (right - left >= 2){
            int preErr = INT_MAX;
            if (nums[left] + nums[right] >= target) {
                for (int i = left + 1; i < right; i++){
                    int temp = target - nums[i] - nums[left] - nums[right];
                    if (abs(temp) <= abs(minErr)) minErr = temp;
                    if (abs(temp) > preErr) break;
                    preErr = abs(temp);
                }
            }else {
                for (int i = right - 1; i > left; i--){
                    int temp = target - nums[i] - nums[left] - nums[right];
                    if (abs(temp) <= abs(minErr)) minErr = temp;
                    if (abs(temp) > preErr) break;
                    preErr = abs(temp);
                }
            }
            if (count == 0) left++, count++;
            else right--, count--;
        }

        return target - minErr;
    }
};