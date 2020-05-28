#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hash;
        int max = 0;
        for (auto &i : nums) hash[i]++;
        for (auto &i : hash) {
            if (hash.find(i.first + 1) != hash.end()) max = max > i.second + hash[i.first + 1] ? max : (i.second + hash[i.first + 1]);
        }
        return max;
    }
};