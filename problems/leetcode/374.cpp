#include <bits/stdc++.h>
using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            if (guessNumber((left + right) / 2) == 0) return (left + right) / 2;
            else if (guessNumber((left + right) / 2) == 1) right = (left + right - 1) / 2;
            else left = (left + right + 1) / 2;
        }
        return 0;
    }
};