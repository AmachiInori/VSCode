#include <iostream>
#include <vector>
using std::vector;

class Solution {
    vector<int> result;
    const int index[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
public:
    int getSum(int x) {
        int res = 0;
        for (long i = 1; x / i > 0; i *= 10)
            res += index[(x - x / (i * 10) * (i * 10)) / i];
        return res;
    }
    bool isHappy(int n) {
        int temp = n;
        while (temp != 1) {
            temp = getSum(temp);
            for (int i = 0; i < result.size(); i++)
                if (temp == result[i]) return false;
            result.push_back(temp);
        }
        return true;
    }
};