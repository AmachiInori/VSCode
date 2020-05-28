#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int loca = -1;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] < nums[i + 1]) loca = i;
        
        if (loca != -1) {
            int minLoca = loca + 1;
            for (int i = loca + 1; i < nums.size(); i++){
                if (nums[i] > nums[loca])
                    minLoca = nums[minLoca] < nums[i] ? minLoca : i;
            }
            int temp = nums[minLoca];
            nums[minLoca] = nums[loca];
            nums[loca] = temp;
            std::sort(nums.begin() + loca + 1, nums.end());//高内存消耗
        } else{
            for (int i = 0; i < nums.size() / 2; i++){
                int temp = nums[nums.size() - 1 - i];
                nums[nums.size() - 1 - i] = nums[i];
                nums[i] = temp;
            }
            
        }
        return;
    }
};