#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<pair<int, int>> index(nums.size(), (pair<int, int>){0, 0});
        int temp(1);
        for (int i(0); i < index.size(); i++) {
            index[i].first = temp;
            temp *= nums[i];
        }
        temp = 1;
        for (int i(index.size() - 1); i >= 0; i--) {
            index[i].second = temp;
            temp *= nums[i];
        }
        vector<int> res(nums.size());
        for (int i(0); i < res.size(); i++) 
            res[i] = index[i].first * index[i].second;
        return res;
    }
};