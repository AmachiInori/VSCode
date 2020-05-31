#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        vector<int> hor(horizontalCuts.size() + 1, 0);
        vector<int> ver(verticalCuts.size() + 1, 0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hoMax(0), veMax(0);
        hor[0] = horizontalCuts[0];
        hor.back() = h - horizontalCuts.back();
        hoMax = max(hor[0], hor.back());
        for (int i = 1; i < horizontalCuts.size(); i++){
            hor[i] = horizontalCuts[i] - horizontalCuts[i - 1];
            hoMax = max(hoMax, hor[i]);
        }

        ver[0] = verticalCuts[0];
        ver.back() = w - verticalCuts.back();
        veMax = max(ver[0], ver.back());
        for (int i = 1; i < verticalCuts.size(); i++){
            ver[i] = verticalCuts[i] - verticalCuts[i - 1];
            veMax = max(veMax, ver[i]);
        }
        
        long res = (long)hoMax * (long)veMax;
        res = res % 1000000007;
        return res;
    }
};