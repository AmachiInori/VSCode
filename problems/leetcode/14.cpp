/*
 * @Author: your name
 * @Date: 2020-04-19 19:22:11
 * @LastEditTime: 2020-04-19 19:49:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\14.cpp
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int loca, minLength = strs[0].length();
        bool isBreak = 0;
        for (int i = 0; i < strs.size(); i++){
            if (strs[i].length() < minLength) minLength = strs[i].length();
        }
        for (loca = 0; loca < minLength; loca++){
            for (int i = 0; i < strs.size(); i++){
                if (strs[0][loca] != strs[i][loca]){
                    isBreak = 1;
                    break;
                }
            }
            if (isBreak) break;
        }
        string result(loca, 0);
        for (int i = 0; i < loca; i++){
            result[i] = strs[0][i];
        }
        return result;
    }
};