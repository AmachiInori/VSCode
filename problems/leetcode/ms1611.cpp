#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k == 0) return (vector<int>){};
        if (shorter == longer) return (vector<int>){k * shorter};
        vector<int> res = vector(k + 1, 0);
        res[0] = k * shorter;
        for (int i = 1; i < res.size(); i++) {
            res[i] = res[i - 1] + longer - shorter;
        }
        return res;
    }
};