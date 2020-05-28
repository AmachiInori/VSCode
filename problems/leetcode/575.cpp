#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> hash;
        int count = 0;
        for (auto &i : candies) {
            if (hash.find(i) == hash.end()) {
                count++;
                hash[i] = 1;
            }
        }
        return count > candies.size() / 2 ? (candies.size() / 2) : count;
    }
};