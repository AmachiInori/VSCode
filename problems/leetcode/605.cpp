#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        for (size_t i = 1; i < flowerbed.size() - 1; ++i) {
            if (flowerbed[i]) continue;
            if (!(flowerbed[i - 1] || flowerbed[i + 1])) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};