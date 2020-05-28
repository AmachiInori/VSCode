#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getDango(string s, vector<string> &res) {
        istringstream stream(s);
        string temp;
        while (stream >> temp) res.push_back(temp);
    }
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> dango;
        getDango(text, dango);
        vector<string> res;
        for (int i = 0; i < dango.size() - 2; i++) {
            if (dango[i] == first && dango[i + 1] == second) res.push_back(dango[i + 2]);
        }
        return res;
    }
};