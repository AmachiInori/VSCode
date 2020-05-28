#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hash;
        vector<int> sum(list2.size(), INT_MAX);
        vector<string> res;
        int min = INT_MAX;
        for (int i = 0; i < list1.size(); i++)
            hash[list1[i]] = i;
        for (int i = 0; i < list2.size(); i++) {
            if (hash.find(list2[i]) != hash.end()) sum[i] = i + hash[list2[i]];
            min = std::min(min, sum[i]);
        }
        for (int i = 0; i < list2.size(); i++) 
            if (sum[i] == min) res.push_back(list2[i]);
        return res;
    }
};