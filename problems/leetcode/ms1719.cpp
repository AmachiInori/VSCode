#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        long sum = 0, doubleSum = 0;
        long lSum = 3, lDoubleSum = 5;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i], doubleSum += nums[i] * nums[i];
            lSum += i + 3; lDoubleSum += (i + 3) * (i + 3);
        }
        sum = lSum - sum, doubleSum = lDoubleSum - doubleSum;
        return {((int)sum + (int)sqrt(2 * doubleSum - sum * sum)) / 2, ((int)sum - (int)sqrt(2 * doubleSum - sum * sum)) / 2};
    }
};