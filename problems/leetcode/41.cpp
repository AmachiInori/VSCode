#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        for (int i(0); i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i]]) swap(nums[nums[i]], nums[i]);
        }
        for (int i(1); i < nums.size(); i++) {
            if (nums[i] != i) return i;
        }
        if (nums[0] != nums.size()) return nums.size();
        return nums.size() + 1;
    }
};