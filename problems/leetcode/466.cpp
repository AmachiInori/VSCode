/*
 * @Author: your name
 * @Date: 2020-04-19 16:53:05
 * @LastEditTime: 2020-04-19 19:13:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\466. 统计重复个数.cpp
 */
//https://leetcode-cn.com/problems/count-the-repetitions/
//. 统计重复个数
#include <iostream>
#include <string>
using std::string;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;
        for (int i = 0; i < s2.length(); i++){ //判断有无不存在元素
            bool exist = 0;
            for (int j = 0; j < s1.length(); j++){
                if (s2[i] == s1[j]) exist = 1;
            }
            if (!exist) return 0;
        }
        
        int count = 0;
        int pointera = 0, pointerb = 0, lastPointer = 0, times;
        bool isFinish = 0;
        int firstcount = 0, secondcount = 0;

        while (true){
            if (s1[pointera] == s2[pointerb]){
                pointera++, pointerb++;
            }else {
                pointera++;
            }
            count++;

            if (pointera == s1.length()) pointera = 0;
            if (pointerb == s2.length()) {
                if (!isFinish){
                    times = 0;
                    isFinish = 1;
                    lastPointer = pointera;
                    firstcount = count;
                }else {
                    times++;
                    if (pointera = lastPointer){
                        secondcount = count - firstcount;
                        break;
                    }
                }
                pointerb = 0;
            }
        }

        return ((n1 * s1.length() - firstcount) / secondcount * times + 1) / n2;
/*
        while (s1.length() > s2.length()){
            if (s1[pointera] == s2[pointerb]){
                pointera++, pointerb++;
            }else {
                pointera++;
            }

            if (pointerb == s2.length()) {
                pointerb = 0;
                count++;
            }
            if (pointera == s1.length()) {
                if (!isFinish){
                    firstcount = count;
                }else {
                    secondcount = count - firstcount;
                    break;
                }
                isFinish = 1;
                pointera = 0;
            }
        }

        return s1.length() <= s2.length() ? ((n1 * s1.length() - firstcount) / secondcount + 1) / n2 : ((n1 - 1) * secondcount + firstcount) / n2;
*/    
    }
};

int main(){
    string a, b;
    int n, m;
    std::cin >> a >> n >> b >> m;
    Solution s;
    std::cout << s.getMaxRepetitions(a, n, b, m);
    system("pause");
    return 0;
}