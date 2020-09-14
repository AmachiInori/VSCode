#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> memory;
public:
    int _busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        if (target < 0) return INT_MAX;
        if (memory[target] != -1) return memory[target];
        long res = INT_MAX;
        for (int i = 0; i < jump.size(); i++) {
            int endPoint = target / jump[i];
            long temp = min(target % jump[i] * inc + cost[i], (target - endPoint) * inc);
            temp += _busRapidTransit(endPoint, inc, dec, jump, cost);
            int endPointB = target / jump[i] + 1;
            long tempB = min((jump[i] - target % jump[i]) * dec + cost[i], (target - endPoint) * inc);
            tempB += _busRapidTransit(endPointB, inc, dec, jump, cost);
            temp = min(temp, tempB);
            res = min(res, temp);
        }
        res = res % 1000000007;
        memory[target] = res;
        return res;
    }
    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        memory.resize(target + 1, int(-1));
        memory[0] = memory[1] = inc;
        return _busRapidTransit(target, inc, dec, jump, cost);
    }
};

int main() {
    Solution test;
    vector<int> jump = {6};
    vector<int> cost = {10};
    cout << test.busRapidTransit(31, 5, 3, jump, cost);
    return 0;
}