#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> hash;
        for (auto &ch : s) hash[ch]++;
        for (int i(0); i < s.length(); i++) {
            if (hash[s[i]] == 1) return s[i];
        }
        return ' ';
    }
};