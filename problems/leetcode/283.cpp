#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (size_t i = 0, write_loca = 0; i < nums.size(); i++) {
            if (nums[i]) std::swap(nums[i], nums[write_loca++]);
        }
    }
};