#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> tar, ar;
        for (auto &i : target) tar[i]++;
        for (auto &i : arr) ar[i]++;
        for (auto &i : tar) 
            if (i.second != ar[i.first]) return false;
        for (auto &i : ar) 
            if (i.second != tar[i.first]) return false;
        return true;
    }
};