#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        long res = 0;
        sort(staple.begin(), staple.end());
        for (int i = 0; i < drinks.size(); i++) {
            int target = x - drinks[i];
            auto temp = upper_bound(staple.begin(), staple.end(), target);
            res += temp - staple.begin();
            res = res % 1000000007;
        }
        return res;
    }
};