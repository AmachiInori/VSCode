# include <bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> sumArr;
public:
    explicit NumArray(vector<int>& nums) : sumArr({ 0 }) { 
        int now_sum = 0;
        for_each(nums.begin(), nums.end(), [&now_sum, this](auto temp) {
            now_sum += temp;
            this->sumArr.push_back(now_sum);
        });
    }
    int sumRange(int i, int j) {
        return sumArr[j + 1] - sumArr[i];
    }
};