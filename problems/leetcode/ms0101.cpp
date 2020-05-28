#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        unordered_map<char, int> hash;
        for (auto &i : astr) {
            if (hash.find(i) != hash.end()) return false;
            else hash[i] = 1;
        }
        return true;
    }
};