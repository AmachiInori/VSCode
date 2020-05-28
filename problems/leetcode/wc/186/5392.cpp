/*
 * @Author: your name
 * @Date: 2020-04-26 10:32:57
 * @LastEditTime: 2020-04-26 10:40:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\wc\186\1.cpp
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    int maxScore(string s){
        vector<int> index(s.length(), 0);
        int count = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '0') count++;
            index[i] = count;
        }
        int max = 0;
        for (int i = 0; i < s.length() - 1; i++){
            int temp = index[i] + s.length() - i - 1 - (count - index[i]);
            if (max < temp) max = temp;
        }
        return max;
    }
};