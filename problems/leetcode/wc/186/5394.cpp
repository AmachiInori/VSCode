/*
 * @Author: your name
 * @Date: 2020-04-26 11:07:34
 * @LastEditTime: 2020-04-26 12:24:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\wc\186\5394.cpp
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums){
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i].size() - (nums.size() - i);
            if (temp > maxLength) maxLength = temp;
        }
        vector<vector<int>> str(nums.size() + maxLength);
        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums[i].size(); j++){
                str[i + j].push_back(nums[i][j]);
                count++;
            }
        }
        vector<int> res(count);
        int pointer = 0;
        for (int i = 0; i < str.size(); i++){
            for (int j = str[i].size() - 1; j >= 0; j--){
                res[pointer] = str[i][j];
                pointer++;
            }
        }
        return res;
    }
};