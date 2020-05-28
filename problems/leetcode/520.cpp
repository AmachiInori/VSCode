#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;
        for (auto &it : word) {
            if (it >= 'A' && it <= 'Z') upper++;
        }
        if (!upper || upper == word.length() || (upper == 1 && (word.front() >= 'A' && word.front() <= 'Z'))) return true;
        else return false;
    }
};