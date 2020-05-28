#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        if (nums.size() == 1) return true;
        vector<int> oneIndex;
        bool isOnePresent = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                oneIndex.push_back(i);
                isOnePresent = true;
            }
        }
        if (!isOnePresent) return true;
        int min = INT_MAX;
        for (int i = 0; i < oneIndex.size() - 1; i++){
            if (oneIndex[i + 1] - oneIndex[i] - 1 < min) min = oneIndex[i + 1] - oneIndex[i] - 1;
        }
        if (min >= k) return true;
        else return false;
        
    }
};