#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> index = vector(nums.size(), -1);
        index[0] = 0;
        for (int i = 1; i < nums.size(); i++){
            int min = INT_MAX;
            for (int j = i - 1; j >= 0; j--){
                if (nums[j] + j >= i) {
                    if (index[j] < min) min = index[j] + 1;
                }
            }
            index[i] = min;
        }
        return index[nums.size() - 1];
    }
};//此算法忽略了题目假设，因此慢。