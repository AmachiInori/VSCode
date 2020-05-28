#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <hash_map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> sum(nums.size() + 1, 0);
        int max = 0;
        for (int i = 0; i < nums.size(); i++)
            sum[i + 1] += nums[i] + sum[i];
        for (int i = 0; i < nums.size() + 1; i++)
            for (int j = i; j < nums.size() + 1; j++) 
                if ((sum[j] - sum[i]) * 2 == j - i) max = max > j - i? max : (j - i);
        return max;
    }
};