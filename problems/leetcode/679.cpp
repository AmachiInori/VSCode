#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> fir = {(double)nums[0] + nums[1], (double)nums[0] - nums[1], (double)nums[0] * nums[1], (double)nums[0] / nums[1]};
        vector<double> sec = {(double)nums[1] + nums[2], (double)nums[1] - nums[2], (double)nums[1] * nums[2], (double)nums[1] / nums[2]};
        vector<double> thr = {(double)nums[2] + nums[3], (double)nums[2] - nums[3], (double)nums[2] * nums[3], (double)nums[2] / nums[3]};
        bool res = false;
        for (int i = 0; i < 4; i++) {
            res = res || judgePoint3({fir[i], (double)nums[2], (double)nums[3]});
            res = res || judgePoint3({(double)nums[0], sec[i], (double)nums[3]});
            res = res || judgePoint3({(double)nums[0], (double)nums[1], thr[i]});
        }
        return res;
    }
    bool judgePoint3(vector<double> nums) {
        bool res = false;
        vector<double> fir = {(double)nums[0] + nums[1], (double)nums[0] - nums[1], (double)nums[0] * nums[1], (double)nums[0] / nums[1]};
        vector<double> sec = {(double)nums[1] + nums[2], (double)nums[1] - nums[2], (double)nums[1] * nums[2], (double)nums[1] / nums[2]};
        for (int i = 0; i < 3; i++) {
            res = res || judgePoint2({fir[i], (double)nums[2]});
            res = res || judgePoint2({(double)nums[0], sec[i]});
        }
        return res;
    }
    bool judgePoint2(vector<double> nums) {
        if (nums[0] + nums[1] == 24 || nums[0] - nums[1] == 24 || nums[0] * nums[1] == 24 || nums[0] / nums[1] == 24){
            return true;
        }
        else return false;
    }
};

int main() {
    Solution test;
    vector<int> a = {1, 5, 9, 1};
    if ((int)test.judgePoint24(a))
        cout << "corr";
    return 0;
}