#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> zhengfang;
        for_each(rectangles.begin(), rectangles.end(), [&zhengfang](auto &temp) {
            zhengfang.push_back(min(temp[0], temp[1]));
        });
        int max = INT_MIN;
        unsigned int number = 0;
        for_each(zhengfang.begin(), zhengfang.end(), [&max, &number](auto &temp) {
            if (temp > max) {
                number = 1;
                max = temp;
            } else if (temp == max) {
                number++;
            }
        });
        return number;
    }
};