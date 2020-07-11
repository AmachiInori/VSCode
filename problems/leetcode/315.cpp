#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> sorted;
public:
    int binarySerch(int target) {
        if (sorted.empty()) return 0;
        int left = 0, right = sorted.size() - 1;
        int mid;
        while (right - left >= 2) {
            mid = (left + right) / 2;
            if (sorted[mid] >= target) right = mid - 1;
            else left = mid + 1;
        }
        if (target <= sorted[left]) return left;
        else if (target > sorted[right]) return right + 1;
        else return right;//注意边界条件
    }
    void ins(int val) {
        int loca = binarySerch(val);
        sorted.insert(sorted.begin() + loca, val);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res.insert(res.begin(), binarySerch(nums[i]));
            ins(nums[i]);
        }
        return res;
    }
};