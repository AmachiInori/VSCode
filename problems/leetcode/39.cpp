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
        for (int i = lastPlace; i < candidates.size(); i++) {
            temp[i]++;
            runner(candidates, target - candidates[i], i);
            temp[i]--;
        }
        return;
    } 

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        temp = vector<int>(candidates.size(), 0);
        runner(candidates, target, 0);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> test = {2,3,6,7};
    s.combinationSum(test, 7);
    return 0;
}