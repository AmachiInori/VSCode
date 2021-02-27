#include <bits/stdc++.h>
using namespace std;

class Solution {
    int res = 0;
    vector<int> temp;
    vector<bool> used;
    void __runner(vector<int>& nums) {
        if (temp.size() == 4) {
            if (temp[0] * temp[1] == temp[2] * temp[3]) {
                res++;
            }
            return;
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            temp.push_back(nums[i]);
            __runner(nums);
            used[i] = false;
            temp.pop_back();
        }
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        if (nums.size() < 4) return 0;
        used = vector(nums.size(), false);
        __runner(nums);
        return res;
    }
};