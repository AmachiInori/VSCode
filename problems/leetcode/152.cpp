#include <bits/stdc++.h>
using namespace std;

int maxThr(int a, int b, int c) {
    a = max(a, b);
    a = max(a, c);
    return a;
}

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = INT_MIN;
        int begin = 0;
        while (nums.back() == 0) {
            max = 0;
            nums.pop_back();
            if (nums.size() == 0) return 0;
        }
        while (nums[begin] == 0) {
            begin++;
            max = 0;
            if (nums.size() == 0) return 0;
        }
        if (nums.size() == 1) return std::max(max, nums[0]);
        for (int i = begin; i < nums.size(); i++) {
            if (nums[i] == 0) {
                vector<int> left(&nums[begin], &nums[i]);
                vector<int> right(&nums[i + 1], &nums[nums.size()]);
                return maxThr(maxProduct(left), maxProduct(right), 0);//你看你传的这个烂参
            }
        }
        vector<int> temp(nums.size() + 1, 1);
        for (int i = begin; i < nums.size(); i++)
            temp[i + 1] = temp[i] * nums[i];
        for (int i = begin; i < nums.size() + 1; i++) {
            for (int j = i + 1; j < nums.size() + 1; j++) {
                max = std::max(max, temp[j] / temp[i]);
            }
        }
        int test = temp[0];
        return max;
    }
};

int main(){
    Solution s;
    vector<int> test = {2,2,2,0,2,2};
    cout << s.maxProduct(test);
    return 0;
}