#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals.front());
        int resLoca = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= res[resLoca][1]) {
                res[resLoca][1] = max(res[resLoca][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
                resLoca++;
            }
        }
        return res;
    }
};