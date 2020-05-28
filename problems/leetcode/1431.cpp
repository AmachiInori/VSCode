#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size(), false);
        int max = INT_MIN;
        for (int i = 0; i < candies.size(); i++)
            if (candies[i] > max) max = candies[i];
        for (int i = 0; i < candies.size(); i++)
            if (candies[i] + extraCandies >= max) res[i] = true;
        return res;
    }
};