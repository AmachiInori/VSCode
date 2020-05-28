#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> temp = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
public:
    void runner(vector<int>& cost, int target) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (target < 0) return;
        for (int i = 0; i < 9; i++) {
            temp[i]++;
            runner(cost, target - cost[i]);
            temp[i]--;
        }
    }

    string largestNumber(vector<int>& cost, int target) {
        for (int i = 8; i > 0; i--) {
            if (cost[i] == INT_MAX) continue;
            else {
                for (int j = i - 1; j >= 0; j--)
                    if (cost[i] == cost[j]) cost[j] = INT_MAX;
            }
        }
        runner(cost, target);
        if (res.empty()) return "0";
        int maxLoca = 0, maxSum = 0;
        for (int i = 0; i < res.size(); i++) {
            int temp = 0;
            for (int j = 0; j < 9; j++)
                temp += res[i][j];
            res[i][9] = temp;
            if (temp >= maxSum) {
                maxSum = temp;
                maxLoca = i;
            }
        }
        for (int i = 0; i < res.size(); i++){
            if (res[i][9] < maxSum) continue;
            for (int j = 8; j >= 0; j--) {
                if (res[i][j] > res[maxLoca][j]) {
                    maxLoca = i;
                    break;
                }
            }
        }
        
        string result;
        for (int i = 8; i >= 0; i--) {
            for (int j = 0; j < res[maxLoca][i]; j++) result.push_back(i + 49);
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> testV = {70,84,55,63,74,44,27,76,34};
    int target = 29;
    cout << s.largestNumber(testV, 659);
    return 0;
}