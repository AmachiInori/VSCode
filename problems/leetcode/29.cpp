/*
 * @Author: your name
 * @Date: 2020-04-24 19:41:41
 * @LastEditTime: 2020-04-24 22:20:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\29.cpp
 */
#include <iostream>

class Solution {
    long index[32];
    long twoPower[32];
    long const max = 2147483647;
    long const min = -2147483648;
public:
    int divideRunner(long dividend, long divisor) {
        if (dividend < divisor) return 0;
        int i;
        int result = 0;
        for (i = 1; i < 32; i++)
            if (dividend - index[i] <= index[i]) break;
        result += twoPower[i] + divideRunner(dividend - index[i], divisor);
        return result;
    }

    int divide(long dividend, long divisor) {
        int isResultNeg = 1;
        if (dividend < 0) dividend = -dividend, isResultNeg = -isResultNeg;
        if (divisor < 0) divisor = -divisor, isResultNeg = -isResultNeg;
        long result;
        if (divisor == 1) result = isResultNeg * dividend;
        else{
            index[0] = 1, index[1] = divisor;
            twoPower[0] = 0, twoPower[1] = 1;
            for (int i = 2; i < 32; i++) {
                index[i] = index[i - 1] + index[i - 1];
                twoPower[i] = twoPower[i - 1] + twoPower[i - 1];
            }
            result = isResultNeg * divideRunner(dividend, divisor);
        }
        if (result > max || result < min) return max;
        else return result;
    }
};

int main() {
    Solution s;
    std::cout << s.divide(10, 3);
    system("pause");
    return 0;
}