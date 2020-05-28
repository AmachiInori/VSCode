/*
 * @Author: your name
 * @Date: 2020-04-23 18:50:54
 * @LastEditTime: 2020-04-23 20:26:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\08.11.cpp
 */
#include <iostream>

class Solution {
public:
    int waysToChange(int n) {
        const long int mod = 1000000007;
        int index[4] = {25, 10, 5, 1};
        int *dp = new int[n + 1]{1};
        
        for (int i = 0; i < 4; ++i) {
            int temp = index[i];
            for (int i = temp; i <= n; ++i) {
                dp[i] = (dp[i] + dp[i - temp]) % mod;
            }
        }
        return dp[n];
    }
};

int main(){
    int n;
    std::cin >> n;
    Solution s;
    int re = s.waysToChange(n);
    std::cout << re;
    system("pause");
    return 0;
}