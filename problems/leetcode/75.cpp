/*
 * @Author: your name
 * @Date: 2020-04-21 17:14:23
 * @LastEditTime: 2020-04-21 17:38:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\75.cpp
 */
#include <iostream>
#include <vector>
using std::vector;

class Solution{
public:
    void sortColors(vector<int>& nums){
        if (nums.size() <= 1) return;
        int zeroPointer = 0, twoPointer = nums.size() - 1;
        while (nums[zeroPointer] == 0){
            zeroPointer++;
            if (zeroPointer >= nums.size()) return;
        }
        while (nums[twoPointer] == 2){
            twoPointer--;
            if (twoPointer < 0) return;
        }
        for (int i = zeroPointer; i <= twoPointer; i++){
            if (nums[i] == 0){
                int temp = nums[zeroPointer];
                nums[zeroPointer] = 0;
                nums[i] = temp;
                zeroPointer++;
                i = zeroPointer;
            }else if (nums[i] == 2){
                int temp = nums[twoPointer];
                nums[twoPointer] = 2;
                nums[i] = temp;
                twoPointer--;
                i = zeroPointer;
            }
        }
    }
};