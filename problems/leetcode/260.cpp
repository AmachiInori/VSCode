#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int preRes = 0, diffPoint = 1;
        for (int i : nums)
            preRes ^= i;
        while (!(diffPoint & preRes)) diffPoint <<= 1;
        int resA = 0, resB = 0;
        for (int i : nums) {
            if (i & diffPoint) resA ^= i;
            else resB ^= i;
        }
        return {resA, resB};
    }
};