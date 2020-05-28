#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZiji(vector<string> &a, vector<string> &b) {
        if (a.size() > b.size()) return false;
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()) {
            if (a[i] < b[j]) return false;
            else if (a[i] == b[j]) {
                i++, j++;
            } else j++;
        }
        if (i < a.size()) return false;
        else return true;
    }
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<int> res;
        for (int i = 0; i < favoriteCompanies.size(); i++)
            sort(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
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