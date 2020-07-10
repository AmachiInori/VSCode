#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] <= minPrice)
                minPrice = prices[i];
            else {
                if (res < prices[i] - minPrice)
                    res = prices[i] - minPrice;
            }
        }
        return res;
    }
};