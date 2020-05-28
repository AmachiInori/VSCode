#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
    int const mod = 1000000007;
public:
    vector<vector<int>> zongxiangguan;
    vector<vector<int>> hengxiangguan;
    vector<vector<int>> AppleLoca;
    vector<int> used;
    int res = 0;

    void runner(int nowNumber, int target){
        if (nowNumber == target) {
            res++;
            res %= mod;
            return;
        }

        for (int i = 0; i < AppleLoca.size(); i++){
            if(!used[i]) {
                used[i] = 1;
                for (int j = 0; j < zongxiangguan[i].size(); j++){
                    used[zongxiangguan[i][j]] = 1;
                }
                runner(nowNumber + 1, target);
                for (int j = 0; j < zongxiangguan[i].size(); j++){
                    used[zongxiangguan[i][j]] = 0;
                }

                for (int j = 0; j < hengxiangguan[i].size(); j++){
                    used[hengxiangguan[i][j]] = 1;
                }
                runner(nowNumber + 1, target);
                for (int j = 0; j < hengxiangguan[i].size(); j++){
                    used[hengxiangguan[i][j]] = 0;
                }
                used[i] = 0;
            }
        }
        return;
    }
    int ways(vector<string>& pizza, int k) {
        for (int i = 0; i < pizza.size(); i++){
            for (int j = 0; j < pizza[0].size(); j++){
                if (pizza[i][j] == 'A') AppleLoca.push_back({i,j});
            }
        }
        zongxiangguan.resize(AppleLoca.size());
        hengxiangguan.resize(AppleLoca.size());
        used = vector(AppleLoca.size(), 0);
        for (int i = 0; i < AppleLoca[i].size() - 1; i++){
            for (int j = 1; j < AppleLoca[i].size(); j++){
                if (AppleLoca[i][0] == AppleLoca[j][0]) hengxiangguan[i].push_back(j);
                if (AppleLoca[i][1] == AppleLoca[j][1]) zongxiangguan[i].push_back(j);
            }
        }
        runner(0, k);
        return res;
    }
};