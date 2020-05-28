#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> hash(nums.size(), 0);
        for (auto &i : nums) {
            if (hash[i]) return i;
            hash[i] = true;
        }
        return 0;
    }
};