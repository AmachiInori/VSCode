#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNumber(string s) {
        int res(0);
        for (int i(0); i < s.size(); i++) {
            res += pow(2, i) * (s[i] - '0');
        }
        return res;
    }
    bool hasAllCodes(string s, int k) {
        if (s.length() < k) return false;
        vector<int> hash(pow(2, k), 0);
        int size(0);
        for (int i(0); i < s.length() - k + 1; i++) {
            string temp = s.substr(i, k);
            int tempI = getNumber(temp);
            if (hash[tempI] == 0) {
                hash[tempI]++;
                size++;
            }
        }
        if (size < (int)pow(2, k)) return false;
        else return true;
    }
};