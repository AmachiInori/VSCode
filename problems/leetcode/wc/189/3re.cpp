#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZiji(vector<string> &a, vector<string> &b) {
        unordered_map<string, int> hashB;
        for (auto &i : b) hashB[i] = 1;
        for (auto &i : a) {
            if (hashB.find(i) == hashB.end()) return false;
        }
        return true;
    }
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<int> res;
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            bool istrue = true;
            for (int j = 0; j < favoriteCompanies.size(); j++) {
                if (i != j) {
                    if (isZiji(favoriteCompanies[i], favoriteCompanies[j])) {
                        istrue = false;
                        break;
                    }
                }
            }
            if (istrue) res.push_back(i);
        }
        return res;
    }
};