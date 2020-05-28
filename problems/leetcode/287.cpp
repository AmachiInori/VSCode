#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left(0), right(nums.size() - 1);
        int mid, res;
        while (left <= right) {
            int temp(0);
            mid = (left + right) / 2;
            for (auto &i : nums) if (i <= mid) temp++;
            if (temp > mid) {
                res = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return res;
    }
};