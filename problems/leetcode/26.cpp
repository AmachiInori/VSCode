/*
 * @Author: your name
 * @Date: 2020-04-25 19:38:45
 * @LastEditTime: 2020-04-26 12:06:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\26.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int> &nums){
        for (int i = 0; i < nums.size(); i++){
            int count = 0;
            int pointer = i;
            while (pointer < nums.size() - 1 && nums[pointer] == nums[pointer + 1]){
                pointer++;
                count++;
            }
            for (int j = pointer + 1; j < nums.size(); j++) nums[j - count] = nums[j];
            for (int j = 0; j < count; j++) nums.pop_back();
        }
        return nums.size();
    }
};