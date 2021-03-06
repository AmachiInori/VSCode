#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> temp;
public:
    void runner(vector<int>& candidates, int target, int lastPlace){
        if (target == 0) {
            res.push_back({});
            for (int i = 0; i < temp.size(); i++) {
                for (int j = 0; j < temp[i]; j++) {
                    res.back().push_back(candidates[i]);
                }
            }
            return;
        }
        if (target < 0) return;
        for (int i = lastPlace + 1; i < candidates.size(); i++) {
            temp[i]++;
            runner(candidates, target - candidates[i], i);
            temp[i]--;
        }
        return;
    } 

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        temp = vector<int>(candidates.size(), 0);
        runner(candidates, target, -1);
        unique(res.begin(), res.end());
        
        return res;
    }
};