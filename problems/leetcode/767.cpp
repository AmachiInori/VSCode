#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> hash;
        char most;
        int max(0);
        for (auto &ch : S) {
            hash[ch]++;
            if (hash[ch] > max) most = ch, max = hash[ch];
        }
        if (max > (S.length() + 1) / 2) return "";
        string resF((S.length() + 1) / 2, ' '), resS(S.length() / 2, ' ');
        for (int i = 0; i < resF.length(); i++) {
            if (max == 0) {
                for (auto &i : hash) {
                    if (i.second > max) {
                        max = i.second;
                        most = i.first;
                    }
                }
            }
            if (max != 0) {
                resF[i] = most;
                max--;
                hash[most]--;
            }
        }
        for (int i = 0; i < resS.length(); i++) {
            if (max == 0) {
                for (auto &i : hash) {
                    if (i.second > max) {
                        max = i.second;
                        most = i.first;
                    }
                }
            }
            if (max != 0) {
                resS[i] = most;
                max--;
                hash[most]--;
            }
        }
        ostringstream str;
        for (int i = 0; i < resF.size(); i++) {
            str << resF[i];
            str << resS[i];
        }
        if (resF.size() > resS.size()) str << resF.back();
        return str.str();
    }
};