/*
 * @Author: your name
 * @Date: 2020-04-20 11:09:10
 * @LastEditTime: 2020-04-20 13:04:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\466二度.cpp
 */
#include <string>
#include <iostream>
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
        
        int pointerA = 0, pointerB = 0;
        bool isStart = 0, isPointerAFinished = 0, isPointerBFinished = 0;
        int start = 0, trueFinal = 0;
        int times = 0, timesA = 1;
        while (true){
            if (s1[pointerA] == s2[pointerB]){
                if (!isStart){
                    start = pointerA;
                    isStart = 1;
                }
                pointerA++;
                pointerB++;
            }else {
                pointerA++;
            }
            if (pointerB == s2.length()){
                trueFinal = pointerA - 1;
                if(trueFinal == ((start - 1) < 0 ? (s1.length() - 1) : (start - 1))) break;
                else {
                    timesA--;
                    while (true){
                        if (pointerB == s2.length()){
                            times++;
                            pointerB = 0;
                        }
                        if (pointerA == s1.length()){
                            pointerA = 0;
                            timesA++;
                        }
                        if (pointerA == 0 && pointerB == 0){
                            break;
                        }
                        if (s1[pointerA] == s2[pointerB]){
                            pointerB++;
                            pointerA++;
                        } else pointerA++;
                    }
                    break;
                }
            }
            if (pointerA == s1.length()){
                pointerA = 0;
                timesA++;
            }
        }

        if (times != 0) return n1 * times / timesA / n2;
        else return n1 / timesA / n2;
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