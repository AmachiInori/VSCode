/*
 * @Author: your name
 * @Date: 2020-04-28 21:18:48
 * @LastEditTime: 2020-04-28 21:39:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\38.cpp
 */
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<string> result;
public:
    string countAndSay(int n) {
        result.resize(n);
        result[0] = "1";
        for (int i = 1; i < n; i++)
            runner(i);
        return result[n - 1];
    }

    void runner(int n) {
        char theChar, prechar = result[n - 1][0];
        int length = 0;
        for (int i = 0; i < result[n - 1].length(); i++){
            theChar = result[n - 1][i];
            if (theChar == prechar) length++;
            else {
                if (length == 0) length++;
                string temp = std::to_string(length);
                for (int i = 0; i < temp.length(); i++){
                    result[n].push_back(temp[i]);
                }
                result[n].push_back(prechar);
                prechar = theChar;
                length = 1;
            }
        }
        string temp = std::to_string(length);
        for (int i = 0; i < temp.length(); i++){
            result[n].push_back(temp[i]);
        }
        result[n].push_back(theChar);
        prechar = theChar;
    }
};

int main(){
    Solution s;
    std::cout << s.countAndSay(10) << std::endl;
    system("pause");
    return 0;
}