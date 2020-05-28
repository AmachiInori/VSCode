/*
 * @Author: your name
 * @Date: 2020-04-28 21:04:42
 * @LastEditTime: 2020-04-28 21:18:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\16re.cpp
 */
#include <vector>
#include <algorithm>
#include <math.h>

using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int left, right;
        int minErr = INT_MAX;
        int count = 0;

        for (int i = 0; i < nums.size() - 2; i++){
            left = i + 1;
            right = nums.size() - 1;
            while (right - left > 0){
                int temp = target - nums[i] - nums[right] - nums[left];
                if (abs(temp) < abs(minErr)) minErr = temp;
                if (temp > 0) left++;
                else if (temp < 0) right--;
                else return target;
            }
        }
        
        return target - minErr;
    }
};