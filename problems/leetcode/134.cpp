#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using std::vector;
using std::stack;
using std::string;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startStation = 0, nowStation = 0;
        int gasSum = 0, costSum = 0;
        for (int i = 0; i < gas.size(); i++){
            gasSum += gas[i];
            costSum += cost[i];
        }
        if (costSum > gasSum) return -1;
        gasSum = 0, costSum = 0;
        while (startStation != gas.size()){
            gasSum += gas[nowStation];
            costSum += cost[nowStation];
            nowStation++;
            if (nowStation == gas.size()) nowStation = 0;
            if (nowStation == startStation) return startStation;
            if (gasSum < costSum) {
                startStation = nowStation;
                gasSum = 0, costSum = 0;
            }
        }
        return 0;
    }
};