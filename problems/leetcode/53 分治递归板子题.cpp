#include <iostream>
#include <vector>

using std::vector;

class Solution{
public:
    struct part{
        int leftSum, rightSum, totalSum, maxSum;
    };
    
    part merge(part a, part b){
        part res;
        res.leftSum = (a.leftSum > a.totalSum + b.leftSum) ? a.leftSum : a.totalSum + b.leftSum;
        res.rightSum = (b.rightSum > a.rightSum + b.totalSum) ? b.rightSum : a.rightSum + b.totalSum;
        volatile int temp = (b.maxSum > a.maxSum) ? b.maxSum : a.maxSum;
        res.maxSum = (temp > a.rightSum + b.leftSum) ? temp : a.rightSum + b.leftSum;
        res.totalSum = a.totalSum + b.totalSum;
        return res;
    }
    part divide(vector<int>& nums, int left, int right) {
        if (left == right) return (part){nums[left], nums[left], nums[left], nums[left]};
        int mid = (left + right) / 2;
        return merge(divide(nums, left, mid), divide(nums, mid + 1, right));
    }
    int maxSubArray(vector<int>& nums){
        return divide(nums, 0, nums.size() - 1).maxSum;
    }
};