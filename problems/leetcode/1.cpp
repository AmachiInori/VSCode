/*
 * @Author: your name
 * @Date: 2020-04-19 19:18:32
 * @LastEditTime: 2020-04-25 17:22:58
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\1.cpp
 */
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int temp;
        vector<int> result(2, 0);
        for (int i = 0; i < nums.size() - 1; i++){
            temp = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[j] == temp) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
        return result;
    }
};