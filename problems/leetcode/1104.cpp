#include <bits/stdc++.h>
using namespace std;

class Solution {
    stack<int> res;
public:
    void runner(int label, int power) {
        res.push(label);
        if (power == 1) return;
        runner(power - (label - power) / 2 - 1, power / 2);
    }
    vector<int> pathInZigZagTree(int label) {
        int power = 1;
        for (int i = 0; ; i++) {
            if (power * 2 > label) break;
            power <<= 1;
        }
        runner(label, power);
        vector<int> resa;
        while (!res.empty()) {
            resa.push_back(res.top());
            res.pop();
        }
        return resa;
    }
};