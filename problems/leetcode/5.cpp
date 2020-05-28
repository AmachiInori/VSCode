/*
 * @Author: your name
 * @Date: 2020-04-25 19:03:49
 * @LastEditTime: 2020-04-25 19:24:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\5.cpp
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        int left, right;
        int max = 0, maxLeft, maxRight;
        int tempLength;
        for (int i = 0; i < s.length(); i++){
            left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                tempLength = right - left + 1;
                if (tempLength > max)
                    max = tempLength, maxLeft = left, maxRight = right;
                left--, right++;
            }
        }
        
        for (int i = 0; i < s.length() - 1; i++){
            if (s[i] == s[i + 1]) {
                left = i, right = i + 1;
                while (left >= 0 && right < s.length() && s[left] == s[right]){
                    tempLength = right - left + 1;
                    if (tempLength > max)
                        max = tempLength, maxLeft = left, maxRight = right;
                    left--, right++;
                }
            }
        }
        
        string res(max, 0);
        for (int i = maxLeft, j = 0; i <= maxRight; i++, j++)
            res[j] = s[i];
        
        return res;
    }
};

int main(){
    Solution s;
    string str = "";
    cout << s.longestPalindrome(str) << endl;
    system("pause");
    return 0;
}