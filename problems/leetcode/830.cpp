#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int last = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != s[last]) {
                if (i - last >= 3) {
                    res.push_back({last, i - 1});
                }
                last = i;
            }
        }
        if (s.size() - last >= 3) {
            res.push_back({last, int(s.size() - 1)});
        }
        return res;
    }
};