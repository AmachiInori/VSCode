#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
//nums.size()是无符号数，如果是1的时候，减去3会变成超级大数。
class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size();){
            if (i <= (int)nums.size() - 4) {
                if (nums[i] + nums[i + 2] >= nums[i + 1] + nums[i + 3]) {
                    res += nums[i];
                    i += 2;
                }else {
                    res += nums[i + 1];
                    i += 3;
                }
            }
            else if (i == (int)nums.size() - 3) {
                if (nums[i] + nums[i + 2] > nums[i + 1]) {
                    res += nums[i] + nums[i + 2];
                }else {
                    res += nums[i + 1];
                }
                break;
            }else if (i == (int)nums.size() - 2) {
                res += nums[i] > nums[i + 1] ? nums[i] : nums[i + 1];
                break;
            }else if (i == (int)nums.size() - 1) {
                res += nums[i];
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> test = {0};
    s.rob(test);
    return 0;
}