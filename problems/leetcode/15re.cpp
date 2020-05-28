/*
 * @Author: your name
 * @Date: 2020-04-25 17:43:46
 * @LastEditTime: 2020-04-25 18:24:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\15re.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int pointL = i + 1, pointR = nums.size() - 1;
            while (pointL < pointR) {
                if (nums[pointL] + nums[pointR] > -nums[i]) {
                    int temp = nums[pointR];
                    while (temp == nums[pointR] && pointL < pointR) pointR--;
                }else if (nums[pointL] + nums[pointR] < -nums[i]) {
                    int temp = nums[pointL];
                    while (temp == nums[pointL] && pointL < pointR) pointL++;
                }else if (nums[pointL] + nums[pointR] == -nums[i]) {
                    res.push_back({nums[pointL], nums[i], nums[pointR]});
                    int tempL = nums[pointL];
                    int tempR = nums[pointR];
                    while (tempL == nums[pointL] && pointL < pointR) pointL++;
                    while (tempR == nums[pointR] && pointL < pointR) pointR--;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> str = {0, 0, 0, 0};
    s.threeSum(str);
    return 0;
}