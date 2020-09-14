#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int x = 1, y = 0;
        auto calcuA = [&x, &y]() {
            x = x * 2 + y;
        };
        auto calcuB = [&x, &y]() {
            y = y * 2 + x;
        };
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                calcuA();
            } else {
                calcuB();
            }
        }
        return x + y;
    }
};