#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Sum = nums.size();
        for (int i = 0; i < nums.size(); i++){
            Sum += i - nums[i];
        }
        return Sum;
    }
};