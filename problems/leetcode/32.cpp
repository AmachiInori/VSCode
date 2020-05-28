/*
 * @Author: your name
 * @Date: 2020-04-23 20:56:52
 * @LastEditTime: 2020-04-23 21:12:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\32.cpp
 */
#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> str = vector(s.length(), -1);
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ')'){
                for (int j = i; j >= 0; j--){
                    if (s[j] == '(' && str[j] == -1){
                        str[i] = j; //随你赋值，只要别是-1就好啦
                        str[j] = i; //随你赋值，只要别是-1就好啦
                        break;
                    }
                }
            }
        }
        vector<int> index = vector(s.length() + 2, -1);
        bool isWholeTrue = true;
        int pointer = 1;
        for (int i = 0; i < str.size(); i++){
            if (str[i] == -1){
                isWholeTrue = false;
                index[pointer++] = i;
            }
        }
        index[pointer] = s.length();

        if (isWholeTrue) return s.length();
        else {
            int max = -1;
            for (int i = 0; i < s.length() + 1; i++){
                int temp = index[i + 1] - index[i] - 1;
                if (temp > max) max = temp;
            }
            return max;
        }
    }
};