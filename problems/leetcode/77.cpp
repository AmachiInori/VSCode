#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> now;
    int totSize;
    
    void runner(int begin, int end) {
        if (now.size() == totSize) {
            res.push_back(now);
            return;
        }
        for (size_t i = begin; i <= end; i++) {
            now.push_back(i);
            runner(i + 1, end);
            now.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        totSize = k;
        runner(1, n);
        return res;
    }
};