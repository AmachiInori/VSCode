#include <iostream>
#include <vector>

using std::vector;

struct part{
    int lMax, rMax, tSum, mSum;
};

class Solution {
public:
    part merge(part left, part right) {
        int newlMax = std::max(left.tSum + right.lMax, left.lMax);
        int newrMax = std::max(left.rMax + right.tSum, right.rMax);
        int newtSum = left.tSum + right.tSum;
        int newmSum = std::max(left.mSum, right.mSum);
        newmSum = std::max(newmSum, left.rMax + right.lMax);
        return (part){newlMax, newrMax, newtSum, newmSum};
    }
    part get(int left, int right, vector<int>& nums) {
        if (left == right) return (part){nums[left], nums[left], nums[left], nums[left]};
        int mid = (right + left) / 2;
        return merge(get(left, mid, nums), get(mid + 1, right, nums));
    }
    int maxSubArray(vector<int>& nums) {
        return get(0, nums.size() - 1, nums).mSum;
    }
};