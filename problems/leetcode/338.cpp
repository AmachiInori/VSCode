#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        if (num == 0) return ret;
        for (size_t i = 1; i < ret.size(); i++) {
            if (i % 2) ret[i] = ret[i / 2] + 1;
            else ret[i] = ret[i / 2];
        }
        return ret;
    }
};
