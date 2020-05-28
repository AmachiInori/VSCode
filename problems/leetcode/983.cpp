#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> temp;
    vector<int> transDays;
    int min(int a, int b, int c) {
        int temp = a < b ? a : b;
        temp = temp < c ? temp : c;
        return temp;
    }
    int dp(int n, vector<int>& costs) {
        if(n > 365) return 0;
        if(temp[n] != -1) return temp[n];
        int res;
        if(!transDays[n]) res = dp(n + 1, costs);
        else res = min(dp(n + 30, costs) + costs[2], dp(n + 7, costs) + costs[1], dp(n + 1, costs) + costs[0]);
        temp[n] = res;
        return res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        temp = vector(366, -1);
        transDays = vector(366, 0);
        for (int i = 0; i < days.size(); i++)
            transDays[days[i]] = 1;
        return dp(1, costs);
    }
};