#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<char, vector<int>> hash;
public:
    int runner(string s, int left, int right) {
        if (left < 0 || right > s.length()) return 0;
        for (auto &it : hash) {
            if ((it.second[right] - it.second[left]) % 2) {
                int tempL, tempR;
                for (tempL = left + 1; tempL < right; tempL++)
                    if (s[tempL] == it.first) break;
                for (tempR = right - 1; tempR > left; tempR--)
                    if (s[tempR] == it.first) break;
                return max(runner(s, left, tempR), runner(s, tempL, right));
                break;
            }
        }
        return right - left + 1;
    }

    int findTheLongestSubstring(string s) {
        hash['a'] = vector(s.length() + 1, 0);
        hash['e'] = vector(s.length() + 1, 0);
        hash['i'] = vector(s.length() + 1, 0);
        hash['o'] = vector(s.length() + 1, 0);
        hash['u'] = vector(s.length() + 1, 0);
        for (int i = 0; i < s.length(); i++) {
            for (auto &it : hash) {
                if (it.first == s[i]) it.second[i + 1] = (i == 0) ? 1 : (it.second[i] + 1);
                else it.second[i + 1] = (i == 0) ? 0 : it.second[i];
            }
        }
        return runner(s, 0, s.length());
    }
};