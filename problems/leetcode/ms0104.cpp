#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> hash;
        int res = 0;
        for (auto &i : s) hash[i]++;
        for (auto i = hash.begin(); i != hash.end(); i++) 
            if (i -> second % 2) res++;
        return !(res > 1);
    }
};