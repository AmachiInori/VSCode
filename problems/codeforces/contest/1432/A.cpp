/*
 * @Author: your name
 * @Date: 2020-04-26 22:40:59
 * @LastEditTime: 2020-04-26 23:47:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\codeforces\contest\1432\A.cpp
 */
#include <iostream>
#include <math.h>

int main(){
    int times;
    std::cin >> times;
    for (int i = 0; i < times; i++){
        long arr;
        long long a, b;
        unsigned long long resultA, resultB;
        unsigned long long result;
        long long firstValue, secondValue;
        std::cin >> a >> b;
        std::cin >> firstValue >> secondValue;
        arr = abs(a) > abs(b) ? abs(b) : abs(a);
        resultA = abs(b - a) * firstValue + arr * secondValue;
        resultB = (abs(a) + abs(b)) * firstValue;
        if (resultA > resultB) result = resultB;
        else result = resultA;
        std::cout << result << std::endl;
    }

    return 0;
}